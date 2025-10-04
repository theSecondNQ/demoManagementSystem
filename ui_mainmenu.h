/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainmenu
{
public:
    QCommandLinkButton *bt_add;
    QCommandLinkButton *bt_del;
    QLineEdit *le_name;
    QComboBox *sw_fmale;
    QLineEdit *le_class;
    QLineEdit *le_num;
    QLineEdit *le_pro;
    QCommandLinkButton *bt_src;
    QTableWidget *tableWidget;
    QCommandLinkButton *bt_save;
    QCommandLinkButton *bt_switch;
    QLabel *title_image;
    QLabel *welcome;
    QLabel *user_name;
    QCommandLinkButton *bt_showall;
    QLabel *time;
    QLabel *label;
    QLabel *label_2;
    QLabel *count;
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_3;
    QCommandLinkButton *bt_logsrc;

    void setupUi(QWidget *mainmenu)
    {
        if (mainmenu->objectName().isEmpty())
            mainmenu->setObjectName("mainmenu");
        mainmenu->resize(1060, 600);
        mainmenu->setMinimumSize(QSize(1060, 600));
        mainmenu->setMaximumSize(QSize(1060, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/app_icon.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        mainmenu->setWindowIcon(icon);
        mainmenu->setStyleSheet(QString::fromUtf8(""));
        bt_add = new QCommandLinkButton(mainmenu);
        bt_add->setObjectName("bt_add");
        bt_add->setGeometry(QRect(10, 170, 231, 51));
        bt_add->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::FolderNew));
        bt_add->setIcon(icon1);
        bt_del = new QCommandLinkButton(mainmenu);
        bt_del->setObjectName("bt_del");
        bt_del->setGeometry(QRect(10, 230, 231, 51));
        bt_del->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        bt_del->setIcon(icon2);
        le_name = new QLineEdit(mainmenu);
        le_name->setObjectName("le_name");
        le_name->setGeometry(QRect(330, 50, 221, 25));
        sw_fmale = new QComboBox(mainmenu);
        sw_fmale->addItem(QString());
        sw_fmale->addItem(QString());
        sw_fmale->addItem(QString());
        sw_fmale->setObjectName("sw_fmale");
        sw_fmale->setGeometry(QRect(570, 50, 83, 25));
        le_class = new QLineEdit(mainmenu);
        le_class->setObjectName("le_class");
        le_class->setGeometry(QRect(670, 50, 113, 25));
        le_num = new QLineEdit(mainmenu);
        le_num->setObjectName("le_num");
        le_num->setGeometry(QRect(800, 50, 113, 25));
        le_pro = new QLineEdit(mainmenu);
        le_pro->setObjectName("le_pro");
        le_pro->setGeometry(QRect(930, 50, 113, 25));
        bt_src = new QCommandLinkButton(mainmenu);
        bt_src->setObjectName("bt_src");
        bt_src->setGeometry(QRect(290, 40, 31, 41));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        bt_src->setIcon(icon3);
        tableWidget = new QTableWidget(mainmenu);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(319, 103, 701, 471));
        tableWidget->horizontalHeader()->setDefaultSectionSize(140);
        bt_save = new QCommandLinkButton(mainmenu);
        bt_save->setObjectName("bt_save");
        bt_save->setGeometry(QRect(10, 290, 231, 51));
        bt_save->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("document-save")));
        bt_save->setIcon(icon4);
        bt_switch = new QCommandLinkButton(mainmenu);
        bt_switch->setObjectName("bt_switch");
        bt_switch->setGeometry(QRect(10, 540, 231, 51));
        bt_switch->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::UserAvailable));
        bt_switch->setIcon(icon5);
        title_image = new QLabel(mainmenu);
        title_image->setObjectName("title_image");
        title_image->setGeometry(QRect(10, 10, 61, 61));
        title_image->setStyleSheet(QString::fromUtf8("border-image: url(:/app_icon.ico);"));
        welcome = new QLabel(mainmenu);
        welcome->setObjectName("welcome");
        welcome->setGeometry(QRect(80, 10, 71, 31));
        user_name = new QLabel(mainmenu);
        user_name->setObjectName("user_name");
        user_name->setGeometry(QRect(80, 40, 121, 41));
        bt_showall = new QCommandLinkButton(mainmenu);
        bt_showall->setObjectName("bt_showall");
        bt_showall->setGeometry(QRect(10, 350, 231, 51));
        bt_showall->setToolTipDuration(-6);
        bt_showall->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::FormatJustifyLeft));
        bt_showall->setIcon(icon6);
        time = new QLabel(mainmenu);
        time->setObjectName("time");
        time->setGeometry(QRect(10, 80, 261, 51));
        label = new QLabel(mainmenu);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 75, 69, 19));
        label_2 = new QLabel(mainmenu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(300, 10, 91, 31));
        count = new QLabel(mainmenu);
        count->setObjectName("count");
        count->setGeometry(QRect(350, 10, 91, 31));
        widget = new QWidget(mainmenu);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-1, -1, 1061, 611));
        widget->setStyleSheet(QString::fromUtf8("border-image: url(:/bg.jpg);"));
        widget_2 = new QWidget(mainmenu);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 291, 601));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        widget_3 = new QWidget(mainmenu);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(291, -1, 778, 81));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgba(222, 220, 219, 100); background-color: rgba(206, 247, 255, 100);"));
        bt_logsrc = new QCommandLinkButton(mainmenu);
        bt_logsrc->setObjectName("bt_logsrc");
        bt_logsrc->setGeometry(QRect(10, 410, 231, 51));
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::EditPaste));
        bt_logsrc->setIcon(icon7);
        widget->raise();
        tableWidget->raise();
        widget_2->raise();
        bt_add->raise();
        bt_del->raise();
        bt_save->raise();
        bt_showall->raise();
        bt_switch->raise();
        label->raise();
        time->raise();
        title_image->raise();
        welcome->raise();
        user_name->raise();
        widget_3->raise();
        count->raise();
        label_2->raise();
        le_class->raise();
        le_name->raise();
        le_num->raise();
        le_pro->raise();
        sw_fmale->raise();
        bt_src->raise();
        bt_logsrc->raise();

        retranslateUi(mainmenu);

        QMetaObject::connectSlotsByName(mainmenu);
    } // setupUi

    void retranslateUi(QWidget *mainmenu)
    {
        mainmenu->setWindowTitle(QCoreApplication::translate("mainmenu", "\346\226\260\350\211\276\345\210\251\351\203\275\346\225\231\350\202\262\345\261\200\345\255\246\347\224\237\350\257\201\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        bt_add->setText(QCoreApplication::translate("mainmenu", "\346\267\273\345\212\240\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
        bt_del->setText(QCoreApplication::translate("mainmenu", "\345\210\240\351\231\244\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
        sw_fmale->setItemText(0, QCoreApplication::translate("mainmenu", "\347\251\272", nullptr));
        sw_fmale->setItemText(1, QCoreApplication::translate("mainmenu", "\347\224\267", nullptr));
        sw_fmale->setItemText(2, QCoreApplication::translate("mainmenu", "\345\245\263", nullptr));

        bt_src->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("mainmenu", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("mainmenu", "\346\200\247\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("mainmenu", "\347\217\255\347\272\247", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("mainmenu", "\345\255\246\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("mainmenu", "\344\270\223\344\270\232", nullptr));
        bt_save->setText(QCoreApplication::translate("mainmenu", "\344\277\235\345\255\230\344\277\256\346\224\271", nullptr));
        bt_switch->setText(QCoreApplication::translate("mainmenu", "\345\210\207\346\215\242\350\264\246\345\217\267", nullptr));
        title_image->setText(QString());
        welcome->setText(QCoreApplication::translate("mainmenu", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">\346\202\250\345\245\275\357\274\201</span></p></body></html>", nullptr));
        user_name->setText(QCoreApplication::translate("mainmenu", "<html><head/><body><p><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", nullptr));
        bt_showall->setText(QCoreApplication::translate("mainmenu", "\346\230\276\347\244\272\345\205\250\351\203\250", nullptr));
        time->setText(QCoreApplication::translate("mainmenu", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; text-decoration: underline;\">TextLabel</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("mainmenu", "\347\216\260\345\234\250\346\230\257", nullptr));
        label_2->setText(QCoreApplication::translate("mainmenu", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">\346\200\273\346\225\260\357\274\232</span></p></body></html>", nullptr));
        count->setText(QCoreApplication::translate("mainmenu", "<html><head/><body><p><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", nullptr));
        bt_logsrc->setText(QCoreApplication::translate("mainmenu", "\346\227\245\345\277\227\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainmenu: public Ui_mainmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
