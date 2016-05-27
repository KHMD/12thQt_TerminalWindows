#include "command.h"

man::man(QString cmd){
    QString file = "man/" + cmd.mid(4);
    file += ".1.html.txt";
    qDebug() << file;
    cat c(file, 1);
}
