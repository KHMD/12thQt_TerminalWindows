#include "command.h"
#include <QDebug>
#include <QDir>
#include "globals.h"

mkdir::mkdir(QString cmd){
    QString temp;
    QString dirNAME = cmd.mid(6);
    QDir path;
    bool created = path.mkdir(dirNAME);
    if(created)
        temp = "Directories created\n";
    else if(path.exists(dirNAME))
        temp = "Directory already exists\n";
    else
        temp = "Unable to create directory\n";

    out << temp;
}
/*here there has to be a condition. if directory already exists
 should be diasbled */

