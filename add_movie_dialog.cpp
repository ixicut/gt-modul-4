#include "add_movie_dialog.h"
#include<QIntValidator>

bool AddMovieDialog::switch_button()
{
    if(line_edit_name_film->text().isEmpty())return false;
    if(line_edit_producer->text().isEmpty())return false;
    if(line_edit_year->text().isEmpty())return false;
    return true;
}

void AddMovieDialog::clear_lines()
{   line_edit_name_film->clear();
    line_edit_producer->clear();
    line_edit_year->clear();
    line_edit_raiting->clear();

}

void AddMovieDialog::slot_switch_button()
{

    button_ok->setEnabled(switch_button());
}

AddMovieDialog::AddMovieDialog()
{

    button_ok = new QPushButton("&Ok",this);
    button_cancel = new QPushButton("&Cancel",this);
    button_ok->setEnabled(false);

    line_edit_name_film = new QLineEdit(this);
    line_edit_producer = new QLineEdit(this);
    line_edit_year = new QLineEdit(this);
    line_edit_raiting = new QLineEdit(this);

    label_name_film = new QLabel("Title",this);
    label_producer = new QLabel("Producer",this);
    label_year = new QLabel("Year",this);
    label_raiting = new QLabel("Rating",this);
    layout = new QGridLayout;

    layout->addWidget(label_name_film,0,0);
    layout->addWidget(line_edit_name_film,0,1);
    layout->addWidget(label_producer,1,0);
    layout->addWidget(line_edit_producer,1,1);
    layout->addWidget(label_year,2,0);
    layout->addWidget(line_edit_year,2,1);
    layout->addWidget(label_raiting,3,0);
    layout->addWidget(line_edit_raiting,3,1);
    layout->addWidget(button_ok,4,0);
    layout->addWidget(button_cancel,4,1);


    QIntValidator* valid_year = new QIntValidator;
    line_edit_year->setValidator(valid_year);
    line_edit_raiting->setValidator(valid_year);
    setLayout(layout);

    connect(button_cancel,SIGNAL(pressed()),this,SLOT(close()));
    connect(line_edit_name_film,SIGNAL(textEdited(QString)),this,SLOT(slot_switch_button()));
    connect(line_edit_producer,SIGNAL(textEdited(QString)),this,SLOT(slot_switch_button()));
    connect(line_edit_year,SIGNAL(textEdited(QString)),this,SLOT(slot_switch_button()));

}
