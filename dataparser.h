#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <QFile>
#include <QDebug>
#include <student.h>
#include <dayofweek.h>
class DataParser
{
public:
    DataParser(QString filename);
    ~DataParser();
    void readFile();

    QList<Student *> getAllStudents() const;
private:
    QFile *file;
    QList<Student *> allStudents;
    QList<DayOfWeek *> days;
    void processLine(QString name, QString time, QString inOut, QString date);
};

#endif // DATAPARSER_H
