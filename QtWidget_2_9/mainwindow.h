#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "area.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QTextCodec *codec;
    Area *area;

public:
    MainWindow();
    ~MainWindow();
};

#endif // MAINWINDOW_H
