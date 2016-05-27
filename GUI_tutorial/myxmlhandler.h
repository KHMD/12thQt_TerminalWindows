#ifndef MYXMLHANDLER
#define MYXMLHANDLER

#include<QtXml/QDomDocument>
#include<QtXml>

#include<QDebug>

void ListElements(QDomElement root, QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);

     qDebug() << "Total items = " << items.count();

     for(int i = 0; i < items.count(); i++)
     {
        QDomNode itemnode = items.at(i);

        //convert to element
        if(itemnode.isElement())
        {
            QDomElement itemele = itemnode.toElement();
            qDebug() << itemele.attribute(attribute);
        }
     }
}

void Write(){

    QDomDocument document;

    QDomElement root = document.createElement("InstructionSet");

    document.appendChild(root);

    QDomElement instruction = document.createElement("Instruction");
    instruction.setAttribute("name", "programmer's reference");
    instruction.setAttribute("ino", "programmer's reference");
    instruction.setAttribute("command", "programmer's reference");
    instruction.setAttribute("desc", "programmer's reference");
    instruction.setAttribute("sec_dec", "programmer's reference");

    root.appendChild(instruction);

    QFile file("D:/Cpp/qt/XMLTest/sample.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){

        qDebug() << "Failed to open";

    }
    else {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug() << "Fin.";

    }


}




void Read(){
    QDomDocument document;
    QFile file("D:/Cpp/qt/XMLTest/sample.xml");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){

        qDebug() << "Failed to open";

    }
    else {
        if(!document.setContent(&file))
        {
            qDebug() << "Failed";

        }
        //file.close();
    }

    QDomElement root = document.firstChildElement();
    qDebug() << root.text();

    ListElements(root,"Instruction", "ino");

}


#endif // MYXMLHANDLER

