#include "command.h"
#include <QFile>
#include <QDir>
#include <QTextStream>
#include "globals.h"
#include <QCommandLineParser>
#include "simplecrypt.h"

using namespace std;

int login::usersCount = 0;

login::login(QString cmd){

    crypto.setKey(Q_UINT64_C(0x0c2ad4a4acb9f023));
    if(cmd.contains(" -n"))
        login_n();
    else if(cmd.contains(" -u"))
        login_u();
    else if(cmd.contains(" -h"))
        login_h();
}

void login::login_n(){
    QString temp1, temp2;
    level = 0;
    out<< "username : "<<endl;
    new_user.username = in.readLine();
    out<<"password : "<<endl;
    temp1 = in.readLine();
    out<<"re-enter password : "<<endl;
    temp2 = in.readLine();
    if(temp1==temp2){
        new_user.epassword = crypto.encryptToString(temp1);
        if(!newUserWrite(new_user.username, new_user.epassword, level)){
            out<<"Sorry try again"<<endl;
            login_n(); // create new user in users file
        }
    }else{
        out<<"Sorry try again"<<endl;
        login_n();
    }
}

int login::newUserWrite(QString u, QString p, int l){

    current_user.username = u;
    current_user.epassword = p;

    usersCount++;
    root = document.createElement("Users");

        document.appendChild(root);

        user = document.createElement("User");
        user.setAttribute("name", u);
        user.setAttribute("id", usersCount); // static variable
        user.setAttribute("password", p);
        user.setAttribute("progress", l);


        root.appendChild(user);

        QFile file("D:/Cpp/qt/17-01-16/gbash/users.xml");
        if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
            return 0;
        }
        else {
            QTextStream stream(&file);
            stream << document.toString();
            file.close();
            out << "New User Created and logged in"<<endl;
            return 1;
        }
}

void login::login_u(){
    QString userps;
    out<< "username : "<<endl;
    new_user.username = in.readLine();
    out<<"password : "<<endl;
    userps = in.readLine();
    QString encrypted = crypto.encryptToString(userps);

    QDomElement root = document.firstChildElement();

    QDomNodeList users = root.elementsByTagName("User");
    QDomElement itemele;

     for(int i = 0; i < users.count(); i++)
     {

        QDomNode usernode = users.at(i);

        if(usernode.isElement())
        {
            itemele = usernode.toElement();
            // cur_is.command = itemele.attribute("command"); // Current user is the one in context
        }
        if(itemele.attribute("password") == encrypted){
            out<<"User looged in"<<endl;
            current_user.username = new_user.username;
            current_user.epassword = encrypted;
            qDebug() << current_user.username<<current_user.epassword;
        }
        else {
            out<<"please try again"<<endl;
        }
     }


    /*
    if(){
    // compare encrypted strings
    }
    else{
        out<<"Sorry try again"<<endl;
        login_u();
    }


}*/
}

void login::login_h(){
    parse.addHelpOption();
    parse.setApplicationDescription("\nThis command allows the user to create a new user or login into a previously created user profile.\nUse -n to create a new user.\nUse -u to log into a new user.");
    out << parse.helpText() << endl;
}

/*
void login::setNull(){
    current_user = NULL;
}
*/






/*
    QString userps = in.readLine();

  //Encryption
  QString encrypted = crypto.encryptToString(userps);

  //Decryption
  QString decrypted = crypto.decryptToString(userps);

*/

