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
QDateTime Student::getLastSignIn() const
{
    return lastSignIn;
}

void Student::setLastSignIn(const QDateTime &value)
{
    lastSignIn = value;
}
QDateTime Student::getLastSignOut() const
{
    return lastSignOut;
}

void Student::setLastSignOut(const QDateTime &value)
{
    lastSignOut = value;
}




