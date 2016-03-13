#ifndef COLORSEARCH_H
#define COLORSEARCH_H

#include <QPluginLoader>

#include "SearchAlgorithm.h"
#include "SearchQuery.h"

#include "ColorHistogram.h"





/**
 * @brief Color based #SearchAlgorithm .
 *
 * @note Implementation requires each tack id to be unique within medium.
 */
class ColorSearch : public SearchAlgorithm
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID Algorithm_iid FILE "ColorSearch.json")
    Q_INTERFACES(Algorithm)

public:
    ColorSearch();
    ~ColorSearch();
    
    // algorithm interface
    bool setInputs(const QList<DataPacket*>& inputDataList) override;
    bool setParameters(const QJsonObject& parameters) override;
    QList<DataPacket*> run() override;

private: 
    // general methods
    bool isUseableQuery(const SearchQuery& q) const;
    const Dataset* getDataset(const QString& path);
    void fillSearchDb();
    SearchResultElement processDbEntry(int idx);

    // specific methods
    void searchObjectToFeature(const SearchObject& o, QVector<ColorHistogram>& feat_vec);
    ColorHistogram computeFeature(const Dataset& ds, const QString& fname, const QRect& r) const;
    void computeTrackFeatures(const Dataset& ds, int dataset_index, int medium_index,
                              const QString& annotation_id, QVector<ColorHistogram>& feat_vec);

    // basic members
    SearchQuery mQuery;                                 ///< Query for current/next #run().
    QHash<QString, std::shared_ptr<Dataset>> mDatasets; ///< The relevant datasets.

    // algorithm parameters
    int mNumBins;                           ///< Number of bins per channel to use for search.

    // features
    QVector<ColorHistogram> mQueryFeatures; ///< Features corresponding to the query.
    QList<SearchResultElement> mSearchDb;   ///< Index/DB of all objects to compare to.
};

#endif
