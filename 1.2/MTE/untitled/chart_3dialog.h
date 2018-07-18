#ifndef CHART_3DIALOG_H
#define CHART_3DIALOG_H

#include <QDialog>

namespace Ui {
class chart_3Dialog;
}

class chart_3Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit chart_3Dialog(QWidget *parent = 0);
    ~chart_3Dialog();

private:
    Ui::chart_3Dialog *ui;
};

#endif // CHART_3DIALOG_H
