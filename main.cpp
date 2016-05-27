#include <QCoreApplication>
#include <iostream>
#include <string.h>
#include <QProcess>
#include <QString>
#include <QTextStream>
#include <QDir>
#include <QFile>
#include "command.h"
#include <QFileSystemWatcher>
#include<QUrl>
#include<QCommandLineParser>
#include<QDebug>
#include "globals.h"
#include <QtCore>
#include "loadingscript.h"
using namespace std;


extern bool qcondition;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setApplicationName("gbash");
    QCoreApplication::setApplicationVersion("1.0");

    bool qs = true;
    load();
    QString user_str;

    out << "                          Welcome to the gBash terminal" << endl;
    out<<"                 (-t) Tutorial   (-m, n) Missions  (-f) Freeplay  " << endl << endl << endl;



    QString program = "Z:/Project Files/gbash/build-GUI-Desktop_Qt_5_5_1_MinGW_32bit-Debug/debug/GUI";
    QStringList arguments;

    QProcess *myProcess = new QProcess;

    do{
        printf("$ ");
        user_str = in.readLine();
        if(user_str.contains("exit"))
        {
            qs = false; //quit statement
            out << "Thank You\n";
            break;
        }
        else if(user_str.startsWith("freeplay")||user_str.startsWith("-f")){
            continue;
            out<<"Please Login (login -h for more)";
        }
     else if(!(user_str.startsWith("freeplay")||user_str.startsWith("-f")) && (user_str.startsWith("Tutorial")||user_str.startsWith("-t")||user_str.startsWith("mission")||user_str.startsWith("-m") )){
            myProcess->start(program, arguments);
        }

     else if(user_str.startsWith("login ")){
            login l(user_str);
        }

     else if(user_str.startsWith("echo ")){   // extra space to prevent echosdfsfd from working.
        echo e(user_str);   // make this dynamic if possible.
    }

     else if(user_str.startsWith("ls")){
         ls l(user_str);
    }

     else if (user_str.startsWith("pwd")){
        pwd *p = new pwd;
        p->output_path();
    }

     else if(user_str.startsWith("clear")){
         system("cls");
}

     else if(user_str.startsWith("mkdir ")){
        mkdir m(user_str);      
    }

     else if(user_str.startsWith("rm ")){
        rm r(user_str);
    }
     else if(user_str.startsWith("grep ")){
         grep g(user_str);
        }

     else if(user_str.startsWith("touch ")){
        touch t(user_str);
    }

     else if(user_str.startsWith("cat ")){
        cat c(user_str, 0);
    }

     else if(user_str.startsWith("cd ")){
        cd c(user_str);
    }

      else if(user_str.startsWith("man ")){
           man m(user_str);
       }
     else
         qWarning("Command not found\n");

    }while(qs);

return 0;

    return a.exec();

}
