#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QColor>
#include "SearchTree.h"

class Widget : public QWidget
{
     Q_OBJECT
public:
    Widget(SearchTree<int>* searchTree, QWidget *parent = nullptr);

public:
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void Size();
    void rePaint();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    SearchTree<int> *searchTree;
    QPen pen;
    QBrush brush;
    QColor background;
    QColor node;
    QColor text;
};

#endif // WIDGET_H
