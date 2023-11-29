#include "main_window.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    lay_button=new QVBoxLayout;
    lay = new QHBoxLayout;
    lay_all = new QVBoxLayout;

    button_add = new QPushButton("&Add new",this);
    button_info = new QPushButton("&Information",this);
    button_close = new QPushButton("&Close",this);
    lay_button->addWidget(button_add);
    lay_button->addWidget(button_info);
    lay_button->addWidget(button_close);
    lay_button->setAlignment(this,Qt::AlignRight);
    
    filter = new FilterWidget(this);
    w_info = new InfoMovieDialog;
    lay_all->addWidget(filter);
    resize(700,50);

    model = new QSqlTableModel;
    
    myModel = new MyModel;
    my_dialog_add = new AddMovieDialog;
    myModel->setTable("films");
    myModel->select();
    myModel->removeColumn(4);
    model->setTable("films");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    myModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    view = new QTableView;
    view->setModel(myModel);
    view->setParent(this);
    view->move(0,50);
    view->resize(700,250);

    lay->addWidget(view);
    lay->addLayout(lay_button);
    lay_all->addLayout(lay);
    setLayout(lay_all);

    resize(750,400);
    connect(button_add,SIGNAL(clicked(bool)),this,SLOT(slot_show_add_dialog()));
    connect(my_dialog_add->button_ok,SIGNAL(pressed()),this,SLOT(slot_add_new()));
    connect(button_close,SIGNAL(pressed()),this,SLOT(slot_close()));
    connect(filter->button_find,SIGNAL(pressed()),this,SLOT(slot_find()));
    connect(filter->button_reset,SIGNAL(pressed()),this,SLOT(slot_reset_filter()));

    connect(button_info,SIGNAL(pressed()),this,SLOT(slot_show_info()));
}

bool MainWindow::add_new_row()
{
    QString temp_name_film = my_dialog_add->line_edit_name_film->text();
    QString temp_producer = my_dialog_add->line_edit_producer->text();
    int temp_year=my_dialog_add->line_edit_year->text().toInt();
    int temp_rait=my_dialog_add->line_edit_raiting->text().toInt();

    QSqlTableModel tempmodel;
    tempmodel.setTable("films");
    tempmodel.setFilter("title = '"+temp_name_film+"'");
    tempmodel.select();

    if(tempmodel.rowCount())QMessageBox::information(0,"Info","This name is already in the database");

        tempmodel.setTable("films");
        tempmodel.setFilter("producer = '"+temp_producer+"'");
        tempmodel.select();

    if(tempmodel.rowCount()==0 ) {

     QMessageBox* message= new QMessageBox(QMessageBox::Information,"Info","There is no such producer in the database! Add a producer? ",QMessageBox::Yes | QMessageBox::No);
     int yes_or_no=message->exec();

    if(yes_or_no==QMessageBox::Yes)
    {
      add(temp_name_film,temp_producer,temp_year,temp_rait);
      myModel->select();
      myModel->removeColumn(4);
      my_dialog_add->clear_lines();
      my_dialog_add->hide();
      return true;
    }

     my_dialog_add->clear_lines();
     my_dialog_add->hide();
     return false;
    }

   add(temp_name_film,temp_producer,temp_year,temp_rait);
    myModel->select();
    myModel->removeColumn(4);
    my_dialog_add->clear_lines();
    my_dialog_add->hide();
    return true;
}

bool MainWindow::add(QString name, QString producer, int year, int reit=0)
{
    model->insertRow(0);
    model->setData(model->index(0,0),name);
    model->setData(model->index(0,1),producer);
    model->setData(model->index(0,2),year);
    model->setData(model->index(0,3),reit);
    model->submitAll();
    model->select();

    myModel->select();
    myModel->removeColumn(4);
    return true;
}

void MainWindow::show_info()
{

    QSqlTableModel temp_model;
    temp_model.setEditStrategy(QSqlTableModel::OnManualSubmit);
    temp_model.setTable("films");

    QModelIndex tmpindex=view->currentIndex();
    int row=tmpindex.row();

    QSqlRecord rec=myModel->record(row);
    temp_model.setFilter("title = '"+rec.value("title").toString()+"'");
    temp_model.select();

    QSqlRecord rec2=temp_model.record(0);

    w_info->set_text(rec2.value("description").toString());
    w_info->show();
    if(w_info->exec()==QDialog::Accepted){

    temp_model.setData(temp_model.index(0,4),w_info->get_text());


    temp_model.submitAll();

    myModel->select();
    myModel->removeColumn(4);
    }
}

bool MainWindow::create_database()
{
     db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("testFilms");

   if(!db.open()){
      QMessageBox::information(0,"Error ","Error on opening database");
       qDebug()<<"Eror open database";
    return false;
   }
   return true;
}

bool MainWindow::create_table()
    {
        QSqlQuery query;
        QString str="create table films (title text not null, producer text not null,year integer,rating integer, description text);";
        if(!query.exec(str)){
       return false;
        }
    return true;
    }
    
    void MainWindow::slot_add_new()
{
    add_new_row();

}

void MainWindow::slot_show_add_dialog()
{
    my_dialog_add->show();
}

void MainWindow::slot_close()
{
    model->submitAll();
    this->close();
    myModel->submitAll();
    this->close();
}

void MainWindow::slot_find()
{
    QString name_film=filter->line_edit_film->text();
    QString year =filter->line_edit_year->text();
    QString rait=filter->line_edit_rait->text();

    if(name_film!="" && year!="" && rait !="" ){
    myModel->setFilter(" title = '"+name_film+"' And year = '"+year+"' and rating = '"+rait+"' ");
    }

    if(name_film!="" && year!="" && rait =="" ){
      myModel->setFilter(" title = '"+name_film+"' And year = '"+year+"' ");
    }

    if(name_film!="" && year=="" && rait !="" ){
      myModel->setFilter(" title = '"+name_film+"'  and rating = '"+rait+"' ");
    }

    if(name_film=="" && year!="" && rait !="" ){  // поиск по году и рейтингу
      myModel->setFilter("  year = '"+year+"' and rating = '"+rait+"' ");
    }

    if(name_film=="" && year=="" && rait !="" ){ // поиск по рейтингу
      myModel->setFilter("  rating = '"+rait+"' ");
    }

    if(name_film=="" && year!="" && rait =="" ){
      myModel->setFilter("  year = '"+year+"'  ");
    }

    if(name_film!="" && year=="" && rait =="" ){
      myModel->setFilter(" title = '"+name_film+"'");
    }

    myModel->select();
}

void MainWindow::slot_reset_filter()
{
    filter->line_edit_film->clear();
    filter->line_edit_year->clear();
    filter->line_edit_rait->clear();
    myModel->setTable("films");
    myModel->select();
    myModel->removeColumn(4);

}

void MainWindow::slot_show_info()
{
    show_info();
}
