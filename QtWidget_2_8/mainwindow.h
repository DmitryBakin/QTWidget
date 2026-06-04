#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>

#include "ui_mainwindow.h"

class Counter : public QLineEdit
{
    Q_OBJECT

public:
    Counter(const QString &contents, QWidget *parent = nullptr)
        : QLineEdit(contents, parent)
    {
        setReadOnly(true);
    }

signals:
    void tick_signal();

public slots:
    void add_one()
    {
        QString str = text();
        int r = str.toInt();

        if (r != 0 && r % 5 == 0)
            emit tick_signal();

        r++;
        str.setNum(r);
        setText(str);
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    Counter *edit1;
    Counter *edit2;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
