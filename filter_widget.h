#ifndef FILTER_WIDGET_H
#define FILTER_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include<QPushButton>
#include<QComboBox>
#include<QHBoxLayout>

class FilterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FilterWidget(QWidget *parent = nullptr);
    QLabel* label_film;
    QLabel* label_year;
    QLabel* label_rait;

    QLineEdit* line_edit_film;
    QLineEdit* line_edit_year;
    QLineEdit* line_edit_rait;

    QPushButton* button_find;
    QPushButton* button_reset;

    QHBoxLayout* lay;
};

#endif // FILTER_WIDGET_H
