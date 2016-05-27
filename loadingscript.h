#ifndef LOADINGSCRIPT
#define LOADINGSCRIPT

// Contains the startup Loading Animation procedure.
// Edit the "Script" to change loading animation.
void sd(){

    QThread::msleep(100);
    out<<endl;
}

void ld(){
    QThread::msleep(300);
    out<<endl;
}

void load(){

out<<"$ wget -O files.txt http://man7.org/linux/man-pages/dir_section_1.html"; ld();
out<<"--2015-12-22 23:10:03--  http://man7.org/linux/man-pages/dir_section_1.html"; ld();
out<<"Resolving man7.org (man7.org)... 213.131.240.174"; ld();
out<<"Connecting to man7.org (man7.org)|213.131.240.174|:80... connected."; ld();
out<<"HTTP request sent, awaiting response... 200 OK"; ld();
out<<"Length: 62885 (61K) [text/html]"; ld();
out<<"Saving to: files.txt"; ld();

out<<"100%[======================================>] 62,885       188KB/s   in 0.3s   "; ld();

out<<"2015-12-22 23:10:04 (188 KB/s) - files.txt saved [62885/62885]"; ld();
out<<"\t\t\t\t\t By"; ld();
out<<"\t\t\t\t\t Aditya Venkatraman"; ld();
out<<"\t\t\t\t\t Gautam Padiyar"; ld();
ld(); ld();
for(int i=0; i<80; i++){
    out<<"-";
    QThread::msleep(1);
}
out<<endl;

/*
out<<""; sd();

*/

system("cls");
}

#endif // LOADINGSCRIPT

