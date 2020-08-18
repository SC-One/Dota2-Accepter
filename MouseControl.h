#ifndef MOUSECONTROL_H
#define MOUSECONTROL_H

#include <QObject>

#include<QCursor>
#include<QGuiApplication>
#include<QScreen>
#include "Windows.h"

class MouseControl : public QObject
{
    Q_OBJECT
public:
    explicit MouseControl(QObject *parent = nullptr);
    ~MouseControl();

    int getXPosCursor(){return cursor->pos().x();}
    int getYPosCursor(){return cursor->pos().y();}

    void gotoWaiting(int x,int y);
    void gotoClicking(int x,int y);

    void gotoWaitingByScale(double x,double y);
    void gotoClickingByScale(double x,double y);

public slots:
    void Clicking();


signals:

public slots:

private:
    QCursor *cursor;
    QScreen *tempScreen;

    void updateVals();
    bool checkScale(double x,double y);
    bool checkValue(int x,int y);
};

#endif // MOUSECONTROL_H
