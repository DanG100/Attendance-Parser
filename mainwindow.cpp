#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DataParser parser("data.csv");
    parser.readFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}


