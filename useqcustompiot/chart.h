#ifndef CHART_H
#define CHART_H

#include <QDialog>

namespace Ui {
class chart;
}

class chart : public QDialog
{
    Q_OBJECT

public:
    explicit chart(QWidget *parent = 0);
    ~chart();

private:
    Ui::chart *ui;
};

#endif // CHART_H
