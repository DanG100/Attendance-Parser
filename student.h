#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student
{
public:
    Student();
    QString getName() const;
    void setName(const QString &value);

private:
    QString name;
};

#endif // STUDENT_H
