#ifndef NEWLOGININDIALOG_H
#define NEWLOGININDIALOG_H

#include <QDialog>

namespace Ui {
class NewLogininDialog;
}

class NewLogininDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewLogininDialog(QWidget *parent = 0);
    ~NewLogininDialog();

private slots:
    void on_btnLogin_clicked();

    void on_btnExit_clicked();

private:
    Ui::NewLogininDialog *ui;
};

#endif // NEWLOGININDIALOG_H
