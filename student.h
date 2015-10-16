#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QDateTime>
class Student
{
public:
    Student();
    QString getName() const;
    void setName(const QString &value);

    QDateTime getLastSignIn() const;
    void setLastSignIn(const QDateTime &value);

    QDateTime getLastSignOut() const;
    void setLastSignOut(const QDateTime &value);

    double getHoursIn() const;
    void increaseHoursIn(double value);
    bool operator <(const Student& other) const;
private:
    QString name;
    QDateTime lastSignIn;
    QDateTime lastSignOut;
    double hoursIn;
};

#endif // STUDENT_H
