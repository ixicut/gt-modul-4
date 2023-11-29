#ifndef CUSTOMFILMLISTWIDGET_H
#define CUSTOMFILMLISTWIDGET_H

#include <QListWidget>
#include <QContextMenuEvent>

class CustomFilmListWidget : public QListWidget
{
    Q_OBJECT

public:
    CustomFilmListWidget(QWidget* parent = nullptr);

protected:
    void contextMenuEvent(QContextMenuEvent* event) override;
};

#endif // CUSTOMFILMLISTWIDGET_H
