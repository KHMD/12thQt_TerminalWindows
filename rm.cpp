#include "command.h"
#include <QDebug>
#include <QDir>
#include "globals.h"

rm::rm(QString cmd){
    char dec;
    QString dirNAME = cmd.mid(3);
    QDir path;
    if(cmd.contains(".txt"))
    path.remove(dirNAME);
    else if(cmd.contains(" -r")){
        out << "Are you sure about this? It's gonna delete everything." <<endl;
        in >> dec;

        if(dec == 'Y')
        path.removeRecursively();
    }
    else
      path.rmdir(dirNAME);
}
