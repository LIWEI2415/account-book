#ifndef PASTERECORDUSINGDIALOG_H
#define PASTERECORDUSINGDIALOG_H

#include <QDialog>

namespace Ui {
class PasteRecordUsingDialog;
}

class PasteRecordUsingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PasteRecordUsingDialog(QWidget *parent = 0);
    ~PasteRecordUsingDialog();

private slots:
    void on_ButtonNewAccount_clicked();

    void on_ButtonFunctionOldthing_clicked();

    void on_pushButton_7_clicked();

    void on_ButtonFunctionMessage_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_ButtonExit_clicked();

    void on_pushButton_6_clicked();


    void on_pushButton_9_clicked();

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息

private:
    Ui::PasteRecordUsingDialog *ui;
};

#endif // PASTERECORDUSINGDIALOG_H
