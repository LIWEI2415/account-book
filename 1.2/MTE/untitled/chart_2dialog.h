#ifndef CHART_2DIALOG_H
#define CHART_2DIALOG_H

#include <QDialog>

namespace Ui {
class chart_2Dialog;
}

class chart_2Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit chart_2Dialog(QWidget *parent = 0);
    ~chart_2Dialog();

private:
    Ui::chart_2Dialog *ui;
};

#endif // CHART_2DIALOG_H
