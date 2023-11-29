#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QSql>
#include <QtSql>
#include <QTableView>
#include <QSqlTableModel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRegExp>
#include <QMessageBox>
#include "filter_widget.h"
#include "my_model.h"
#include "add_movie_dialog.h"
#include "widget_show_info.h"
#include "info_movie_dialog.h"

class MainWindow : public QWidget
{
    Q_OBJECT

    static QSqlDatabase db;
    FilterWidget* filter;
    QSqlTableModel* model;
    MyModel* myModel;
    QTableView* view;

    InfoMovieDialog* w_info;
    AddMovieDialog* my_dialog_add;

    QVBoxLayout* lay_button;
    QHBoxLayout* lay;
    QVBoxLayout* lay_all;

    QPushButton* button_add;
    QPushButton* button_info;
    QPushButton* button_close;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    bool add_new_row();

    bool add(QString name, QString producer, int year, int reit);

    void show_info();

    static bool create_database();

    static bool create_table();

    public slots:
    void slot_add_new();
    void slot_show_add_dialog();
    void slot_close();
    void slot_find();
    void slot_reset_filter();
    void slot_show_info();
};

#endif // MAIN_WINDOW_H
