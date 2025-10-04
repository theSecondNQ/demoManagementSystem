/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *logButton;
    QPushButton *regButton;
    QPushButton *exitButton;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *le_account;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *le_password;
    QCheckBox *pw_show;
    QWidget *widget;
    QWidget *widget_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(392, 300);
        Widget->setMinimumSize(QSize(392, 300));
        Widget->setMaximumSize(QSize(392, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/app_icon.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Widget->setWindowIcon(icon);
        Widget->setAutoFillBackground(true);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 50, 321, 101));
        label->setTextFormat(Qt::TextFormat::AutoText);
        label->setScaledContents(false);
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 20, 61, 61));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/app_icon.ico);"));
        logButton = new QPushButton(Widget);
        logButton->setObjectName("logButton");
        logButton->setGeometry(QRect(260, 240, 93, 28));
        regButton = new QPushButton(Widget);
        regButton->setObjectName("regButton");
        regButton->setGeometry(QRect(150, 240, 93, 28));
        exitButton = new QPushButton(Widget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(40, 240, 93, 28));
        horizontalWidget = new QWidget(Widget);
        horizontalWidget->setObjectName("horizontalWidget");
        horizontalWidget->setGeometry(QRect(40, 130, 291, 41));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        label_3 = new QLabel(horizontalWidget);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        le_account = new QLineEdit(horizontalWidget);
        le_account->setObjectName("le_account");

        horizontalLayout->addWidget(le_account);

        le_account->raise();
        label_3->raise();
        horizontalWidget_2 = new QWidget(Widget);
        horizontalWidget_2->setObjectName("horizontalWidget_2");
        horizontalWidget_2->setGeometry(QRect(40, 180, 291, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(horizontalWidget_2);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        le_password = new QLineEdit(horizontalWidget_2);
        le_password->setObjectName("le_password");

        horizontalLayout_2->addWidget(le_password);

        pw_show = new QCheckBox(Widget);
        pw_show->setObjectName("pw_show");
        pw_show->setGeometry(QRect(340, 193, 16, 16));
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-11, -10, 441, 331));
        widget->setStyleSheet(QString::fromUtf8("border-image: url(:/bg1.jpg);"));
        widget_2 = new QWidget(Widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(-1, -1, 401, 301));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        widget->raise();
        widget_2->raise();
        horizontalWidget_2->raise();
        label->raise();
        label_2->raise();
        logButton->raise();
        regButton->raise();
        pw_show->raise();
        exitButton->raise();
        horizontalWidget->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\226\260\350\211\276\345\210\251\351\203\275\346\225\231\350\202\262\345\261\200\345\255\246\347\224\237\350\257\201\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", nullptr));
        label_2->setText(QString());
        logButton->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        regButton->setText(QCoreApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
        exitButton->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\350\264\246\345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
        pw_show->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
