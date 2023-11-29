#include <QMenu>
#include <QAction>
#include "custom_film_list_widget.h"

CustomFilmListWidget::CustomFilmListWidget(QWidget* parent)
    : QListWidget(parent) {}

void CustomFilmListWidget::contextMenuEvent(QContextMenuEvent* event)
{
    QListWidgetItem* selectedItem = itemAt(event->pos());
    if (selectedItem) {
        QMenu contextMenu(this);

        QAction* addToLocalAction = contextMenu.addAction("Add to Local Database");
        connect(addToLocalAction, &QAction::triggered, this, &CustomFilmListWidget::addToLocalDataBaseSlot);

        contextMenu.exec(event->globalPos());
    }
}

void CustomFilmListWidget::addToLocalDataBaseSlot()
{

}
