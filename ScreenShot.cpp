#include "ScreenShot.h"
#include<QGuiApplication>
#include<QScreen>
#include<QPixmap>

ScreenShot::ScreenShot():
        img{new QImage()}
{

}

ScreenShot::~ScreenShot()
{
    delete img;
    img=nullptr;
}

QImage* ScreenShot::takeShot()
{
    img->fill(qRgba(0, 0, 0, 255));
    *img = QGuiApplication::primaryScreen()->grabWindow(0).toImage();
    return img;
}

QImage *ScreenShot::takeShot(double x1, double y1, double x2, double y2)
{
    takeShot();
    QRect rect(x1*img->width(), y1*img->height(), (x2-x1)*img->width() , (y2-y1)*img->height());
    *img = img->copy(rect);
    return img;
}
