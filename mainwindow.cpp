#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parser = new DataParser("data.csv");
    parser->readFile();
    QMap<QString,double> map;
    foreach(const Student *stu,this->parser->getAllStudents())
    {
        map.insert(stu->getName(),stu->getHoursIn());
    }
    sortedPeople = map.keys();
    sortedHours = map.values();

    qDebug()<<"Done reading log";
    setUpPeoplePlot();
    setUpDayPlot();
    setUpPeopleList();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete parser;
}

void MainWindow::setUpPeoplePlot()
{
    QCPBars *bars = new QCPBars(ui->peopleGraph->xAxis,ui->peopleGraph->yAxis);
    ui->peopleGraph->addPlottable(bars);
    QVector<double> ticks;
    QVector<QString> labels;
    QVector<double> hours;
    for(int i =0;i<sortedPeople.size();i++)
    {
        ticks << i+1;
        labels << sortedPeople.at(i);
        hours << sortedHours.at(i);
    }
    ui->peopleGraph->xAxis->setAutoTicks(false);
    ui->peopleGraph->xAxis->setAutoTickLabels(false);
    ui->peopleGraph->xAxis->setTickVector(ticks);
    ui->peopleGraph->xAxis->setTickVectorLabels(labels);
    ui->peopleGraph->xAxis->setTickLabelRotation(90);
    ui->peopleGraph->xAxis->setSubTickCount(0);
    ui->peopleGraph->xAxis->setTickLength(0, 4);
    ui->peopleGraph->xAxis->grid()->setVisible(true);
    ui->peopleGraph->xAxis->setRange(0, this->parser->getAllStudents().size()+1);

    ui->peopleGraph->yAxis->setRange(0,16);
    ui->peopleGraph->yAxis->setPadding(20);
    bars->setData(ticks,hours);
    ui->peopleGraph->replot();
}

void MainWindow::setUpDayPlot()
{
    QCPBars *bars = new QCPBars(ui->dayGraph->xAxis,ui->dayGraph->yAxis);
    ui->dayGraph->addPlottable(bars);
    QVector<double> ticks;
    QVector<QString> labels;
    QVector<double> people;
    for(int i =0;i<7;i++)
    {
        ticks << i;
        people << this->parser->getDays().at(i)->getStudents()->size();
    }
    labels << "Mon" << "Tue" << "Wed" << "Thur" << "Fri" << "Sat" << "Sun";
    ui->dayGraph->xAxis->setAutoTicks(false);
    ui->dayGraph->xAxis->setAutoTickLabels(false);
    ui->dayGraph->xAxis->setTickVector(ticks);
    ui->dayGraph->xAxis->setTickVectorLabels(labels);
    ui->dayGraph->xAxis->setTickLabelRotation(90);
    ui->dayGraph->xAxis->setSubTickCount(0);
    ui->dayGraph->xAxis->setTickLength(0, 4);
    ui->dayGraph->xAxis->grid()->setVisible(true);
    ui->dayGraph->xAxis->setRange(0,7);

    ui->dayGraph->yAxis->setRange(0,16);
    ui->dayGraph->yAxis->setPadding(20);
    bars->setData(ticks,people);
    ui->dayGraph->replot();
}

void MainWindow::setUpPeopleList()
{
    ui->peopleTable->setRowCount(this->sortedPeople.size());
    ui->peopleTable->setColumnCount(2);
    for(int i =0;i<this->sortedPeople.size();i++)
    {
        QTableWidgetItem *name = new QTableWidgetItem(this->sortedPeople.at(i));

        QTableWidgetItem *hours = new QTableWidgetItem(QString::number(this->sortedHours.at(i)));
        ui->peopleTable->setItem(i,0,name);
        ui->peopleTable->setItem(i,1,hours);
    }
}


