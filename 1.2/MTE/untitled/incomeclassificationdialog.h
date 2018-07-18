#ifndef INCOMECLASSIFICATIONDIALOG_H
#define INCOMECLASSIFICATIONDIALOG_H

#include <QDialog>

namespace Ui {
class IncomeClassificationDialog;
}

class IncomeClassificationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IncomeClassificationDialog(QWidget *parent = 0);
    ~IncomeClassificationDialog();

private slots:
    void on_ButtonNewAccount_clicked();

    void on_ButtonFunctionOldthing_2_clicked();

    void on_pushButton_9_clicked();

    void on_ButtonFunctionMessage_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_ButtonExit_2_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_7_clicked();

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息

private:
    Ui::IncomeClassificationDialog *ui;
};

#endif // INCOMECLASSIFICATIONDIALOG_H
