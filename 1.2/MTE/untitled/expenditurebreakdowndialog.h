#ifndef EXPENDITUREBREAKDOWNDIALOG_H
#define EXPENDITUREBREAKDOWNDIALOG_H

#include <QDialog>

namespace Ui {
class ExpenditureBreakdownDialog;
}

class ExpenditureBreakdownDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExpenditureBreakdownDialog(QWidget *parent = 0);
    ~ExpenditureBreakdownDialog();

private slots:
    void on_ButtonNewAccount_clicked();

    void on_ButtonFunctionOldthing_clicked();

    void on_pushButton_7_clicked();

    void on_ButtonFunctionMessage_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_ButtonExit_clicked();

    void on_pushButton_6_clicked();


    void on_pushButton_9_clicked();

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息

private:
    Ui::ExpenditureBreakdownDialog *ui;
};

#endif // EXPENDITUREBREAKDOWNDIALOG_H
