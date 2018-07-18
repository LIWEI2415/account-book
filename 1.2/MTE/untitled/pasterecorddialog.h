#ifndef PASTERECORDDIALOG_H
#define PASTERECORDDIALOG_H

#include <QDialog>

namespace Ui {
class PasteRecordDialog;
}

class PasteRecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PasteRecordDialog(QWidget *parent = 0);
    ~PasteRecordDialog();

private slots:
    void on_ButtonNewAccount_clicked();

    void on_pushButton_7_clicked();

    void on_ButtonFunctionMessage_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_ButtonExit_clicked();

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息

private:
    Ui::PasteRecordDialog *ui;
};

#endif // PASTERECORDDIALOG_H
