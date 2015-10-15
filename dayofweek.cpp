#include "dayofweek.h"

DayOfWeek::DayOfWeek(int dayOfWeek)
{
    this->dayOfWeek = dayOfWeek;
    this->students = new QList<Student*>();
}
int DayOfWeek::getDayOfWeek() const
{
    return dayOfWeek;
}
void DayOfWeek::addStudent(Student *stu)
{
    bool alreadySignedIn = false;
    for(int i = 0;i<students->size();i++)
    {
        if(stu->getName()==this->students->at(i)->getName())
            alreadySignedIn = true;
    }
    if(!alreadySignedIn)
        this->students->append(stu);
}


