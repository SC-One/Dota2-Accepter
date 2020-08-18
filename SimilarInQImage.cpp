#include "SimilarInQImage.h"
#include<QGuiApplication>
#include<QScreen>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include<QDebug>

SimilarInQImage::SimilarInQImage(QObject *parent)
    : QObject(parent)
    ,imgContainer{new QImage(QString(":/1920Accept.png"))}
{ 
    auto temp=QGuiApplication::primaryScreen()->geometry();
    if(temp.width()<1920)
    {
        *imgContainer=imgContainer->scaled(temp.width()*imgContainer->width()/1920,

                                           temp.height()*imgContainer->height()/1080,
                                           Qt::IgnoreAspectRatio,
                                           Qt::SmoothTransformation);
    }
}

SimilarInQImage::~SimilarInQImage()
{
    delete imgContainer;
    imgContainer=nullptr;
}

QImage *SimilarInQImage::getImgContainer() const
{
    return imgContainer;
}

void SimilarInQImage::setImgContainer(QImage *value)
{
    imgContainer = value;
}

double SimilarInQImage::isIn(const QImage &inputImage)
{
    long long maxSimilarity{0};

    int inputWidth{inputImage.width()};
    int inputHeight{inputImage.height()};

    int imgWidth{imgContainer->width()};
    int imgHeight{imgContainer->height()};

    if(inputWidth>=imgWidth
            && inputHeight>=imgHeight)
    {
        int tempW{inputWidth-imgWidth};
        int tempH{inputHeight-imgHeight};

        for(int i=0;i<=tempW;i++)
        {
            for(int j=0;j<=tempH;j++)
            {
                long long tempMaxSimilarity{onlySimilarity(inputImage,i,j)};

                if(tempMaxSimilarity>maxSimilarity)
                    maxSimilarity=tempMaxSimilarity;
            }
        }

        return maxSimilarity / static_cast<double>(imgWidth*imgHeight)*100 ;
    }
    else
        return 0;

}

long long SimilarInQImage::onlySimilarity(const QImage &inputImage, int i, int j)
{
    long long similarity{0};

    int row{imgContainer->width()+i};
    int column{imgContainer->height()+j};

    int tempJ=j;
    for(int myRow{0};i<row;i++,myRow++,j=tempJ)
    {
        for(int myCol{0};j<column;j++,myCol++)
        {
            similarity+=(inputImage.pixel(i,j)==imgContainer->pixel(myRow,myCol));
        }
    }
    return similarity;
}

QPoint SimilarInQImage::whereIsIt(QImage &inputImage)
{
    cv::Mat bigImage(inputImage.height(), inputImage.width(), CV_8UC3, (uchar*)inputImage.bits(),inputImage.bytesPerLine());
    cv::Mat smallImage(imgContainer->height(), imgContainer->width(), CV_8UC3, (uchar*)imgContainer->bits(), imgContainer->bytesPerLine());
    cv::Mat resultMatrix;

    int result_cols =  bigImage.cols - smallImage.cols + 1;
    int result_rows = bigImage.rows - smallImage.rows + 1;

    resultMatrix.create( result_rows, result_cols, CV_32FC1 );

    //  TM_SQDIFF        = 0
    //  TM_SQDIFF_NORMED = 1
    //  TM_CCORR         = 2
    //  TM_CCORR_NORMED  = 3
    //  TM_CCOEFF        = 4
    //  TM_CCOEFF_NORMED = 5

    matchTemplate( bigImage, smallImage, resultMatrix, cv::TM_CCOEFF_NORMED);


    double minVal, maxVal;
    cv::Point minLoc,  maxLoc, matchLoc;

    cv::minMaxLoc( resultMatrix, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat() );
    matchLoc = maxLoc;

    qDebug()<<maxVal;

    if(/*minVal<5.1e+7*/ maxVal>0.9 )
    {
        lastPoint.setX(matchLoc.x +imgContainer->width()/2);
        lastPoint.setY(matchLoc.y + imgContainer->height()/2);
    }
    else
    {
        lastPoint.setX(0);
        lastPoint.setY(0);
    }
    return getLastPoint();
}

QPoint SimilarInQImage::getLastPoint() const
{
    return lastPoint;
}

void SimilarInQImage::setLastPoint(const QPoint &value)
{
    lastPoint = value;
}
