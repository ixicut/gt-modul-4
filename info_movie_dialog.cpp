#include "info_movie_dialog.h"

InfoMovieDialog::InfoMovieDialog(QDialog *parent) : QDialog(parent)
{
      text = new QTextEdit(this);
      button_ok= new QPushButton("&Ok",this);
      layout = new QVBoxLayout;
      layout->addWidget(text);
      layout->addWidget(button_ok);
      setLayout(layout);
      resize(200,150);
      connect(button_ok,SIGNAL(pressed()),this,SLOT(accept()));
}
void InfoMovieDialog::set_text(QString str)
{
    text->setText(str);
}

QString InfoMovieDialog::get_text()
{
    return text->toPlainText();
}
