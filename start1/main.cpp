#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
     QApplication app(argc, argv);
    QFrame *frame = new QFrame;
       frame->setObjectName("myframe");
       frame->resize(400,700);
       frame->setStyleSheet("QFrame#myframe{border-image:url(images/登陆界面.png)}" );
       frame->show();
    return a.exec();
}
