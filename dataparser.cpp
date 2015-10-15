#include "dataparser.h"

DataParser::DataParser(QString filename)
{
    this->file = new QFile(filename);
    if(!this->file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Can't open file";
    }
}
DataParser::~DataParser()
{

}

void DataParser::readFile()
{
    QTextStream in(file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QString name = line.section(',',0,0);
        QString time = line.section(',',1,1);
        QString inOut = line.section(',',2,2);
        QString data = line.section(',',3,3);
    }
}
