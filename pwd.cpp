#include "command.h"
#include <QFileInfoList>
#include <QDir>
#include <QTextStream>
#include "globals.h"

pwd::pwd(){

}
void pwd::output_path(){
    if(curr.setCurrent(var_path))
    out << var_path << endl;
}
