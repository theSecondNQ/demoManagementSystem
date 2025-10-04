#include "reg.h"
#include "login.h"
#include "ui_reg.h"
#include "qstring.h"
#include "qmessagebox.h"
#include "qfile.h"
#include "QTextStream"
#include "QDebug"
#include "QCoreApplication"

reg::reg(QWidget *parent) // 注册窗口
    : QWidget(parent) // 初始化窗口为所有窗口部件的基类
    , ui(new Ui::reg) // 创建UI窗口
{
    ui->setupUi(this); // 打开窗口
}

reg::~reg() // 设定关闭窗口事件
{
    delete ui;
}

void reg::on_bt_finish_clicked() // 注册完成事件
{
    int flag=0; // 设定异常状态
    QString account = ui->le_account->text(); // 获取用户名
    QString password = ui->le_password->text(); // 获取密码
    QString cpw = ui->le_pasw_c->text(); // 获取确认密码
    if (account.isEmpty()) { // 判断用户名是否为空
        flag++; // 报错
        QMessageBox::information(this, "提示", "请输入账号！"); // 提示用户
    }
    if (password.isEmpty() && flag==0){ // 判断密码是否为空且是否处于异常状态
        flag++; // 报错
        QMessageBox::information(this, "提示", "请输入密码！"); // 提示用户
    }
    if (cpw.isEmpty() && flag==0){ // 判断确认密码是否为空且是否处于异常状态
        flag++; // 报错
        QMessageBox::information(this, "提示", "请再次确认密码！"); // 提示用户
    }
    if (password!=cpw){ // 判断密码与确认密码是否不相同
        flag++; // 报错
        QMessageBox::information(this, "提示", "密码不相同！"); // 提示用户
    }
    if (!account.isEmpty() && !password.isEmpty() && !cpw.isEmpty() && flag==0){ // 确认所有状态正常
        QString appDir = QCoreApplication::applicationDirPath(); // 获取程序核心路径
        QString accountPath = appDir + "/filestorage/account.txt"; // 获取账号存储文件路径
        QString passwordPath = appDir + "/filestorage/password.txt"; // 获取密码存储文件路径
        QFile ac(accountPath); // 设定QFile对象用于访问账号存储文件
        QFile pw(passwordPath); // 设定QFile对象用于访问密码存储文件
        QTextStream acin(&ac); // 创建文本传输流
        if (!ac.open(QIODevice::ReadOnly | QIODevice::Text)) return; // 以只读模式打开账号存储文件
        acin.setEncoding(QStringConverter::Utf8); // 设定编码为UTF-8防止乱码
        while (!acin.atEnd()) { // 遍历账号并判断账号是否已被注册
            QString acline = acin.readLine(); // 读取当前行
            if (acline==account) { // 判断当前账号是否已被注册
                QMessageBox::information(this, "提示", "该账号已注册！"); // 提示用户
                ac.close(); // 关闭账号存储文件
                return; // 中断函数
            }
        }
        ac.close(); // 关闭账号存储文件
        if ((ac.open(QIODevice::Append | QIODevice::Text)) && (pw.open(QIODevice::Append | QIODevice::Text))) { // 以追加模式打开账号存储文件和密码存储文件注册新账号
            QTextStream acout(&ac); // 创建文本传输流
            QTextStream pwout(&pw); // 创建文本传输流
            acout.setEncoding(QStringConverter::Utf8); // 设定编码为UTF-8防止乱码
            pwout.setEncoding(QStringConverter::Utf8); // 设定编码为UTF-8防止乱码
            acout << account << "\n" ; // 追加新账号
            pwout << password << "\n" ; // 追加新密码
            ac.close(); // 关闭账号存储文件
            pw.close(); // 关闭密码存储文件
            QMessageBox::information(this, "成功", "账密已保存！"); // 提示用户
        }
        Widget *w=new Widget(); // 创建登录窗口对象
        w->show(); // 启动登录窗口
        this->hide(); // 关闭注册窗口
    }
}

void reg::on_bt_exit_clicked() // 退出事件
{
    Widget *w=new Widget(); // 创建登录窗口对象
    w->show(); // 启动登录窗口
    this->hide(); // 关闭注册窗口
}
