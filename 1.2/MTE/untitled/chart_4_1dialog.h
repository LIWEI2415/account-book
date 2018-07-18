#ifndef CHART_4_1DIALOG_H
#define CHART_4_1DIALOG_H

#include <QDialog>

namespace Ui {
class chart_4_1Dialog;
}

class chart_4_1Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit chart_4_1Dialog(QWidget *parent = 0);
    ~chart_4_1Dialog();

private:
    Ui::chart_4_1Dialog *ui;
};

#endif // CHART_4_1DIALOG_H
