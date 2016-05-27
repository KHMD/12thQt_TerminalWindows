#include "command.h"
#include "globals.h"
#include <QtCore>
#include<QTextStream>
using namespace std;

grep::grep(QString input){
    cmd = input;

if(cmd.contains("-i"))
    this->grep_i();

else
    this->grep_n();
}

void grep::grep_n(){
       user = cmd.mid(5);
       subnum = user.indexOf(" ");
       filename = user.mid(subnum+1);
       substr = user.left(subnum);

       QFile file(filename);
       file.open(QIODevice::ReadOnly|QIODevice::Text);
       putt_n = file.readAll();
       file.close();

       string s = substr.toStdString();
       check = s.c_str();
       if(putt_n.contains(check))
           out << check << endl << "Found" << endl;
       else
           out << "Not Found" << endl;
}
void grep::grep_i(){
    user = cmd.mid(8);
    subnum = user.indexOf(" ");
    filename = user.mid(subnum+1);
    substr = user.left(subnum);
    substr = substr.toLower();

    //file read
    QFile file(filename);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    putt = file.readAll();


    //checking
    string s = substr.toStdString();
    check = s.c_str();
    if(putt.contains(check))
        out << check << endl << "Found" << endl;
    else
        out << "Not Found" <<endl;

    file.close();
}
