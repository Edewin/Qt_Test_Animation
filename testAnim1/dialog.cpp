#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    /***************
    FILE
    */
    file = new QFile("timer_Rands2.csv");

    if(! file->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        return;
    }

    ButtonState = false;

    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    bluePen = new QPen(Qt::blue);

    redBrush = new QBrush(Qt::red);

    radialGradient = new QRadialGradient(50,50,100);

    radialGradient->setColorAt(0.0, Qt::darkGreen );
    radialGradient->setColorAt(0.5, Qt::darkRed );
    radialGradient->setColorAt(1.0, Qt::darkYellow);

    greenBrush = new QBrush(*radialGradient);

    //greenBrush->setColor(Qt::green);


    rect = new QRect(0,0,200,300);


    item = scene->addRect(*rect, *bluePen, *redBrush);



    ellipse = scene->addEllipse(0,0,100,100, *bluePen, *greenBrush);

    scene->addEllipse(100,100,100,100, *bluePen, *greenBrush);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    timer->start(40);


}

Dialog::~Dialog()
{
    file->close();
    delete ui;
}

void Dialog::update()
{
    //angle = qrand() % 360;



    //try to open file for Read/Write -> Text Mode



    angle += 5;

    item->setRotation( angle );

    rand1 = qrand() % 500;
    rand2 = (qrand() % 500) - 500;

    stringData.sprintf("Current time: %d - %d - %d,rand1 = %f,rand2 = %f\n",
                       time->hour(),time->minute(),time->second(),rand1,rand2);
    file->write(stringData.toLatin1());

    qDebug() << rand1;
    qDebug() << rand2;




}

void Dialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(Qt::darkMagenta);
    painter.setFont(QFont("Arial",30));
    painter.drawText(*rect,Qt::AlignCenter,"Qt");
}

void Dialog::on_pushButton_clicked()
{
   if(ButtonState == false)
   {
       ButtonState = true;

       item->setFlag(QGraphicsItem::ItemIsMovable, true);

       item->setPos(((qrand() % 500)-500),((qrand() % 500)-500));

       item->setVisible(true);
   }
   else
   {
       ButtonState = false;

       item->setFlag(QGraphicsItem::ItemIsMovable, false);

       item->setVisible(false);
       //rect->moveTo(0,0);
   }

}
