#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include"Windows.h"
#include"MouseControl.h"
#include"APIGetter.h"

#include"ScreenShot.h"
#include"SimilarInQImage.h"

#include<QPushButton>
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool getFlagRun() const;
    void setFlagRun(bool value);

private slots:
    void on_startSearchBtn_clicked();
    void updaterCheck();
    void windowGoCorner();
    void checkImage();

private:
    Ui::MainWindow *ui;

    MouseControl *mouseCtrl;
    QTimer *timerClicker;
    QRect *tempScreen;
    QPixmap *AdImageRight;
    QString *topStr;
    QString *bottomStr;
    QString *statusStr;
    APIGetter *getterAPIS;
    QTimer *checkerUpdater;

    ScreenShot *scrShooter;
    SimilarInQImage *imgComprator;
    QImage *img;

    QPushButton* tempBtnRuning;

};
#endif // MAINWINDOW_H
