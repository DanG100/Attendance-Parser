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
    this->students->append(stu);
}


