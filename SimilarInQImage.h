#ifndef SIMILARINQIMAGE_H
#define SIMILARINQIMAGE_H

#include <QObject>
#include <QImage>

class SimilarInQImage : public QObject
{
    Q_OBJECT
public:
    explicit SimilarInQImage(QObject *parent = nullptr);

    ~SimilarInQImage();

    QImage *getImgContainer() const;
    void setImgContainer(QImage *);

    double isIn(const QImage &);
    long long onlySimilarity(const QImage &, int , int );

    QPoint whereIsIt(QImage &);

    QPoint getLastPoint() const;
    void setLastPoint(const QPoint &value);

signals:

public slots:

private:
    QImage* imgContainer;
    QPoint lastPoint;
};

#endif // SIMILARINQIMAGE_H
