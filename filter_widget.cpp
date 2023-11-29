#include "filter_widget.h"

FilterWidget::FilterWidget(QWidget *parent) : QWidget(parent)
{
    label_film = new QLabel("Title");
    label_year = new QLabel("Year");
    label_rait = new QLabel("Rating");

    line_edit_film = new QLineEdit;
    line_edit_year = new QLineEdit;
    line_edit_rait = new QLineEdit;

    button_find = new QPushButton("&Search",this);
    button_reset = new QPushButton("&Clear",this);

    lay = new QHBoxLayout;
    lay->setMargin(10);

    lay->addWidget(label_film);
    lay->addWidget(line_edit_film);
    lay->addWidget(label_year);
    lay->addWidget(line_edit_year);
    lay->addWidget(label_rait);
    lay->addWidget(line_edit_rait);
    lay->addSpacing(75);
    lay->addWidget(button_find);
    lay->addWidget(button_reset);

    setLayout(lay);
}
