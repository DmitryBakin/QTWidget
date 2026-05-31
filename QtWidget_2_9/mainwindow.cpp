#include "mainwindow.h"

MainWindow::MainWindow()
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);

    setWindowTitle("Figures");

    area = new Area(ui->areaPlaceholder);
    QVBoxLayout *layout = new QVBoxLayout(ui->areaPlaceholder);
    layout->addWidget(area);
    layout->setContentsMargins(0, 0, 0, 0);

    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete area;
    delete ui;
}
