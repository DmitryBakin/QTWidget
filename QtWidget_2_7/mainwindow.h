#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>

#include "ui_mainwindow.h"



class StrValidator : public QValidator
{
    Q_OBJECT
public:
    StrValidator(QObject *parent = nullptr) : QValidator(parent) {}
    virtual State validate(QString &str, int &pos) const override
    {;
        return Acceptable;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void begin();
    void calc();
};

#endif
