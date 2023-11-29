#include "my_model.h"

MyModel::MyModel(){}

Qt::ItemFlags MyModel::flags ( const QModelIndex & index ) const
{
   if (index.column() == 3) return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
   else return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}
