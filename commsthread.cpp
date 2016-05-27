#include "commsthread.h"
#include <QtCore>
#include <QTextStream>
#include <QFileSystemWatcher>
#include "globals.h"
using namespace std;

commsThread::commsThread()
{
    filepath = watch.absoluteFilePath("common.txt");
}
//console
void commsThread::run(){

}
void commsThread::start(){

    QFileSystemWatcher::QPrivateSignal follow;
    alter.fileChanged(filepath, follow);
}
void commsThread::started(){

}
void commsThread::commFunc(QString user_str){
    string s = user_str.toStdString();
    QByteArray putt = s.c_str();
    cFile.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text );
    cFile.write("\nC: ");
    cFile.write(putt);
    cFile.close();
}
