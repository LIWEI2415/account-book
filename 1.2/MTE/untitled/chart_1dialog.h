#ifndef CHART_1DIALOG_H
#define CHART_1DIALOG_H

#include <QDialog>

namespace Ui {
class chart_1Dialog;
}

class chart_1Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit chart_1Dialog(QWidget *parent = 0);
    ~chart_1Dialog();

private:
    Ui::chart_1Dialog *ui;
};

#endif // CHART_1DIALOG_H
