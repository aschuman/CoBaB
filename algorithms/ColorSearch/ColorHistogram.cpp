#include "ColorHistogram.h"

#include <cmath>
#include <limits>
#include <iostream>

#include <QFile>

using namespace std;





/**
 * @brief Default constructor.
 * @param nbins Number of bins for each color channel.
 */
ColorHistogram::ColorHistogram(int nbins)
{
    setNBins(nbins);
}



/**
 * @brief Destructor.
 */
ColorHistogram::~ColorHistogram()
{
}



/**
 * @brief Get a string representation of the histogram.
 * @return The string.
 */
QString ColorHistogram::toString() const
{
    QString s;
    for (double d : mHistogram) s.append(" "+QString::number(d, 'f', 1));
    return s.trimmed();
}



/**
 * @brief Get the number of bins in each color channel.
 * @return The number of bins in each color channel.
 */
int ColorHistogram::nBins() const
{
    return pow(mHistogram.size(), 1/3.);
}



/**
 * @brief Set the number of bins in each color channel (clears existing histogram).
 * @param n The new number of bins.
 */
void ColorHistogram::setNBins(int n)
{
    n = max(0, min(256, n));
    mHistogram = QVector<double>(n*n*n, 0.);
}



/**
 * @brief Compute the histogram given an image.
 * @param img The image.
 * @return True, if successful.
 */
bool ColorHistogram::compute(const QImage &img, QRect r)
{
    clear();
    int color, cr, cg, cb;
    int n = nBins();
    int binsize = ceil(256. / n);

    int cmax = max(r.x()+r.width(), 0);
    int rmax = max(r.y()+r.height(), 0);
    if (cmax == 0) cmax = img.width();
    if (rmax == 0) rmax = img.height();
    for(int col = max(r.x(), 0); col < min(cmax, img.width()); ++col)
    {
        for(int row = max(r.y(), 0); row < min(rmax, img.height()); ++row)
        {
            color = img.pixel(col,row);
            cr = qRed(color) / binsize;
            cg = qGreen(color) / binsize;
            cb = qBlue(color) / binsize;
            mHistogram[cr*n*n + cg*n + cb] += 1;
        }
    }

    double sum = (min(cmax, img.width())-max(r.x(), 0)) * (min(rmax, img.height())-max(r.y(), 0));
    for(int ii = 0; ii < mHistogram.length(); ++ii) mHistogram[ii] /= sum;

    return true;
}



/**
 * @brief Clear the current histogram (setting all bins to 0).
 */
void ColorHistogram::clear()
{
    mHistogram = QVector<double>(mHistogram.size(), 0.);
}



/**
 * @brief Get access to the histogram.
 * @return The histogram.
 */
const QVector<double>& ColorHistogram::histogram() const
{
    return mHistogram;
}



/**
 * @brief Compute the distance to another histogram.
 * @param ch The other histogram (of same length).
 * @return The distance between this and the other histogram.
 */
double ColorHistogram::diff(const ColorHistogram& ch) const
{
    if (ch.histogram().length() != mHistogram.length()) return std::numeric_limits<double>::max();

    double dist = 0;

    // euclidean distance (ish)
    for (int ii = 0; ii < mHistogram.size(); ++ii)
    {
        dist += fabs(mHistogram[ii]-ch.mHistogram[ii]);
    }

    return dist;
}



/**
 * @brief Store the histogram to a binary file.
 * @param fname The name of the file to write.
 * @return True, if successful.
 */
bool ColorHistogram::store(const QString &fname) const
{
    QFile file(fname);
    bool b = file.open(QIODevice::WriteOnly);
    if (!b) return false;
    QDataStream out(&file);
    out << mHistogram;
    file.close();
    return true;
}



/**
 * @brief Load the histogram from binary file.
 * @param fname The file to read from.
 */
bool ColorHistogram::load(const QString &fname)
{
    QFile file(fname);
    file.open(QIODevice::ReadOnly);
    if (!file.isOpen()) return false;
    QDataStream in(&file);
    in >> mHistogram;
    file.close();
    return true;
}
