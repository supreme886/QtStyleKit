#include "mainwindow.h"
#include "button.h"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QSK::Button *btn = new QSK::Button;
    btn->setText("this is btn");
    btn->setFixedWidth(100);

    QWidget *main = new QWidget;
    QHBoxLayout *main_layout = new QHBoxLayout(main);

    main_layout->addWidget(btn);

    setCentralWidget(main);
}

MainWindow::~MainWindow() {}
