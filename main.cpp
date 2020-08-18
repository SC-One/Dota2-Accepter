#include "mainwindow.h"
#include <QApplication>
#include <QGuiApplication>
#include<QObject>
#include<QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    double Exact{1.0};

    QNetworkAccessManager apiRequester;
    QNetworkRequest requestURl;
    QString tmpStr="http://hcoding.ir/Dota2Accepter/version.php";
    requestURl.setUrl(QUrl(tmpStr));
    apiRequester.get(requestURl);

    QObject::connect(&apiRequester, &QNetworkAccessManager::finished ,[&](QNetworkReply* reply)
    {
        if (reply->error() != QNetworkReply::NoError)
        {
            QMessageBox::about(nullptr, "Dota2 Accepter", "No Internet, This program is created for online Game(Dota2)! <a href='http://hcoding.ir/Dota2Accepter/index.html'>Dota2 Accepter Site</a>");
        }
        else
        {
            QByteArray rawData;
            rawData = reply->readAll();
            while(!reply->isFinished());
            tmpStr.operator=(rawData);
            if(Exact>=tmpStr.toDouble())
            {
                MainWindow *headerAccepterMainWindow{new MainWindow};
                headerAccepterMainWindow->show();
            }
            else
            {
                QMessageBox::about(nullptr, "Dota2 Accepter", "Please update program from <a href='http://hcoding.ir/Dota2Accepter/index.html' alt='Click Me.'>Dota2 Accepter</a>");
            }
        }

    });
    /////////////////////////////////////////////////////////////////////////////////////////////////////







    return a.exec();
}
