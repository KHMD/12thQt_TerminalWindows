#ifndef COMMSTHREAD_H
#define COMMSTHREAD_H

#include <QObject>
#include <QtCore>
#include <QTextStream>

class commsThread : public QThread
{
    QDir watch;
    QString filepath;
    QFileSystemWatcher alter;
public:
    commsThread();
    void run();
    void commFunc(QString);
public slots:
    void start();
signals:
    void started();
};

#endif // COMMSTHREAD_H
