#ifndef COMMSTHREAD_H
#define COMMSTHREAD_H
#include <QtCore>
#include <QObject>
#include <QTextStream>

class commsThread : public QThread
{
    QString readtxt;
    int j, i;
    char c;
public:
    commsThread();
    void run();
    void commFunc();
    void reverseStr(QString &);

public slots:
 void start();

signals:
    void started();
};

#endif // COMMSTHREAD_H
