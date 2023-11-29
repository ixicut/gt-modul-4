#include <QMenu>
#include <QAction>
#include <QListWidget>
#include "custom_film_list_widget.h"

CustomFilmListWidget::CustomFilmListWidget(QWidget* parent) : QListWidget(parent) {}

void CustomFilmListWidget::contextMenuEvent(QContextMenuEvent* event)
{
    QMenu contextMenu(this);

    QAction* action1 = contextMenu.addAction("Action 1");
    QAction* action2 = contextMenu.addAction("Action 2");

    //connect(action1, &QAction::triggered, this, &CustomFilmListWidget::customAction1);
    //connect(action2, &QAction::triggered, this, &CustomFilmListWidget::customAction2);

    contextMenu.exec(event->globalPos());
}
