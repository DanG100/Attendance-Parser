#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <student.h>
#include <dataparser.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    void setUpPeoplePlot();
    void setUpDayPlot();
    DataParser *parser;

};

#endif // MAINWINDOW_H
