#ifndef ADD_MOVIE_DIALOG_H
#define ADD_MOVIE_DIALOG_H

#include <QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QLabel>
#include<QGridLayout>
#include<QDialog>

class AddMovieDialog : public QDialog
{
    Q_OBJECT
public:

        QPushButton* button_cancel;
        QPushButton*  button_ok;

        QLineEdit* line_edit_name_film;
        QLineEdit* line_edit_producer;
        QLineEdit* line_edit_year;
        QLineEdit* line_edit_raiting;

        QLabel* label_name_film;
        QLabel* label_producer;
        QLabel* label_year;
        QLabel* label_raiting;

        QGridLayout* layout;
        bool button_activ = false;
        bool switch_button();
        void clear_lines();
        AddMovieDialog();

public slots:
        void slot_switch_button();

};

#endif // ADD_MOVIE_DIALOG_H
