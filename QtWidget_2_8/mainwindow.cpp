#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);

    codec = QTextCodec::codecForName("Windows-1251");
    setWindowTitle(codec->toUnicode("Счетчик"));

    // Создаем два счетчика
    edit1 = new Counter("0", ui->widgetCounters);
    edit2 = new Counter("0", ui->widgetCounters);

    // Находим layout внутри widgetCounters (он называется countersLayout)
    QLayout *layout = ui->widgetCounters->layout();
    if (layout) {
        // Добавляем счетчики горизонтально
        QHBoxLayout *hLayout = qobject_cast<QHBoxLayout*>(layout);
        if (!hLayout) {
            hLayout = new QHBoxLayout();
            delete layout;
            ui->widgetCounters->setLayout(hLayout);
        }
        hLayout->addWidget(edit1);
        hLayout->addWidget(edit2);
    }

    // Подключения сигналов и слотов
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
