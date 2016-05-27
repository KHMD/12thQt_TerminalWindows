#include "commsthread.h"
#include <QtCore>
#include <QTextStream>
#include <QFileSystemWatcher>
#include <QDir>
#include <qfilesystemwatcher.h>
#include <fstream>
#include "globals.h"
#include <algorithm>
using namespace std;

commsThread::commsThread()
{
    j =0;
    i = 0;
}
//GUI
void commsThread::run(){

}
void commsThread::started(){
    QDir watch;
    QFileSystemWatcher::QPrivateSignal follow;
    QString filepath = watch.absoluteFilePath("common.txt");
    QFileSystemWatcher alter;
    alter.fileChanged(filepath, follow );


}
void commsThread::commFunc(){

}
void commsThread::reverseStr(QString &rev){
    for(QString::const_iterator c = rev.constEnd(); c!= rev.constBegin(); ){
        --c;
        GUItxt += *c;
    }
}

void commsThread::start(){

    fstream ifile("common.txt", ios::in);
    ifile.seekg(0, ios::end);
    j = ifile.tellg();
    while(!readtxt.contains(":C")){
        j--;
        ifile.get(c);
        readtxt.append(c);
    }
    reverseStr(readtxt);
    emit started();
    ifile.close();

}
