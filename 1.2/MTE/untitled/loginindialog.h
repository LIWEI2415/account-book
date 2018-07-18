#ifndef LOGININDIALOG_H
#define LOGININDIALOG_H

#include <QDialog>

namespace Ui {
class LogininDialog;
}

class LogininDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogininDialog(QWidget *parent = 0);
    ~LogininDialog();

private slots:
    void on_btnLogin_clicked();

    void on_pushButton_clicked();

    void receiveshow();

signals:
    void showmainwindow();//显示主窗口界面

private:
    Ui::LogininDialog *ui;
};

#endif // LOGININDIALOG_H
