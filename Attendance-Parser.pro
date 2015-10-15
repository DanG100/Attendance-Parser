#-------------------------------------------------
#
# Project created by QtCreator 2015-10-15T14:47:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Attendance-Parser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dataparser.cpp \
    student.cpp \
    dayofweek.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    dataparser.h \
    student.h \
    dayofweek.h \
    qcustomplot.h

FORMS    += mainwindow.ui
