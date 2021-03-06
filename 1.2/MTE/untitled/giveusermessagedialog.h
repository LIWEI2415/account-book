#ifndef GIVEUSERMESSAGEDIALOG_H
#define GIVEUSERMESSAGEDIALOG_H

#include <QDialog>

namespace Ui {
class GiveUserMessageDialog;
}

class GiveUserMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GiveUserMessageDialog(QWidget *parent = 0);
    ~GiveUserMessageDialog();

private slots:
    void on_ButtonNewAccount_clicked();

    void on_ButtonFunctionOldthing_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_ButtonExit_clicked();

    void on_pushButton_6_clicked();

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息

private:
    Ui::GiveUserMessageDialog *ui;
};

#endif // GIVEUSERMESSAGEDIALOG_H
