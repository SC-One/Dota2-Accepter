#include "MouseControl.h"


MouseControl::MouseControl(QObject *parent) :
    QObject(parent)
  , cursor{new QCursor()}
  ,tempScreen{QGuiApplication::primaryScreen()}
{
}

MouseControl::~MouseControl()
{
    delete cursor;
    cursor=nullptr;
}




void MouseControl::Clicking()
{


    INPUT    Input={0};
    // left down
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
    ::SendInput(1,&Input,sizeof(INPUT));

    // left up
    ::ZeroMemory(&Input,sizeof(INPUT));
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
    ::SendInput(1,&Input,sizeof(INPUT));


//    INPUT Inputs[2] = {0};
//    Inputs[0].type = INPUT_MOUSE;
//    Inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
//    Inputs[1].type = INPUT_MOUSE;
//    Inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

//    SendInput(2, Inputs, sizeof(INPUT));
}


void MouseControl::gotoWaiting(int x, int y)
{
    if(checkValue(x,y))
        cursor->setPos(tempScreen ,x ,y);
}


void MouseControl::gotoClicking(int x,int y)
{
    gotoWaiting(x,y);
    Clicking();
}

void MouseControl::gotoWaitingByScale(double x,double y)
{
    if(checkScale(x,y))
    {
        gotoWaiting(static_cast<int>(tempScreen->availableGeometry().width()*x)
                    ,static_cast<int>(tempScreen->availableGeometry().height()*y));
    }
}

void MouseControl::gotoClickingByScale(double x, double y)
{
    gotoWaitingByScale(x,y);
    Clicking();
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Private functions that contain checking and usefull functions


bool MouseControl::checkScale(double x, double y)
{
    if(x<=1 && y<=1
            && x>=0 && y>=0)
    {
        return true;
    }
    else
        return false;
}

bool MouseControl::checkValue(int x, int y)
{
    if(x<=tempScreen->availableGeometry().width()
            &&  x>=0
            &&  y>=0
            &&  y<=tempScreen->availableGeometry().height())
        return true;
    else
        return false;

}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Private functions that contain checking and usefull functions
