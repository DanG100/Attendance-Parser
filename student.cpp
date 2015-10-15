#include "student.h"

Student::Student()
{

}
QString Student::getName() const
{
    return name;
}

void Student::setName(const QString &value)
{
    name = value;
}


