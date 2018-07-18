#ifndef SHOWEVERYTHINGSDIALOG_H
#define SHOWEVERYTHINGSDIALOG_H

#include <QDialog>

namespace Ui {
class ShowEveryThingsDialog;
}

class ShowEveryThingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowEveryThingsDialog(QWidget *parent = 0);
    ~ShowEveryThingsDialog();

private slots:
    void on_ComeBackMain_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_ButtonFunctionOldthing_clicked();

    void on_pushButton_7_clicked();

    void on_ButtonFunctionMessage_clicked();

    void on_ButtonExit_clicked();

    void on_btnEditAccounter_3_clicked();

    void on_btnCancle_3_clicked();

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息

private:
    Ui::ShowEveryThingsDialog *ui;

  //  MainWindow* pMainWindow;
};

#endif // SHOWEVERYTHINGSDIALOG_H
