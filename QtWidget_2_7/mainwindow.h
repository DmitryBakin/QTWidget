#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>



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

class MainWindow : public QWidget
{
    Q_OBJECT
protected:
    QFrame *frame;
    QLabel *inputLabel;
    QLineEdit *inputEdit;
    QLabel *outputLabel;
    QLineEdit *outputEdit;
    QPushButton *nextButton;
    QPushButton *exitButton;
private:

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void begin();
    void calc();
};

#endif
