#include "login.h"
#include "mainmenu.h"
#include "reg.h"
#include "ui_login.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "QVector"

QVector<qint64> aclineOffsets; // 账号位置索引
QVector<qint64> pwlineOffsets; // 密码位置索引

Widget::Widget(QWidget *parent) // 登录窗口
    : QWidget(parent) // 初始化窗口为所有窗口部件的基类
    , ui(new Ui::Widget) // 创建UI窗口
{
    ui->setupUi(this); // 打开窗口
    ui->le_password->setEchoMode(QLineEdit::Password); // 设定密码初始不可见
}

Widget::~Widget() // 设定关闭窗口事件
{
    delete ui;
}

void Widget::on_logButton_clicked() // 登录按钮按下事件
{
    int linenumber=0; // 索引行数编号，账密位置行一一对应
    QString appDir = QCoreApplication::applicationDirPath(); // 获取程序核心路径
    QString accountPath = appDir + "/filestorage/account.txt"; // 获取账号路径
    QString passwordPath = appDir + "/filestorage/password.txt"; // 获取密码路径
    QString tempPath = appDir + "/filestorage/temp.txt"; // 获取账号待显缓存文件
    QString account = ui->le_account->text() + "\n" ; // 获取账号输入框内内容
    QString password = ui->le_password->text() + "\n" ; // 获取密码输入框内内容
    QFile ac(accountPath); // 设定QFile对象用于访问账号存储文件
    QFile pw(passwordPath); // 设定QFile对象用于访问密码存储文件
    QFile tp(tempPath); // 设定QFile对象用于访问账号待显缓存文件
    QTextStream acin(&ac); // 设定账号存储文件文本传输流
    QTextStream pwin(&pw); // 设定密码存储文件文本传输流
    QTextStream tpout(&tp); // 设定账号待显缓存文件文本传输流
    tpout.setEncoding(QStringConverter::Utf8); // 设定编码格式为UTF-8防止乱码
    if (tp.open(QIODevice::WriteOnly | QIODevice::Text)) { // 打开账号待显缓存文件
        tpout << ui->le_account->text() ; // 假设用户存在且登录成功，提前设定主窗口所显示的用户名
    }
    tp.close(); // 关闭账号待显缓存文件
    if (!ac.open(QIODevice::ReadOnly | QIODevice::Text)) return; // 打开账号存储文件
    acin.setEncoding(QStringConverter::Utf8); // 设定编码格式为UTF-8防止乱码
    aclineOffsets.append(1); // 初始化索引
    pwlineOffsets.append(1); // 初始化索引
    if (!pw.open(QIODevice::ReadOnly | QIODevice::Text)) return; // 打开密码存储文件
    while (!pwin.atEnd()) { // 创建密码索引
        pwlineOffsets.append(pw.pos());
        pw.readLine();
    }
    pw.close(); // 关闭密码存储文件
    while (!acin.atEnd()) { // 创建账号索引并检测登录账密是否存在且对应
        aclineOffsets.append(ac.pos()); // 创建账号索引
        linenumber++;
        QString acline = ac.readLine();
        if (acline==account) { // 账号存在事件
            if (!pw.open(QIODevice::ReadOnly | QIODevice::Text)) return; // 再次打开密码存储文件
            pwin.setEncoding(QStringConverter::Utf8); // 设定编码格式为UTF-8防止乱码
            pwin.seek(pwlineOffsets[linenumber]); // 由于账密行号对应，直接跳转到对应位置检测密码是否一致
            QString pwline = pw.readLine(); // 获取密码信息
            if(pwline==password){ // 密码一致事件
                mainmenu *w=new mainmenu; // 设定主窗口对象
                w->show(); // 启动主窗口
                this->hide(); // 关闭登录窗口
                ac.close(); // 关闭账号存储文件
                pw.close(); // 关闭密码存储文件
                return;
            }
            if(pwline!=password){ // 密码不一致事件
                QMessageBox::information(this, "提示", "密码错误！"); // 提示用户密码错误
                ac.close(); // 关闭账号存储文件
                pw.close(); // 关闭密码存储文件
                return;
            }
        }
    }
    QMessageBox::information(this, "提示", "账户不存在！"); // 若账户存在事件未被触发则提示用户账户不存在
    ac.close(); // 关闭账号存储文件
    pw.close(); // 关闭密码存储文件
    return;
}

void Widget::on_regButton_clicked() // 注册按钮按下事件
{
    reg *w=new reg(); // 设定注册窗口对象
    w->show(); // 启动注册窗口
    this->hide(); // 关闭登录窗口
}

void Widget::on_exitButton_clicked() // 退出按钮按下事件
{
    this->close(); // 关闭登录窗口
}

void Widget::on_pw_show_clicked(bool checked) // 密码显示勾选框事件
{
    if(checked){ // 检查框是否被勾选
        ui->le_password->setEchoMode(QLineEdit::Normal); // 若勾选则显示密码
    }
    else{
        ui->le_password->setEchoMode(QLineEdit::Password); // 若未被勾选则不显示密码
    }
}
