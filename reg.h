#ifndef REG_H
#define REG_H

#include <QWidget>

namespace Ui {
class reg;
}

class reg : public QWidget
{
    Q_OBJECT

public:
    explicit reg(QWidget *parent = nullptr);
    ~reg();

private slots:
    void on_bt_finish_clicked();

    void on_bt_exit_clicked();

private:
    Ui::reg *ui;
};

#endif // REG_H
