#include "command.h"
#include <QDebug>
#include <QDir>
#include <QFileInfoList>
#include <QCommandLineParser>
#include "globals.h"
#include <QStringList>
#include <QCommandLineOption>
#include <QFileInfo>

ls::ls(QString input){
    cmd = input;
    file_list.setNameFilters(QStringList() << "*.txt");
    if(cmd.contains(" -at") or cmd.contains(" -ta")){
        this->ls_at();
    }
    else if(cmd.contains(" -a"))
    {
        this->ls_a();
    }
    else if(cmd.contains(" -t")){
        this->ls_t();
    }
    else if(cmd.contains(" -h") or cmd.contains("--help") or cmd.contains("-?")){
        this->ls_h();
    }

    else
        this->ls_n();

}

void ls::ls_t(){
    names = file_list.entryList(QDir::Files|QDir::NoDotAndDotDot|QDir::AllDirs, QDir::Time);
    list = names.join(" \n");
    out << list <<endl;
}

void ls::ls_a(){
    names = file_list.entryList(QDir::Files|QDir::Hidden|QDir::AllDirs);
    list = names.join(" \n");
    out << list << endl;
}

void ls::ls_h(){
    parse.addHelpOption();
    parse.setApplicationDescription("\nLists all files in the current directory.\nUse -a opton to lists all files including hidden\n");
    out<< parse.helpText() <<endl ;
}

void ls::ls_n(){
    foreach (QFileInfo select, file_list.entryList(QDir::Files|QDir::NoDotAndDotDot|QDir::AllDirs)) {
        QString list = select.fileName();

        out << list << " \n";

    }
    out << output <<endl;
}
void ls::ls_at(){
    names = file_list.entryList(QDir::Files|QDir::Hidden|QDir::AllDirs, QDir::Time );
    list = names.join(" \n");
    out << list <<endl;
}
