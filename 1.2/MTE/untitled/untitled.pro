#-------------------------------------------------
#
# Project created by QtCreator 2018-07-06T22:01:42
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT +=multimedia
RC_ICONS += myapp.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport


TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    loginindialog.cpp \
    newloginindialog.cpp \
    addrecountdialog.cpp \
    pasterecorddialog.cpp \
    pasterecordusingdialog.cpp \
    incomeclassificationdialog.cpp \
    expenditurebreakdowndialog.cpp \
    pasterecordgettingdialog.cpp \
    giveusermessagedialog.cpp \
    sickeverydaydialog.cpp \
    showeverythingsdialog.cpp \
    qcustomplot.cpp \
    chart_1dialog.cpp \
    chart_2dialog.cpp \
    chart_3dialog.cpp \
    chart_4dialog.cpp \
    chart_1_1dialog.cpp \
    chart_2_1dialog.cpp \
    chart_3_1dialog.cpp \
    chart_4_1dialog.cpp

HEADERS += \
        mainwindow.h \
    loginindialog.h \
    newloginindialog.h \
    addrecountdialog.h \
    pasterecorddialog.h \
    pasterecordusingdialog.h \
    incomeclassificationdialog.h \
    expenditurebreakdowndialog.h \
    pasterecordgettingdialog.h \
    giveusermessagedialog.h \
    sickeverydaydialog.h \
    showeverythingsdialog.h \
    qcustomplot.h \
    chart_1dialog.h \
    chart_2dialog.h \
    chart_3dialog.h \
    chart_4dialog.h \
    chart_1_1dialog.h \
    chart_2_1dialog.h \
    chart_3_1dialog.h \
    chart_4_1dialog.h

FORMS += \
        mainwindow.ui \
    loginindialog.ui \
    newloginindialog.ui \
    addrecountdialog.ui \
    pasterecorddialog.ui \
    pasterecordusingdialog.ui \
    incomeclassificationdialog.ui \
    expenditurebreakdowndialog.ui \
    pasterecordgettingdialog.ui \
    giveusermessagedialog.ui \
    sickeverydaydialog.ui \
    showeverythingsdialog.ui \
    chart_1dialog.ui \
    chart_2dialog.ui \
    chart_3dialog.ui \
    chart_4dialog.ui \
    chart_1_1dialog.ui \
    chart_2_1dialog.ui \
    chart_3_1dialog.ui \
    chart_4_1dialog.ui

RESOURCES += \
    resource.qrc
