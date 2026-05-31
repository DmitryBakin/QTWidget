#ifndef AREA_H
#define AREA_H

#include <QtWidgets>
#include "figura.h"

class Area : public QWidget
{
    Q_OBJECT

private:
    int myTimer;
    float alpha;

public:
    MyLine *myline;
    MyRect *myrect;

    Area(QWidget *parent = nullptr);
    ~Area();

protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
};

#endif // AREA_H
