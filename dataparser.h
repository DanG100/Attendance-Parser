#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <QFile>
#include <QDebug>

class DataParser
{
public:
    DataParser(QString filename);
    ~DataParser();
    void readFile();
private:
    QFile *file;
};

#endif // DATAPARSER_H
