#ifndef CHART_4DIALOG_H
#define CHART_4DIALOG_H

#include <QDialog>

namespace Ui {
class chart_4Dialog;
}

class chart_4Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit chart_4Dialog(QWidget *parent = 0);
    ~chart_4Dialog();

private:
    Ui::chart_4Dialog *ui;
};

#endif // CHART_4DIALOG_H
