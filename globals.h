#ifndef GLOBALS
#define GLOBALS
#include <QDir>
#include <QtCore>
#include <QCommandLineParser>
#include <QFile>

extern bool set_var; //quit condition
extern QString var_path, cmd;
extern QCommandLineParser parse;
extern QDir curr, GUI;
extern QTextStream in, out;


#endif // GLOBALS

