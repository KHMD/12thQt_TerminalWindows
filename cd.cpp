#include <command.h>
#include <QDir>
#include <QFile>
#include "globals.h"
#include <QTextStream>

cd::cd(QString input){
    cmd = input;
    user = cmd.mid(3);

    if(cmd.contains("..")){
       if(curr.cdUp()){
          out << "Directory changed" << endl;
}}
    else{
     if(curr.cd(user)){
         QString path = curr.absoluteFilePath(user);
         if(QDir::setCurrent(path))
         out << "Directories changed" << endl;}
     else
         qWarning("Directory doesn't exist!\n");
    }
}

