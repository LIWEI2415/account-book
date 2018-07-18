#ifndef CHART_3_1DIALOG_H
#define CHART_3_1DIALOG_H

#include <QDialog>

namespace Ui {
class chart_3_1Dialog;
}

class chart_3_1Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit chart_3_1Dialog(QWidget *parent = 0);
    ~chart_3_1Dialog();

private:
    Ui::chart_3_1Dialog *ui;
};

#endif // CHART_3_1DIALOG_H
