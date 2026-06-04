#ifndef FIGURA_H
#define FIGURA_H

#include <QtWidgets>

class Figura
{
protected:
    int x, y;        // центр
    int halflen;     // половина длины
    int dx, dy;      // смещение
    virtual void draw(QPainter *Painter) = 0;

public:
    Figura(int X, int Y, int Halflen) : x(X), y(Y), halflen(Halflen) {}
    virtual ~Figura() {}
    void move(float Alpha, QPainter *Painter);
};

class MyLine : public Figura
{
protected:
    void draw(QPainter *Painter) override;

public:
    MyLine(int x, int y, int halflen) : Figura(x, y, halflen) {}
};

class MyRect : public Figura
{
protected:
    void draw(QPainter *Painter) override;

public:
    MyRect(int x, int y, int halflen) : Figura(x, y, halflen) {}
};

#endif // FIGURA_H
