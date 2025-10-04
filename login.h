#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_logButton_clicked();

    void on_regButton_clicked();

    void on_exitButton_clicked();

    void on_pw_show_clicked(bool checked);

private:
    Ui::Widget *ui;
};
#endif // LOGIN_H
