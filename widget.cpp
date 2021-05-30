#include "widget.h"

Widget::Widget(SearchTree<int>* searchTree, QWidget* parent) : QWidget(parent), searchTree()
{
    this->searchTree = searchTree;
    node = QColor(168, 168, 129);
    background = QColor(235, 235, 235);
    text = QColor(71, 98, 68);
}

void Widget::rePaint()
{
    if(searchTree->empty())
    {
        return;
    }
    this->update();
}

QSize Widget::sizeHint() const
{
    return QSize(50, 50);
}
QSize Widget::minimumSizeHint() const
{
    return QSize(50, 50);
}

void Widget::paintEvent(QPaintEvent* event)
{
    if (!searchTree->empty())
    {
        QPainter painter(this);
        QBrush brush;
        brush.setColor(node);
        brush.setStyle(Qt::SolidPattern);
        QPen pen;
        pen.setColor(text);
        painter.setBrush(brush);
        painter.setPen(pen);
        searchTree->draw(&painter);
        Size();
    }
}

void Widget::Size() {
    QSize size(searchTree->getTotalX(), searchTree->getTotalY());
    setMinimumSize(size);
    resize(size);
}
