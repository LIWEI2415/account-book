#include "chart_1_1dialog.h"
#include "ui_chart_1_1dialog.h"
#include"qcustomplot.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>
chart_1_1Dialog::chart_1_1Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chart_1_1Dialog)
{
    ui->setupUi(this);

    //执行相关sql语句
    QSqlQuery sql_query;
    sql_query.exec("SELECT * FROM PIN;");
    int Year=2018,Month=1;
    int Account[12]={0,0,0,0,0,0,0,0,0,0,0,0},number=0;
    while(Month<13)
    {
        sql_query.first();
        while(sql_query.next())
        {
        int Y1 = sql_query.value(2).toInt();
        int M1 = sql_query.value(3).toInt();
        if(Y1==Year && Month==M1)
          {
             Account[number]=Account[number]+sql_query.value(6).toInt();
          }
        }
        number=number+1;
        Month=Month+1;
    }


    QCustomPlot *customPlot=new QCustomPlot(this);
    customPlot->resize(790,510);
    QLinearGradient gradient(0,0,0,400);
    gradient.setColorAt(0,QColor(90,90,90));
    gradient.setColorAt(0.38,QColor(105,105,105));
    gradient.setColorAt(1,QColor(70,70,70));
    customPlot->setBackground(QBrush(gradient));
    QCPGraph *fossil = new QCPGraph(customPlot->xAxis, customPlot->yAxis);
    fossil->setAntialiased(false);

    fossil->setName("月收入");
    fossil->setPen(QPen(QColor(111,9,176).lighter(170)));
    fossil->setBrush(QColor(111,9,176));
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7<<8<<9<<10<<11<<12;
    labels << "一月" << "二月" << "三月" << "四月" << "五月" << "六月" << "七月"<<"八月"<<"九月"<<"十月"<<"十一月"<<"十二月";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(20);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 13);
    customPlot->xAxis->setBasePen(QPen(Qt::white));
    customPlot->xAxis->setTickPen(QPen(Qt::white));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->setLabelColor(Qt::white);
    customPlot->yAxis->setRange(0, 2000);
    customPlot->yAxis->setPadding(100); // a bit more space to the left border
    customPlot->yAxis->setLabel("本年收入");
    customPlot->yAxis->setBasePen(QPen(Qt::white));
    customPlot->yAxis->setTickPen(QPen(Qt::white));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(Qt::white);
    customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    QVector<double> fossilData;
    fossilData  << Account[0] <<Account[1] << Account[2]<<Account[3] << Account[4]<< Account[5] << Account[6]<<Account[7]<<Account[8]<<Account[9]<<Account[10]<<Account[11];
    fossil->setData(ticks, fossilData);
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

chart_1_1Dialog::~chart_1_1Dialog()
{
    delete ui;
}
