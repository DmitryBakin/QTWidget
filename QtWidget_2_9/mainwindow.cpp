#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("Фигуры");

    area = new Area( this );
    exitButton = new QPushButton("Завершить",this );
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(exitButton);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::close);
}
