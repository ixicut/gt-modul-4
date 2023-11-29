#ifndef INFO_MOVIE_DIALOG_H
#define INFO_MOVIE_DIALOG_H

#include<QDialog>
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include<QVBoxLayout>

class InfoMovieDialog: public QDialog
{
    Q_OBJECT
    QTextEdit* text;
    QPushButton* button_ok;

    QVBoxLayout* layout;
public:
    explicit InfoMovieDialog(QDialog *parent = nullptr);
    void set_text(QString str);
    QString get_text();
};

#endif // INFO_MOVIE_DIALOG_H
