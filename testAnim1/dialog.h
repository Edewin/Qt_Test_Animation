#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

#include <QRadialGradient>

#include <QDateTime>
#include <QTime>

#include <QDebug>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();





private slots:
    void on_pushButton_clicked();
    void update();

protected:
    void paintEvent(QPaintEvent *);
private:
    Ui::Dialog *ui;

    QGraphicsScene *scene;

    QGraphicsItem *item;
    QGraphicsItem *ellipse;

    QGraphicsRectItem *rectItem;

    QRadialGradient *radialGradient;

    QTimer *timer;

    QPen *bluePen;

    QBrush *redBrush;

    QBrush *greenBrush;

    QRect *rect;

    //File variables
    QFile *file;

    QString stringData;
    QDate *date;
    QTime *time;
    QDateTime *dateTime;
    qreal rand1, rand2;


    bool ButtonState;

    qreal angle;


};

#endif // DIALOG_H
