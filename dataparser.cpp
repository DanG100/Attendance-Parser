#include "dataparser.h"

DataParser::DataParser(QString filename)
{
    this->file = new QFile(filename);
    if(!this->file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Can't open file";
    }
    for(int i = 1;i<=7;i++)
    {
        this->days.append(new DayOfWeek(i));
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
        QString date = line.section(',',3,3);
        this->processLine(name,time,inOut,date);//should be moved to new thread later
    }
}

void DataParser::processLine(QString name, QString time, QString inOut, QString date)
{
    Student *stu = NULL;

    for(int i = 0;i<allStudents.size();i++)
    {
        if(name==this->allStudents.at(i)->getName())
        {
            stu = this->allStudents.at(i);
        }
    }
    if(stu==NULL)
    {
        stu = new Student();
        this->allStudents.append(stu);
    }
    stu->setName(name);

    if(inOut=="Sign In")
    {
        QDateTime signIn(QDate::fromString(date),QTime::fromString(time));
        stu->setLastSignIn(signIn);
    }
    else
    {
        QDateTime signOut(QDate::fromString(date),QTime::fromString(time));
        stu->setLastSignOut(signOut);
        processSignOut(stu);

    }
}

void DataParser::processSignOut(Student *student)
{
    if(student->getLastSignIn().date()==student->getLastSignOut().date())
    {
        student->increaseHoursIn(student->getLastSignIn().time().secsTo(student->getLastSignOut().time())/3600.);
    }
    if(student->getLastSignIn().time().secsTo(student->getLastSignOut().time())>90*60)
        days.at(student->getLastSignOut().date().dayOfWeek()-1)->addStudent(student);
}
QList<Student *> DataParser::getAllStudents() const
{
    return allStudents;
}
QList<DayOfWeek *> DataParser::getDays() const
{
    return days;
}

