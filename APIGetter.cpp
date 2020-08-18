#include "APIGetter.h"

APIGetter::APIGetter(QObject *parent) : QObject(parent)
  ,counter{0}
  ,apiRequester{new QNetworkAccessManager}
  ,imgContainer{new QPixmap}
  ,txtContainerTop{new QString("AtinadAccepter")}
  ,txtContainerBottom{new QString("AtinadAccepter")}
{
    connect(apiRequester, &QNetworkAccessManager::finished ,this ,&APIGetter::gotRawData);



    tmpStr="http://hcoding.ir/Dota2Accepter/explain";
    setRequestURl(tmpStr);
    apiRequester->get(requestURl);
}


void APIGetter::gotRawData(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
    else
    {
        rawData = reply->readAll();
        while(!reply->isFinished());
        switch (counter)
        {
        case 0:
            txtContainerTop->operator=(rawData);
            ++counter;

            tmpStr="http://hcoding.ir/Dota2Accepter/about";
            setRequestURl(tmpStr);
            apiRequester->get(requestURl);

            break;
        case 1:
            txtContainerBottom->operator=(rawData);
            ++counter;

            tmpStr="http://hcoding.ir/Dota2Accepter/AdImage.png";
            setRequestURl(tmpStr);
            apiRequester->get(requestURl);

            break;
        case 2:
            imgContainer->loadFromData(rawData);
            ++counter;
            break;
        default:
            break;
        }
    }
}

int APIGetter::getCounter() const
{
    return counter;
}

QPixmap *APIGetter::getImgContainer() const
{
    return imgContainer;
}

QString *APIGetter::getTxtContainerBottom() const
{
    return txtContainerBottom;
}

QString *APIGetter::getTxtContainerTop() const
{
    return txtContainerTop;
}


APIGetter::~APIGetter()
{
    delete apiRequester;
    apiRequester=nullptr;

    delete imgContainer;
    imgContainer=nullptr;
}

void APIGetter::setRequestURl(QString &strURL)
{
    requestURl.setUrl(QUrl(strURL));
}
