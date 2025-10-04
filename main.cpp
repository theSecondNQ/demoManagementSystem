#include "login.h"

#include <QApplication>
#include <QFile>
#include <QDir>

int main(int argc, char *argv[]) // App启动项
{
    QApplication a(argc, argv); // 设定App对象
    Widget w; // 设定窗口对象
    w.show(); // 显示登录窗口
    QString appDir = QCoreApplication::applicationDirPath(); // 获取程序核心路径
    QString dirPath = appDir + "/filestorage"; // 获取文件保存目录
    QString accountPath = appDir + "/filestorage/account.txt"; // 获取账号存储文件路径
    QString passwordPath = appDir + "/filestorage/password.txt"; // 获取密码存储文件路径
    QString tempPath = appDir + "/filestorage/temp.txt"; // 获取账号待显缓存文件
    QString dataPath = appDir + "/filestorage/data.txt"; // 获取数据存储文件
    QString logPath = appDir + "/filestorage/logs.txt";
    QFile ac(accountPath); // 创建QFile对象用于访问账号存储文件
    QFile pw(passwordPath); // 创建QFile对象用于访问密码存储文件
    QFile tp(tempPath); // 创建QFile对象用于访问账号待显缓存文件
    QFile dp(dataPath); // 创建QFile对象用于访问数据存储文件
    QFile lp(logPath);
    if ( !QDir(dirPath).exists() ) { // 检查文件夹是否存在，不存在则新建文件夹
        if ( !QDir().mkpath(dirPath) ) return 0;
    }
    if ( !ac.exists() ){  // 检查文件是否存在，不存在则创建新文件
        if( !ac.open(QIODevice::WriteOnly | QIODevice::Text) ) return 0;
        ac.close(); // 关闭账号存储文件
    }
    if ( !pw.exists() ){  // 检查文件是否存在，不存在则创建新文件
        if( !pw.open(QIODevice::WriteOnly | QIODevice::Text) ) return 0;
        pw.close(); // 关闭密码存储文件
    }
    if ( !tp.exists() ){  // 检查文件是否存在，不存在则创建新文件
        if( !tp.open(QIODevice::WriteOnly | QIODevice::Text) ) return 0;
        tp.close(); // 关闭账号待显缓存文件
    }
    if ( !dp.exists() ){  // 检查文件是否存在，不存在则创建新文件
        if( !dp.open(QIODevice::WriteOnly | QIODevice::Text) ) return 0;
        dp.close(); // 关闭数据存储文件
    }
    if ( !lp.exists() ){  // 检查文件是否存在，不存在则创建新文件
        if( !lp.open(QIODevice::WriteOnly | QIODevice::Text) ) return 0;
        lp.close(); // 关闭数据存储文件
    }
    return a.exec(); // 检测窗口是否被关闭并返回关闭或崩溃报告
}
