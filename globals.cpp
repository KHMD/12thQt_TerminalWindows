#include "globals.h"
#include <QDir>
#include <QtCore>
#include <QCommandLineParser>
#include <qxmlstream.h>
#include <QFile>


QDir curr = QDir::current();
QDir GUI;
QString var_path = curr.currentPath();
QCommandLineParser parse;
QFile cFile("common.txt");
QString cmd;
QTextStream in(stdin);
QTextStream out(stdout);
