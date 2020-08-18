#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QObject>
#include<QImage>

class ScreenShot : public QObject
{
    Q_OBJECT
public:
    QImage *img;

    ScreenShot();
    ~ScreenShot();
    QImage &getImg(){return *img;}

signals:

public slots:
    QImage *takeShot();
    QImage *takeShot(double ,double ,double ,double);
};

#endif // SCREENSHOT_H
