#ifndef ADDRECOUNTDIALOG_H
#define ADDRECOUNTDIALOG_H

#include <QDialog>

namespace Ui {
class AddRecountDialog;
}

class AddRecountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecountDialog(QWidget *parent = 0);
    ~AddRecountDialog();

private slots:
    void on_ComeBackMain_clicked();

    void on_ButtonFunctionOldthing_clicked();

    void on_ButtonFunctionMessage_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_btnSaveQuit_3_clicked();

    void on_ButtonExit_clicked();
 //   void on_pushButton_7_clicked();

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息

private:
    Ui::AddRecountDialog *ui;
};

#endif // ADDRECOUNTDIALOG_H
