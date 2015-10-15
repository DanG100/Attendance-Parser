#ifndef DATAPARSER_H
#define DATAPARSER_H
#include <QFile>

class DataParser
{
public:
    DataParser(QFile datafile);
    int readFile();
private:
    QFile file;
    void readLine();
};

#endif // DATAPARSER_H
