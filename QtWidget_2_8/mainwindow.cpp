#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);

    this->setWindowTitle("Счетчик");
    edit1 = new Counter("0", this);
    edit2 = new Counter("0", this);

    QHBoxLayout *countersRowLayout = new QHBoxLayout();
    countersRowLayout->addWidget(edit1);
    countersRowLayout->addWidget(edit2);
    ui->countersLayout->addLayout(countersRowLayout);

    connect(ui->calcButton, &QPushButton::clicked, edit1, &Counter::add_one);
    connect(edit1, &Counter::tick_signal, edit2, &Counter::add_one);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete edit1;
    delete edit2;
    delete ui;
}
