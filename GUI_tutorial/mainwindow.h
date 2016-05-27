#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void retrieve_next_instruction();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_moreButton_clicked();

    void on_start_clicked();

private:
    bool at_end;
    Ui::MainWindow *ui;
    static int startCount;
    struct instructionstruct {

        QString ino, name, command, desc, sec_desc;
    }cur_is;
};

#endif // MAINWINDOW_H
