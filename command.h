#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>
#include <QString>
#include <QThread>
#include "simplecrypt.h"
#include <QtXml>



class echo{
    QString output, cmd;
public:
    echo(QString);
    QString echo_n(QString);
    void echo_a();
    void echo_o();
    void echo_p();
    void echo_h();
};

class ls{
    QString output, cmd, list;
    QDir file_list;
    QStringList names;
    public :
        ls(QString);
        void ls_a();
        void ls_n();
        void ls_t();
        void ls_h();
        void ls_at();
};

class touch{
    QString filename;
    public :
        touch(QString);
};

class cd{
    QString cmd, user;
    public :
        cd(QString);
};

class pwd{
    public :
      pwd();
      void output_path();
};

class rm {
    public:
    rm(QString);

};

class cat {
    QString filename, cmd;
    int length, index;
    QByteArray output;
    public :
        cat(QString, int);
        void cat_h();
        void cat_n(int);
        void cat_a();
        void cat_o();

};

class mkdir {
    public:
        mkdir(QString);

};
class grep {
     QByteArray putt, putt_n, check;
     QString user, cmd, filename, substr;
     int subnum;

public :
    grep(QString);
    void grep_n();
    void grep_i();
};
class login{
    int level;
    SimpleCrypt crypto;
    static int usersCount;
    QDomDocument document;
    QDomElement root, user;
    struct User{
      QString username, epassword;
    }new_user, current_user;


public :
    void setNull();
    login(QString);
    void login_n(); // new user
    void login_u(); // already user
    void login_h();
    int newUserWrite(QString u, QString p, int l);
};

class man{

public:
    man(QString);
};

#endif // COMMAND_H



