#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);

    codec = QTextCodec::codecForName("Windows-1251");
    setWindowTitle("Squaring");

    StrValidator *v = new StrValidator(ui->inputEdit);
    ui->inputEdit->setValidator(v);

    begin();

    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->nextButton, &QPushButton::clicked, this, &MainWindow::begin);
    connect(ui->inputEdit, &QLineEdit::returnPressed, this, &MainWindow::calc);
}

void MainWindow::begin()
{
    ui->inputEdit->clear();
    ui->nextButton->setEnabled(false);
    ui->nextButton->setDefault(false);
    ui->inputEdit->setEnabled(true);
    ui->outputLabel->setVisible(false);
    ui->outputEdit->setVisible(false);
    ui->outputEdit->setEnabled(false);
    ui->inputEdit->setFocus();
}

void MainWindow::calc()
{
    bool Ok = true;
    float r, a;
    QString str = ui->inputEdit->text();
    a = str.toDouble(&Ok);

    if (Ok)
    {
        r = a * a;
        str.setNum(r);
        ui->outputEdit->setText(str);
        ui->inputEdit->setEnabled(false);
        ui->outputLabel->setVisible(true);
        ui->outputEdit->setVisible(true);
        ui->nextButton->setDefault(true);
        ui->nextButton->setEnabled(true);
        ui->nextButton->setFocus();
    }
    else if (!str.isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Information,
                           "Squaring",
                           "Invalid value entered.",
                           QMessageBox::Ok);
        msgBox.exec();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
