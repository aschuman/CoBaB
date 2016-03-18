#include "ColorSearch.h"

#include <QTime>
#include <QCoreApplication>

#include <QDebug>
#include <iostream>
using namespace std;





////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Convert a #SearchObject to a string.
 * @param o The #SearchObject .
 * @return The string representation.
 */
QString searchObjectToString(const SearchObject& o)
{
    QString s;
    if (o.getType() == SearchObject::ANNOTATION)    s = "ANN ";
    else if (o.getType() == SearchObject::MEDIUM)   s = "MED ";
    else if (o.getType() == SearchObject::ROI)      s = "ROI ";
    else                                            s = "??? ";
    s.append(o.getMedium()+" ");
    s.append(QString::number(o.getMediumIndex())+" ");
//    s.append(o.getSourceDataset()+" ");
    if (o.getType() == SearchObject::ANNOTATION)
    {
        QRect* r = dynamic_cast<QRect*>(o.getAnnotation());
        if (r) s.append(QString::number(r->x())+" "+
                        QString::number(r->y())+" "+
                        QString::number(r->width())+" "+
                        QString::number(r->height()));
        else if (!o.getAnnotation()) s.append(" NULL_ANNOTATION");
        else                         s.append("NONRECT_ANNOTATION");
    }
    else if (o.getType() == SearchObject::ROI) s.append(QString::number(o.getROI().x())+" "+
                                                        QString::number(o.getROI().y())+" "+
                                                        QString::number(o.getROI().width())+" "+
                                                        QString::number(o.getROI().height()));
    else {}
    return s;
}



/**
 * @brief Find the position of a #Medium in a dataset.
 * @param ds The dataset to search in.
 * @param fname The absolute path of the #Medium.
 * @return The index within the dataset or -1, if not found.
 */
int findMediumInDataset(const Dataset& ds, const QString& fname)
{
    QFileInfo minf(fname);
    QList<Medium*> l = ds.getMediaList();
    for (int ii=0; ii<l.size(); ++ii)
    {
        if (QFileInfo(l[ii]->getPath()) == minf) return ii;
    }
    return -1;
}



/**
 * @brief Get all annotations for a given frame from an annotation list.
 * @param annlist The annotation list.
 * @param frame The frame to look for.
 * @return The list of found annotations.
 */
QList<Annotation*> getAnnotationsForFrame(QList<QPair<int, Annotation*>> annlist, int frame)
{
    QList<Annotation*> result;
    for (QPair<int, Annotation*> a : annlist)
    {
        if (a.first == frame && a.second != nullptr) result.append(a.second);
    }
    return result;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// ColorSearch
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Default constructor.
 */
ColorSearch::ColorSearch()
    : mNumBins(4)
{
    mId = "Search_ColorHist";
    mName = "Color Search";
    mDescription = "Search method that focuses on color information.";
    mCancel = false;
    mSupportProgressInfo = true;
}



/**
 * @brief Destructor.
 */
ColorSearch::~ColorSearch()
{}



////////////////////////////////////////////////////////////////////////////////////////////////////
// Algorithm Interface
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Set a set of inputs for the algorithm.
 * @param inputDataList The inputs (requires only a SearchQuery).
 * @return True, if the algorithm is runnable.
 */
bool ColorSearch::setInputs(const QList<DataPacket*>& inputDataList)
{
    if (inputDataList.length() < 1) return false;
    qDebug() << "number of ColorSearch inputs: " << inputDataList.size();
    bool valid_input = false;
    mFeedback.setFeedbackList(QList<QPair<SearchObject, int>>()); // clear feedback

    for (auto packet : inputDataList)
    {
        SearchQuery* q = dynamic_cast<SearchQuery*>(packet);
        if (q)
        {
            if (!isUseableQuery(*q)) return false;
            mQuery = *q;
            valid_input = true;
            continue;
        }

        SearchFeedback* fb = dynamic_cast<SearchFeedback*>(packet);
        if (fb)
        {
            qDebug() << "found feedback list for ColorSearch: " << fb->getFeedbackList().size();
            mFeedback = *fb;
            continue;
        }
    }
    return valid_input;
}



/**
 * @brief Set the algorithm's parameters from a json object.
 * @param parameters The parameters.
 * @return True, if the parameter input was accepted.
 * @note If the input is partially invalid, no value will be set.
 */
bool ColorSearch::setParameters(const QJsonObject& parameters)
{
    bool b = SearchAlgorithm::setParameters(parameters);
    if (!b) return b;

    int bins = mNumBins;

    if (parameters.contains("Number of Bins"))
    {
        bins = parameters.value("Number of Bins").toInt();
        if (bins < 1 || bins > 32) return false;
    }

    mNumBins = bins;

    return true;
}



/**
 * @brief Run the search on the current query.
 * @return List of results (or empty list, if query invalid).
 */
QList<DataPacket*> ColorSearch::run()
{
    // check input again
    if (!isUseableQuery(mQuery))
    {
        qWarning() << "tried to start ColorSearch with invalid query.";
        return QList<DataPacket*>();
    }

    // compute features for query
    mQueryFeatures.clear();
    searchObjectToFeature(mQuery.getSearchObject(), mQueryFeatures);
    qDebug() << "ColorSearch feedback size during run(): " << mFeedback.getFeedbackList().size();
    for (auto fb : mFeedback.getFeedbackList())
    {
        qDebug() << fb.second;
        if (fb.second == 1)
        {
            searchObjectToFeature(fb.first, mQueryFeatures);
            qWarning() << "adding positive feedback to query";
        }
    }
    if (mQueryFeatures.size() < 1)
    {
        qWarning() << "no query features could be computed.";
        return QList<DataPacket*>();
    }

    // fill the search database for the current query
    fillSearchDb();
    if (mSearchDb.size() < 1)
    {
        qWarning() << "search database is empty.";
        return QList<DataPacket*>();
    }

    // run algorithm
    mCancel = false;
    SearchResult* result = new SearchResult;
    QTime t_start;
    t_start.start();
    int last_progress = 0;
    int last_partial_result = 0;

    for (int ii = 0; ii < mSearchDb.size(); ++ii)
    {
        // next algorithm step
        SearchResultElement e = processDbEntry(ii);
        result->addResultElement(e);
        int ms = t_start.elapsed();

        // debugging infos
//        qDebug() << "db entry: "  + searchObjectToString(e.getSearchObject())
//                 + "   score: "   + QString::number(e.getScore(), 'f', 4)
//                 + "   ms(avg): " + QString::number(float(ms)/ii, 'f', 2);

        // send update signals
        if (ms - last_progress > 1000)
        {
            emit madeProgress(double(ii)/mSearchDb.size());
            last_progress = ms;
        }
        if (ms - last_partial_result > 1000)
        {
            emit producedIntermediateResults(*result);
            last_partial_result = ms;
        }

        // check for cancel
        QCoreApplication::processEvents();
        if (mCancel)
        {
            qDebug() << "execution interrupted.";
            break;
        }
    }

    // wrap up
    QList<DataPacket*> list;
    list.append((DataPacket*)result);
    return list;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// General Methods
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Check, if a given query is supported.
 * @param q The query to check.
 * @return True, if the query can be used.
 */
bool ColorSearch::isUseableQuery(const SearchQuery &q) const
{
    Dataset dataset(q.getSearchObject().getSourceDataset());

    switch (dataset.getType())
    {
    case Dataset::PHOTO:
        switch (q.getSearchObject().getType())
        {
        case SearchObject::MEDIUM:
            return true;
            break;
        case SearchObject::ANNOTATION:
        {
            QRect*r = dynamic_cast<QRect*>(q.getSearchObject().getAnnotation());
            if (r) return true;
            else   return false;
            break;
        }
        case SearchObject::ROI:
            return true;
            break;
        default:
            return false;
            break;
        }
        break;
    case Dataset::SINGLE_FRAME_VIDEO:
        switch (q.getSearchObject().getType())
        {
        case SearchObject::ANNOTATION:
        {
            QRect*r = dynamic_cast<QRect*>(q.getSearchObject().getAnnotation());
            if (r) return true;
            else   return false;
            break;
        }
        default:
            return false;
            break;
        }
        break;
    default:
        return false;
        break;
    }

    return false;
}


/**
 * @brief Get a dataset from cache.
 * @param path The path of the dataset.
 * @return Pointer to the dataset.
 */
Dataset const* ColorSearch::getDataset(const QString& path_)
{
    QString path = QDir(path_).canonicalPath();
    if (!mDatasets.contains(path)) mDatasets[path] = make_shared<Dataset>(path);
    return mDatasets[path].get();
}



/**
 * @brief Fill the search database according to query.
 */
void ColorSearch::fillSearchDb()
{
    mSearchDb.clear();
    SearchObject qobj = mQuery.getSearchObject();

    for (const QString& ds_path : mQuery.getDatasets())
    {
        const Dataset* dataset = getDataset(ds_path);

        // generate annotation SearchObjects for video and image datasets.
        if (qobj.getType() == SearchObject::ANNOTATION && qobj.getAnnotation())
        {
            QList<Medium*> media = dataset->getMediaList();
            for (Medium* m : media)
            {
                QVector<QString> known_ids;
                QList<QPair<int, Annotation*>> annlist = m->getAnnotationList();
                for (auto ann : annlist)
                {
                    if (!ann.second) continue;
                    if (ann.second->getType() != qobj.getAnnotation()->getType()) continue;
                    if (known_ids.contains(ann.second->getId())) continue;
                    known_ids.append(ann.second->getId());
                    SearchObject o;
                    o.setSourceDataset(dataset->getPath());
                    o.setMedium(m->getPath());
                    o.setMediumIndex(ann.first);
                    o.setAnnotation(ann.second->copy()); //NOTE: will be part of search output
                    o.setType(SearchObject::ANNOTATION);
                    SearchResultElement e;
                    e.setSearchObject(o);
                    mSearchDb.append(e);
                }
            }
        }

        // for MEDIUM and ROI image queries generate MEDIUM SearchObjects as responses
        if (dataset->getType() == Dataset::PHOTO &&
            (qobj.getType() == SearchObject::MEDIUM || qobj.getType() == SearchObject::ROI))
        {
            QList<Medium*> media = dataset->getMediaList();
            for (Medium* m : media)
            {
                SearchObject o;
                o.setSourceDataset(dataset->getPath());
                o.setMedium(m->getPath());
                o.setType(SearchObject::MEDIUM);
                SearchResultElement e;
                e.setSearchObject(o);
                mSearchDb.append(e);
            }
        }
    }
}



/**
 * @brief Process an entry in the search database.
 * @param idx The index of the entry to process.
 * @return The result.
 */
SearchResultElement ColorSearch::processDbEntry(int idx)
{
    QVector<ColorHistogram> features;
    searchObjectToFeature(mSearchDb[idx].getSearchObject(), features);

    // compare query features to db features
    double score = numeric_limits<double>::max();
    for (const ColorHistogram& qf : mQueryFeatures)
    {
        for (const ColorHistogram& dbf : features)
        {
            double dist = qf.diff(dbf);
            if (abs(dist) < score) score = abs(dist);
        }
    }

    mSearchDb[idx].setScore(score);
    return mSearchDb[idx];
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// Specific Methods
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Compute all features for a #SearchObject and append them to output.
 * @param o The #SearchObject .
 * @param feat_vec The feature vector to append to.
 */
void ColorSearch::searchObjectToFeature(const SearchObject& o, QVector<ColorHistogram>& feat_vec)
{
    const Dataset* dataset = getDataset(o.getSourceDataset());

    if (dataset->getType() == Dataset::PHOTO)
    {
        // determine region
        QRect region;
        if      (o.getType() == SearchObject::ROI)          region = o.getROI();
        else if (o.getType() == SearchObject::MEDIUM)       region = QRect(0,0,0,0);
        else if (o.getType() == SearchObject::ANNOTATION)
        {
            QRect* r = dynamic_cast<QRect*>(o.getAnnotation());
            if (r) region = *r;
            else return;
        }
        else return;

        // compute feature (single image)
        feat_vec.append(computeFeature(*dataset, o.getMedium(), region));
    }
    else if (dataset->getType() == Dataset::SINGLE_FRAME_VIDEO)
    {
        if (o.getType() == SearchObject::ANNOTATION)
        {
            // compute features (track)
            int datasetindex = findMediumInDataset(*dataset, o.getMedium());
            computeTrackFeatures(*dataset, datasetindex, o.getMediumIndex(),
                                 o.getAnnotation()->getId(), feat_vec);
        }
    }
}



/**
 * @brief Compute a feature for a region in an image.
 * @param dataset The dataset the image is on (for cache location).
 * @param fname Absolute filename for the image to compute the feature on.
 * @param region The region. QRect(0,0,0,0) means whole image.
 * @return The computed feature.
 */
ColorHistogram ColorSearch::computeFeature(const Dataset& dataset, const QString& fname,
                                           const QRect& region) const
{
    // piece together unique cache file name
    QString cache_dir = dataset.getPath() + QDir::separator() + "_featurecache";
    QString rel_fname = QDir(dataset.getPath()).relativeFilePath(fname);
    if (rel_fname.startsWith(".."))
    {
        qWarning() << "ohoh, image file from outside dataset. "
                      "something has gone terribly, terribly wrong.";
        return ColorHistogram();
    }
    QString cache_file = cache_dir + QDir::separator() + rel_fname +
                         "_" + QString::number(mNumBins) +
                         "_" + QString::number(region.x()) +
                         "_" + QString::number(region.y()) +
                         "_" + QString::number(region.width()) +
                         "_" + QString::number(region.height()) +
                         ".colorhist";

    // read feature from cache
    ColorHistogram f;
    if (QFile(cache_file).exists())
    {
        bool b = f.load(cache_file);
        if (b) return f;
    }

    // compute feature
    QImage img;
    bool b = img.load(fname);
    if (!b)
    {
        qWarning() << "image could not be loaded for feature computation.";
        return ColorHistogram();
    }
    f.setNBins(mNumBins);
    f.compute(img, region);

    // write feature to cache
    QDir parent = QFileInfo(cache_file).dir();
    if (!parent.exists()) parent.mkpath(parent.path());
    f.store(cache_file);

    return f;
}



/**
 * @brief Compute a set of features for a track and append them to output.
 * @param dataset The dataset.
 * @param dataset_index The index of the video within the dataset.
 * @param medium_index The index of a frame within the video.
 * @param annotation_id The track annotation id.
 * @param feat_vec The feature vector to which features will be appended.
 */
void ColorSearch::computeTrackFeatures(const Dataset& dataset,
                                       int dataset_index,
                                       int medium_index,
                                       const QString& annotation_id,
                                       QVector<ColorHistogram>& feat_vec)
{
    if (dataset.getType() != Dataset::SINGLE_FRAME_VIDEO || dataset_index < 0 ||
        medium_index < 0) return;

    QList<Medium*> media_list = dataset.getMediaList();
    if (dataset_index >= media_list.size()) return;
    SingleFrameVideo* m = dynamic_cast<SingleFrameVideo*>(media_list[dataset_index]);
    if (!m) return;
    QList<QString> framelist = m->getFrameList();
    if (medium_index >= framelist.size()) return;
    QList<QPair<int, Annotation*>> annlist = m->getAnnotationList();

    for (auto ann : annlist)
    {
        if (!ann.second) continue;
        if (ann.second->getId() != annotation_id) continue;
        QRect* r = dynamic_cast<QRect*>(ann.second);
        if (!r) continue;
        QString fname = QFileInfo(m->getPath() + QDir::separator() + framelist[ann.first]).
                              absoluteFilePath();
        feat_vec.append(computeFeature(dataset, fname, *r));
    }
}
