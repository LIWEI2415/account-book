#include "chart_3_1dialog.h"
#include "ui_chart_3_1dialog.h"
#include"qcustomplot.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>

chart_3_1Dialog::chart_3_1Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chart_3_1Dialog)
{
    ui->setupUi(this);
    //执行相关sql语句
    QSqlQuery sql_query;
    sql_query.exec("SELECT * FROM PIN;");

    int Account[3]={0,0,0};
    sql_query.first();
        while(sql_query.next())
        {
            if(sql_query.value(1).toString()=="薪水津贴")    Account[0]=Account[0]+sql_query.value(6).toInt();
            else if(sql_query.value(1).toString()=="红包礼金")    Account[1]=Account[1]+sql_query.value(6).toInt();
            else if(sql_query.value(1).toString()=="生意买卖")    Account[2]=Account[2]+sql_query.value(6).toInt();
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

    fossil->setName("金额");
    fossil->setPen(QPen(QColor(255,0,0).lighter(170)));
    fossil->setBrush(QColor(255,0,0));
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 ;
    labels << "薪水津贴" << "红包礼金" << "生意买卖" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(45);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 4);
    customPlot->xAxis->setBasePen(QPen(Qt::white));
    customPlot->xAxis->setTickPen(QPen(Qt::white));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->setLabelColor(Qt::white);
    customPlot->yAxis->setRange(0, 2000);
    customPlot->yAxis->setPadding(100); // a bit more space to the left border
    customPlot->yAxis->setLabel("收入类型");
    customPlot->yAxis->setBasePen(QPen(Qt::white));
    customPlot->yAxis->setTickPen(QPen(Qt::white));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(Qt::white);
    customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    QVector<double> fossilData;
    fossilData  << Account[0] <<Account[1] << Account[2];
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

chart_3_1Dialog::~chart_3_1Dialog()
{
    delete ui;
}
