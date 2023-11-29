#ifndef MY_MODEL_H
#define MY_MODEL_H
#include <QSqlTableModel>
#include <QWidget>

class MyModel : public QSqlTableModel
{
public:
    MyModel();
    Qt::ItemFlags flags(const QModelIndex &index) const;
};

#endif // MY_MODEL_H
