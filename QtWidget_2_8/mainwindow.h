#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>

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

class MainWindow : public QWidget
{
    Q_OBJECT
protected:
    QLabel *label1,*label2;
    Counter *edit1,*edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
