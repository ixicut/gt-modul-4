#include <QApplication>
#include <QSql>
#include"main_window.h"
#include"widget_show_info.h"

QSqlDatabase MainWindow::db;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    MainWindow::create_database();
    MainWindow::create_table();
    MainWindow win;
    win.show();

    return a.exec();
}


