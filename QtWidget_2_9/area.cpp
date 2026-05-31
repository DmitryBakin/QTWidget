#include "area.h"

Area::Area(QWidget *parent) : QWidget(parent)
{
    setFixedSize(300, 200);
    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::white);
    setPalette(pal);

    myline = new MyLine(80, 100, 50);
    myrect = new MyRect(220, 100, 50);
    alpha = 0;
}

void Area::showEvent(QShowEvent *)
{
    myTimer = startTimer(50);
}

void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer);
}

void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer)
    {
        alpha += 0.1;
        update();
    }
    else
    {
        QWidget::timerEvent(event);
    }
}

void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(QPen(Qt::red, 2));
    myline->move(alpha, &painter);

    painter.setPen(QPen(Qt::blue, 2));
    myrect->move(-0.5f * alpha, &painter);
}

Area::~Area()
{
    delete myline;
    delete myrect;
}
