#include "mainwindow.h"

MainWindow::MainWindow()
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);

    setWindowTitle("Фигуры");

    area = new Area(ui->areaPlaceholder);
    QVBoxLayout *layout = new QVBoxLayout(ui->areaPlaceholder);
    layout->addWidget(area);

    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete area;
    delete ui;
}
