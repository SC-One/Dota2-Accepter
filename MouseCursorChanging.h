#ifndef MOUSCURSORCHANGING_H
#define MOUSECURSORCHANGING_H

#include <QObject>
#include <QTimer>
#include <QCursor>

class MouseCursorChanging : public QObject
{
    Q_OBJECT
public:
    explicit MouseCursorChanging(QObject *parent = nullptr);

public slots:
    void start();
    void stop();


signals:
    void changingPos();

public slots:

private:
    QTimer *tempTmr;
    QPoint tempPos;
};

#endif // MOUSECURSORCHANGING_H
