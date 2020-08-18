#include "MouseCursorChanging.h"

MouseCursorChanging::MouseCursorChanging(QObject *parent) :
    QObject(parent)
  ,tempTmr{new QTimer}
  ,tempPos{QCursor::pos()}
{
    tempTmr->setInterval(10);
    connect(tempTmr, &QTimer::timeout, [&]()
    {
        if(tempPos!=(QCursor::pos()))
        {
            tempPos=QCursor::pos();
            emit changingPos();
        }
    });
}

void MouseCursorChanging::start()
{
    tempPos=QCursor::pos();
    tempTmr->start();
}

void MouseCursorChanging::stop()
{
    tempTmr->stop();
}

