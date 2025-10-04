/********************************************************************************
** Form generated from reading UI file 'reg.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REG_H
#define UI_REG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reg
{
public:
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *le_account;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *le_password;
    QWidget *horizontalWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *le_pasw_c;
    QPushButton *bt_finish;
    QPushButton *bt_exit;
    QWidget *widget;
    QWidget *widget_2;

    void setupUi(QWidget *reg)
    {
        if (reg->objectName().isEmpty())
            reg->setObjectName("reg");
        reg->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/app_icon.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        reg->setWindowIcon(icon);
        horizontalWidget = new QWidget(reg);
        horizontalWidget->setObjectName("horizontalWidget");
        horizontalWidget->setGeometry(QRect(30, 50, 321, 41));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        label_3 = new QLabel(horizontalWidget);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        le_account = new QLineEdit(horizontalWidget);
        le_account->setObjectName("le_account");

        horizontalLayout->addWidget(le_account);

        horizontalWidget_2 = new QWidget(reg);
        horizontalWidget_2->setObjectName("horizontalWidget_2");
        horizontalWidget_2->setGeometry(QRect(30, 110, 321, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(horizontalWidget_2);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        le_password = new QLineEdit(horizontalWidget_2);
        le_password->setObjectName("le_password");

        horizontalLayout_2->addWidget(le_password);

        horizontalWidget_3 = new QWidget(reg);
        horizontalWidget_3->setObjectName("horizontalWidget_3");
        horizontalWidget_3->setGeometry(QRect(30, 170, 321, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(horizontalWidget_3);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        le_pasw_c = new QLineEdit(horizontalWidget_3);
        le_pasw_c->setObjectName("le_pasw_c");

        horizontalLayout_3->addWidget(le_pasw_c);

        bt_finish = new QPushButton(reg);
        bt_finish->setObjectName("bt_finish");
        bt_finish->setGeometry(QRect(220, 240, 93, 28));
        bt_exit = new QPushButton(reg);
        bt_exit->setObjectName("bt_exit");
        bt_exit->setGeometry(QRect(80, 240, 93, 28));
        widget = new QWidget(reg);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-11, -10, 441, 331));
        widget->setStyleSheet(QString::fromUtf8("border-image: url(:/bg1.jpg);"));
        widget_2 = new QWidget(reg);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(-10, -1, 411, 301));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        widget->raise();
        widget_2->raise();
        bt_exit->raise();
        bt_finish->raise();
        horizontalWidget->raise();
        horizontalWidget_2->raise();
        horizontalWidget_3->raise();

        retranslateUi(reg);

        QMetaObject::connectSlotsByName(reg);
    } // setupUi

    void retranslateUi(QWidget *reg)
    {
        reg->setWindowTitle(QCoreApplication::translate("reg", "\346\263\250\345\206\214", nullptr));
        label_3->setText(QCoreApplication::translate("reg", "\350\264\246       \345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("reg", "\345\257\206       \347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("reg", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        bt_finish->setText(QCoreApplication::translate("reg", "\345\256\214\346\210\220", nullptr));
        bt_exit->setText(QCoreApplication::translate("reg", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reg: public Ui_reg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REG_H
