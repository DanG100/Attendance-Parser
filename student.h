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

private:
    QString name;
    QDateTime lastSignIn;
    QDateTime lastSignOut;
};

#endif // STUDENT_H
