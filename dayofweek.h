#ifndef DAYOFWEEK_H
#define DAYOFWEEK_H

#include <QObject>
#include <student.h>


class DayOfWeek
{
public:
    DayOfWeek(int dayOfWeek);
    int getDayOfWeek() const;
    void addStudent(Student* stu);
    QList<Student *> *getStudents() const;

private:
    int dayOfWeek;
    QList<Student*> *students;
};

#endif // DAYOFWEEK_H
