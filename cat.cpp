#include "command.h"
#include <QFile>
#include <QDir>
#include <QTextStream>
#include "globals.h"
#include <QCommandLineParser>
using namespace std;

cat::cat(QString input, int b){
    cmd = input;

    if(cmd.contains(" -h") or cmd.contains(" --help") or cmd.contains(" -?"))
        this->cat_h();

    else if(cmd.contains(">> "))
        this->cat_a();

    else if (cmd.contains("> "))
       this->cat_o();

    else
        this->cat_n(b);
}
void cat::cat_h(){
    parse.addHelpOption();
    parse.setApplicationDescription("\nThis command extracts the contents of the specified file and displays it as standard output\nUse > followed by a filename to overwrite the contents of that file by the standard output of the current command\nUse >> followed by a filename to append the standard output of the current command into that file\nUse \'|\' to pipe the standard output to another command\n");
    out << parse.helpText() << endl;
}
void cat::cat_o(){
    index = cmd.indexOf(">");
    length = cmd.length();
    filename = cmd.right(length - index - 2);

    QFile file(filename);
    QString in = cmd.remove(index, length);
    in = cmd.mid(4);
    if (!file.exists())
        out << "File does not exist!\n";
    else
    {
        QFile reader(in);
        reader.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray putt = reader.readAll();
        out << putt << endl;
        reader.close();

        file.open(QIODevice::WriteOnly | QIODevice::Text);
        file.flush();
        file.write(putt);
        file.close();

    }
}
void cat::cat_a(){

            index = cmd.indexOf(">>");
            length = cmd.length();
            QString filename = cmd.right(length - index - 3);
            QFile file(filename);

            if (!file.exists())
                out << "File does not exist!\n";
            else
            {

                QString in = cmd.remove(index, length);
                in = cmd.mid(4);
                QFile reader(in);
                reader.open(QIODevice::ReadOnly);
                QByteArray putt = reader.readAll();
                QString disp = putt;
                out << disp << endl;
                reader.close();

                file.open(QIODevice::Append | QIODevice::Text);
                file.write(putt);
                file.close();

            }
}
void cat::cat_n(int b){
    if(!b)
        filename  = cmd.mid(4);
    else
        filename = cmd;
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    output = file.readAll();
    out << output << endl;
    file.close();
}
