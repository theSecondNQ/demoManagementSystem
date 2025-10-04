#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QString>
#include <QPushButton>

namespace Ui {
class mainmenu;
}

class mainmenu : public QWidget
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

private slots:
    void on_bt_save_clicked();

    void on_bt_add_clicked();

    void on_bt_del_clicked();

    void on_bt_src_clicked();

    void on_bt_switch_clicked();

    void on_bt_showall_clicked();

    void on_bt_logsrc_clicked();

private:
    Ui::mainmenu *ui;
    void loadFile();
    void updateLineIndex();
    void updateTime();
    void update(int count);
    int checkState();
};

#endif // MAINMENU_H
