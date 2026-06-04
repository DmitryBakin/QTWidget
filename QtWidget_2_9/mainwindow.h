#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "area.h"


class MainWindow : public QWidget
{
    Q_OBJECT

protected:
    Area * area;
    QPushButton * exitButton;


public:
    MainWindow(QWidget *parent = nullptr);
};

#endif // MAINWINDOW_H
