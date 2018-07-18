#ifndef CHART_2_1DIALOG_H
#define CHART_2_1DIALOG_H

#include <QDialog>

namespace Ui {
class chart_2_1Dialog;
}

class chart_2_1Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit chart_2_1Dialog(QWidget *parent = 0);
    ~chart_2_1Dialog();

private:
    Ui::chart_2_1Dialog *ui;
};

#endif // CHART_2_1DIALOG_H
