#include "mainwindow.h"
#include "ui_mainwindow.h"
#define MAXAPIS 3
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,mouseCtrl{new MouseControl}
    ,timerClicker{new QTimer(this)}
    ,tempScreen{new QRect(QGuiApplication::primaryScreen()->geometry())}
    ,AdImageRight{new QPixmap}
    ,topStr{new QString("AtinadAccepter_t")}
    ,bottomStr{new QString("AtinadAccepter_b")}
    ,statusStr{new QString("...")}
    ,getterAPIS{new APIGetter}
    ,checkerUpdater{new QTimer(this)}
    ,scrShooter{new ScreenShot}
    ,imgComprator{new SimilarInQImage}
    ,img{new QImage}
    ,tempBtnRuning{new QPushButton(QString("Please maximize Dota2\n\"click to stop auto Running\""))}
{


    auto tempFontBtn=tempBtnRuning->font();
    tempFontBtn.setBold(true);
    tempBtnRuning->setFont(tempFontBtn);

    tempBtnRuning->hide();


    // @@@@@@@@@@@@@@@@@@ Updater APIs @@@@@@@@@@@@@@@@@@

    checkerUpdater->setInterval(77);
    connect(checkerUpdater, &QTimer::timeout, this, &MainWindow::updaterCheck);
    checkerUpdater->start();
    // !!!!!!!!!!!!!!!!!! Updater APIs !!!!!!!!!!!!!!!!!!


    ui->setupUi(this);
    ui->lblAdImage->setScaledContents(true);

    windowGoCorner();
    timerClicker->setInterval(2777);


    connect(tempBtnRuning,&QPushButton::clicked ,[&]()
    {
        timerClicker->stop();
        this->show();
        tempBtnRuning->hide();
    });

}

MainWindow::~MainWindow()
{

    delete mouseCtrl;
    mouseCtrl = nullptr;

    delete timerClicker;
    timerClicker = nullptr;

    delete tempScreen;
    tempScreen = nullptr;

    delete AdImageRight;
    AdImageRight = nullptr;

    delete topStr;
    topStr = nullptr;

    delete bottomStr;
    bottomStr = nullptr;

    delete statusStr;
    statusStr = nullptr;


    delete getterAPIS;
    getterAPIS = nullptr;

    delete checkerUpdater;
    checkerUpdater = nullptr;

    delete scrShooter;
    scrShooter = nullptr;

    delete imgComprator;
    imgComprator = nullptr;

    delete img;
    img = nullptr;

    delete tempBtnRuning;
    tempBtnRuning = nullptr;




    delete ui;
}

void MainWindow::on_startSearchBtn_clicked()
{

    connect(timerClicker,&QTimer::timeout,this,&MainWindow::checkImage);
    timerClicker->start();

    tempBtnRuning->resize(300,150);
    tempBtnRuning->setGeometry(tempScreen->width()-tempBtnRuning->width(),0
                               ,tempBtnRuning->width(),tempBtnRuning->height());
    this->hide();
    tempBtnRuning->show();


}

void MainWindow::updaterCheck()
{
    ui->lblAdImage->setPixmap(*AdImageRight);
    ui->lblTop->setText(*topStr);
    ui->lblBottom->setText(*bottomStr);

    AdImageRight=getterAPIS->getImgContainer();
    topStr=getterAPIS->getTxtContainerTop();
    bottomStr=getterAPIS->getTxtContainerBottom();
    if(getterAPIS->getCounter()== MAXAPIS)
        checkerUpdater->stop();

}

void MainWindow::windowGoCorner()
{
    window()->move(tempScreen->width()-window()->width(),0);
}

void MainWindow::checkImage()
{
    while ((imgComprator->whereIsIt(*scrShooter->takeShot())).x() !=0 )
    {
        timerClicker->stop();
        this->show();
        tempBtnRuning->hide();
        mouseCtrl->gotoClickingByScale(0.5,0.5);

        keybd_event(VK_RETURN, 0x9C, 0, 0);
        keybd_event(VK_RETURN, 0x9C, KEYEVENTF_KEYUP, 0);
        QApplication::beep();
    }
}
