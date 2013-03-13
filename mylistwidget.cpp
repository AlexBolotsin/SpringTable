#include "mylistwidget.h"
#include <QDragMoveEvent>

MyListWidget::MyListWidget(QWidget *parent)
    : QListWidget(parent)
{
}

void MyListWidget::dragMoveEvent(QDragMoveEvent* event) {
    if (event->source() != this) {
        event->accept();
    } else {
        event->ignore();
    }
}
