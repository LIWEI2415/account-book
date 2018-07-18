#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QSound>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    QSystemTrayIcon *mSysTrayIcon;
    QMenu *mMenu;
    QAction *mShowMainAction;
    QAction *mExitAppAction;

public:
    void createActions();
    void createMenu();

private slots:
    void on_ButtonNewAccount_clicked();

    void on_pushButton_7_clicked();

    void on_ButtonFunctionOldthing_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_ButtonFunctionMessage_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void receivelogin();//与login发射的信号相关的槽函数

    void on_pushButton_10_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
    void on_showMainAction();
    void on_exitAppAction();

    void on_pushButton_13_clicked();

signals:
    void dlgshow();//显示登录对话框信号

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
