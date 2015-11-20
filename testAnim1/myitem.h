#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class MyItem : public QGraphicsItem
{
public:
    MyItem();

    //pure virtual functions of QGraphicsItem
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);



signals:

public slots:
};

#endif // MYITEM_H
