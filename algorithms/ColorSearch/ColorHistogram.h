#ifndef COLORHISTOGRAM_H
#define COLORHISTOGRAM_H

#include <QVector>
#include <QImage>



/**
 * @brief Color Histogram feature class.
 */
class ColorHistogram
{
public:
    ColorHistogram(int nbins=4);
    virtual ~ColorHistogram();

    QString toString() const;

    int nBins() const;
    void setNBins(int n);

    bool compute(const QImage& img, QRect r=QRect(0,0,0,0));
    void clear();
    const QVector<double>& histogram() const;

    double diff(const ColorHistogram& ch) const;

    bool store(const QString& fname) const;
    bool load(const QString& fname);

    friend QDataStream& operator<<(QDataStream& stream, const ColorHistogram& ch);
    friend QDataStream& operator>>(QDataStream& stream, ColorHistogram& ch);

private:
    QVector<double> mHistogram; ///< The histogram.
};





/**
 * @brief Operator to write the histogram to a data stream.
 * @param stream The output stream.
 * @param ch The histogram to write.
 * @return The stream.
 */
inline QDataStream& operator<<(QDataStream& stream, const ColorHistogram& ch)
{
    stream << ch.mHistogram;
    return stream;
}

/**
 * @brief Operator to read the histogram from a data stream.
 * @param stream The input stream.
 * @param ch The histogram to read to.
 * @return The stream.
 */
inline QDataStream& operator>>(QDataStream& stream, ColorHistogram& ch)
{
    stream >> ch.mHistogram;
    return stream;
}

#endif
