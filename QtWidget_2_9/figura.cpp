#include "figura.h"
#include <cmath>

// Метод move вычисляет смещение по углу Alpha и вызывает draw
void Figura::move(float Alpha, QPainter *Painter)
{
    dx = halflen * cos(Alpha);
    dy = halflen * sin(Alpha);
    draw(Painter);
}

// Рисование линии: от (x+dx, y+dy) до (x-dx, y-dy)
void MyLine::draw(QPainter *Painter)
{
    Painter->drawLine(x + dx, y + dy, x - dx, y - dy);
}

// Рисование квадрата: 4 стороны, повёрнутые на угол Alpha
void MyRect::draw(QPainter *Painter)
{
    Painter->drawLine(x + dx, y + dy, x + dy, y - dx);
    Painter->drawLine(x + dy, y - dx, x - dx, y - dy);
    Painter->drawLine(x - dx, y - dy, x - dy, y + dx);
    Painter->drawLine(x - dy, y + dx, x + dx, y + dy);
}
