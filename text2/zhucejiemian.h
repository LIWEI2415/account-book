#ifndef ZHUCEJIEMIAN_H
#define ZHUCEJIEMIAN_H

#include <QDialog>

namespace Ui {
class zhucejiemian;
}

class zhucejiemian : public QDialog
{
    Q_OBJECT

public:
    explicit zhucejiemian(QWidget *parent = 0);
    ~zhucejiemian();

private:
    Ui::zhucejiemian *ui;
};

#endif // ZHUCEJIEMIAN_H
