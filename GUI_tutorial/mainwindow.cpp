#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globals.h"
#include<QFile>
#include <QThread>
#include <QFileSystemWatcher>
#include "commsthread.h"
#include<QtXml>
#include "myXMLHandler.h"

int MainWindow::startCount = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    at_end = false;

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    if(!at_end){
    startCount++;
    if(startCount > 0)
        ui->start->setText("Next ");
    ui->Desc->setEnabled(true);
    ui->Details->setEnabled(true);
    ui->moreButton->setEnabled(true);
    ui->Command->setEnabled(true);
    ui->Mission->setEnabled(true);
    ui->Details->setText("");
    }
    else if(at_end){
        ui->Desc->setText(" ");
        ui->Command->setText(" ");
        ui->Mission->setText(" ");
        ui->Desc->setEnabled(false);
        ui->Details->setEnabled(false);
        ui->moreButton->setEnabled(false);
        ui->Command->setEnabled(false);
        ui->Mission->setEnabled(false);
        ui->Details->setEnabled(true);
        ui->Details->setText("End of tutorial reached");
    }



    this->retrieve_next_instruction();

    //qDebug() << startCount;
}

void MainWindow :: retrieve_next_instruction(){

    QDomDocument document;
    QString doc = "Z:/Project Files/gbash/GUI_tutorial/tutorial.xml";
    QFile file(doc);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        out << "Failed to open" << endl;
    }
    else {
        if(!document.setContent(&file))
        {
            out << "Failed" <<endl;
        }
    }

    QDomElement root = document.firstChildElement();

    QDomNodeList commands = root.elementsByTagName("Instruction");
    // qDebug() << commands.length();

    for(int i=0; i<commands.length(); i++){

        QDomNode commandnode = commands.at(startCount);

        if(commandnode.isElement())
        {
            QDomElement itemele = commandnode.toElement();
            cur_is.command = itemele.attribute("command");
            cur_is.desc = itemele.attribute("desc");
            cur_is.sec_desc =  itemele.attribute("sec_dec");
            cur_is.ino = itemele.attribute("ino");

        }

        ui->Mission->setText("Task " + cur_is.ino);
        ui->Desc->setText(cur_is.desc);
        ui->Command->setText(cur_is.command);
        int s = startCount, c=commands.length()-1;
        QString st = QString("%1 of %2").arg(s).arg(c);
        ui->progress->setText(st);
        if(startCount >= commands.length()-1)
            at_end = true;
     }
    file.close();
}


void MainWindow::on_moreButton_clicked(){
    ui->Details->setText(cur_is.sec_desc);
}
