#ifndef APIGETTER_H
#define APIGETTER_H

#include <QObject>

#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QPixmap>
#include<QUrl>

class APIGetter : public QObject
{
    Q_OBJECT
public:
    explicit APIGetter(QObject *parent = nullptr);
    ~APIGetter();

    QString *getTxtContainerTop() const;

    QString *getTxtContainerBottom() const;

    QPixmap *getImgContainer() const;

    int getCounter() const;

public slots:
    void gotRawData(QNetworkReply *);

private:
    int counter;
    QNetworkAccessManager *apiRequester;
    QNetworkRequest requestURl;
    QByteArray rawData;

    QPixmap *imgContainer;
    QString tmpStr;
    QString *txtContainerTop;
    QString *txtContainerBottom;

    void setRequestURl(QString &);
};

#endif // APIGETTER_H
