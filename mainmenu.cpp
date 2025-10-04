#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "login.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QHeaderView>
#include <QCoreApplication>
#include <QInputDialog>
#include <QTimer>
#include <QDateTime>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QDialog>

int linenumber=0; // 行号
bool preventState=0; // 修改保存状态
QString appDir; // 程序核心路径
QString dataPath; // 数据存储文件路径
QString tempPath; // 账号待显缓存文件路径
QString logPath;
QString username;
QString timeText;

mainmenu::mainmenu(QWidget *parent) // 主界面窗口
    : QWidget(parent) // 初始化窗口为所有窗口部件的基类
    , ui(new Ui::mainmenu) // 创建UI窗口
{
    appDir = QCoreApplication::applicationDirPath(); // 获取程序核心路径
    dataPath = appDir + "/filestorage/data.txt"; // 获取数据存储文件路径
    tempPath = appDir + "/filestorage/temp.txt"; // 获取账号待显缓存文件路径
    logPath = appDir + "/filestorage/logs.txt";
    QTimer *timer; // 定义计时器对象
    ui->setupUi(this); // 打开主界面窗口
    QStringList headers = {"姓名", "性别", "班级", "学号", "专业"}; // 初始化表头
    ui->tableWidget->setColumnCount(5); // 设定列数
    ui->tableWidget->setHorizontalHeaderLabels(headers); // 设定表头显示内容
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 使表头平铺铺满显示
    loadFile(); // 加载数据
    updateLineIndex(); // 更新行号
    timer = new QTimer(this); // 启动计时器
    connect(timer, &QTimer::timeout, this, &mainmenu::updateTime); // 关联时间日期显示与计时器及主界面，使倒计时完毕时调用时间更新函数
    timer->start(1000); // 设定更新间隔
    updateTime(); // 调用时间更新函数
    update(linenumber); // 更新数据总量
}

mainmenu::~mainmenu() // 设定关闭窗口事件
{
    delete ui;
}

void mainmenu::updateLineIndex(){ // 行号更新函数
    QFile file(dataPath); // 设定QFile对象用于访问数据存储文件
    linenumber=0; // 初始化行号
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) { // 只读数据文件
        QTextStream in(&file); // 创建文本传输流
        while (!in.atEnd()) { // 遍历数据并更新行号
            in.readLine();
            linenumber++;
        }
        file.close(); // 关闭数据存储文件
    }
    return;
}

void mainmenu::loadFile(){ // 数据读取函数
    QFile file(dataPath); // 设定QFile对象用于访问数据存储文件
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) { // 以只读模式打开文件
        return;
    }
    QTextStream in(&file); // 创建文本传输流
    in.setEncoding(QStringConverter::Utf8); // 设定编码为UTF-8防止乱码
    ui->tableWidget->setRowCount(0); // 初始化行计数器
    int row = 0; // 初始化行计数
    while (!in.atEnd()) { // 将数据内容投放到表格上显示
        QString line = in.readLine().trimmed(); // 逐行读取并过滤空格
        if (line.isEmpty()) continue; // 检查当前行是否为空
        QStringList parts = line.split("&"); // 读取以&为分隔符的数据并拆成5份读取到字符串队列中
        if (parts.size() != 5) continue; // 检测数据是否为5份
        ui->tableWidget->insertRow(row); // 创建新行
        for (int col = 0; col < 5; ++col) { // 投放数据
            QTableWidgetItem *item = new QTableWidgetItem(parts[col]); // 设定行列内容对象
            ui->tableWidget->setItem(row, col, item); // 投放数据至对象中以显示
        }
        row++; // 行数递增
    }
    QFile tp(tempPath); // 设定QFile对象用于访问账号待显缓存文件
    QTextStream tpin(&tp); // 创建文本传输流
    tpin.setEncoding(QStringConverter::Utf8); // 设定编码为UTF-8防止乱码
    if (tp.open(QIODevice::ReadOnly | QIODevice::Text)) { // 以只读模式打开账号待显缓存文件
        username = tpin.readAll(); // 读取已登录用户名
        ui->user_name->setText(username); // 显示已登录用户名
        ui->user_name->setStyleSheet("font-size: 16px;"); // 设定文本大小为16
        tp.close(); // 关闭账号待显缓存文件
    }
    file.close(); // 关闭数据存储文件
}

void mainmenu::on_bt_save_clicked() // 保存修改事件
{
    QFile file(dataPath); // 设定QFile对象用于访问数据存储文件
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) { // 以覆写模式打开数据存储文件
        return;
    }
    QFile log(logPath);
    QTextStream out(&file); // 创建文本传输流
    out.setEncoding(QStringConverter::Utf8); // 设定编码为UTF-8防止乱码
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) { // 遍历表格数据并放入字符串队列内
        QStringList rowData; // 设定字符串队列存储每行所有数据
        for (int col = 0; col < 5; ++col) { // 遍历当前行数据
            QTableWidgetItem *item = ui->tableWidget->item(row, col); // 设定行列内容对象
            rowData << (item ? item->text() : ""); // 判断当前行列内内容是否为空并投放内容至字符串队列内
            if(rowData.contains("&")){ // 判断用户是否将分隔符放进内容内
                QMessageBox::information(this, "提示", "请保存正确的内容！"); // 提示用户
                preventState=1; // 设定状态为未保存
                return; // 中断函数
            }
        }
        out << rowData.join("&") << "\n"; // 将当前表格所有数据覆写至文件内
    }
    file.close(); // 关闭数据存储文件
    if (!log.open(QIODevice::Append | QIODevice::Text)) {
        return;
    }
    QTextStream logout(&log);
    logout.setEncoding(QStringConverter::Utf8);
    logout << timeText << " " << username << " 修改了数据" << "\n" ;
    log.close();
    QMessageBox::information(this, "成功", "文件已保存！"); // 提示用户
    preventState=0; // 设定状态为已保存
    loadFile(); // 重新读取数据并更新表格
}

void mainmenu::on_bt_add_clicked() // 新增数据事件
{
    if(checkState()==1){ // 检测文件是否处于已保存状态
        return;
    }
    QFile file(dataPath); // 设定QFile对象用于访问数据存储文件
    QFile log(logPath);
    if (file.open(QIODevice::Append | QIODevice::Text)) { // 以追加模式打开数据存储文件
        QTextStream out(&file); // 创建文本输出流
        out.setEncoding(QStringConverter::Utf8); // 设定编码为UTF-8防止乱码
        out << "请输入姓名&请输入性别&请输入班级&请输入学号&请输入专业\n" ; // 追加新用户并留待用户修改
        file.close(); // 关闭数据存储文件
    }
    if (!log.open(QIODevice::Append | QIODevice::Text)) {
        return;
    }
    QTextStream logout(&log);
    logout.setEncoding(QStringConverter::Utf8);
    logout << timeText << " " << username << " 新增了一项数据" << "\n" ;
    log.close();
    loadFile(); // 重新读取数据并更新表格
    updateLineIndex(); // 更新行号
    update(linenumber); // 更新数据总量
}

void mainmenu::on_bt_del_clicked() // 删除数据事件
{
    if(checkState()==1){ // 检测文件是否处于已保存状态
        return;
    }
    QFile file(dataPath); // 设定QFile对象用于访问数据存储文件
    QFile log(logPath);
    QTextStream in(&file); // 创建文本传输流
    QStringList temp; // 创建字符串队列用以暂存数据
    in.setEncoding(QStringConverter::Utf8); // 设定编码为UTF-8格式防止乱码
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) { // 以只读模式打开数据存储文件
        while (!in.atEnd()) { // 逐行遍历
            temp.append(in.readLine()); // 整行读取存储
        }
        file.close(); // 关闭数据存储文件
    }
    bool ok; // 设定布尔值用于创建确认和取消按钮
    int targetLN = QInputDialog::getInt( // 获取行号并用QInputDialog创建窗口便于用户输入所删除行号且限定行号范围防止用户输入有误
        this, // 设定在主界面上创建窗口
        "删除学生数据", // 设定标题
        QString("请输入行号 (1-%1):").arg(linenumber), // 告知用户行号范围
        1, // 设定默认值
        1, // 设定最小值
        linenumber, // 设定最大值
        1, // 设定步长
        &ok // 创建确认和取消按钮
    );
    if (!ok) return; // 获取布尔值以确认用户的确认和取消操作
    temp.removeAt(targetLN-1); // 移除目标行
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) { // 以覆写模式打开数据存储文件
        QTextStream out(&file); // 创建文本传输流
        out.setEncoding(QStringConverter::Utf8); // 设定编码为UTF-8防止乱码
        foreach (const QString &line, temp) { // 遍历字符串队列
            out << line << "\n"; // 将修改过的数据覆写至文件内
        }
    }
    if (!log.open(QIODevice::Append | QIODevice::Text)) {
        return;
    }
    QTextStream logout(&log);
    logout.setEncoding(QStringConverter::Utf8);
    logout << timeText << " " << username << " 删除了一项数据" << "\n" ;
    log.close();
    loadFile(); // 重新读取数据并更新表格
    updateLineIndex(); // 更新行号
    update(linenumber); // 更新数据总量
}

void mainmenu::on_bt_src_clicked() // 搜索事件
{
    if(checkState()==1){ // 检测文件是否处于已保存状态
        return;
    }
    int count = linenumber; // 获取总行数
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) { // 初始化数据显示状态
        ui->tableWidget->setRowHidden(row, false);
    }
    QString name = ui->le_name->text(); // 获取用户想搜索的名字内容
    QString sex = ui->sw_fmale->currentText(); // 获取用户想搜索的性别
    if(sex=="空"){ // 如果性别为空则将字符串设为空
        sex="";
    }
    QString Class = ui->le_class->text(); // 获取用户想搜索的班级内容
    QString num = ui->le_num->text(); // 获取用户想搜索的学号内容
    QString pro = ui->le_pro->text(); // 获取用户想搜索的专业内容
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) { // 遍历所有数据
        QString np = ui->tableWidget->item(row,0)->text(); // 获取当前行学生姓名
        QString sp = ui->tableWidget->item(row,1)->text(); // 获取当前行学生性别
        QString cp = ui->tableWidget->item(row,2)->text(); // 获取当前行学生班级
        QString nup = ui->tableWidget->item(row,3)->text(); // 获取当前行学生学号
        QString pp = ui->tableWidget->item(row,4)->text(); // 获取当前行学生专业
        if( !np.contains(name) || !sp.contains(sex) || !cp.contains(Class) || !nup.contains(num) || !pp.contains(pro) ){ // 判断当前行学生数据是否不包含所要搜索的数据
            ui->tableWidget->setRowHidden(row, true); // 隐藏当前行
            count--; // 总行数递减
        }
    }
    update(count); // 更新学生总量
}

void mainmenu::on_bt_switch_clicked() // 切换账号事件
{
    if(checkState()==1){ // 检测文件是否处于已保存状态
        return;
    }
    Widget *w=new Widget(); // 设定登录窗口对象
    w->show(); // 启动登录窗口
    this->close(); // 关闭主界面
}

void mainmenu::on_bt_showall_clicked() // 显示全部数据事件
{
    if(checkState()==1){ // 检测文件是否处于已保存状态
        return;
    }
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) { // 遍历所有行
        ui->tableWidget->setRowHidden(row, false); // 显示当前行
    }
    update(ui->tableWidget->rowCount()); // 更新学生总量
}

void mainmenu::on_bt_logsrc_clicked()
{
    QFile log(logPath);
    if (!log.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream login(&log);
    login.setEncoding(QStringConverter::Utf8);
    QString logs;
    while (!login.atEnd()) {
        logs += login.readLine() + "\n";
    }
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("日志内容");
    dialog->resize(600, 400);
    QTextEdit *textEdit = new QTextEdit(dialog);
    textEdit->setPlainText(logs);
    textEdit->setReadOnly(true);
    textEdit->setFont(QFont("Consolas", 12));
    textEdit->setStyleSheet("background-color: #f0f0f0;");
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(textEdit);
    dialog->setLayout(layout);
    dialog->show();
    log.close();
}

void mainmenu::updateTime(){ // 日期时间更新函数
    QFont font; // 设定文本格式对象
    font.setPixelSize(24); // 设定文本大小为24
    font.setBold(true); // 启用粗体
    font.setUnderline(true); // 启用下划线
    QDateTime currentTime = QDateTime::currentDateTime(); // 获取当前日期时间
    timeText = currentTime.toString("yyyy-MM-dd hh:mm:ss"); // 将日期时间转换为字符串
    ui->time->setText(timeText); // 显示当前日期时间
    ui->time->setFont(font); // 设定文本格式
}

void mainmenu::update(int count){ // 学生总量更新函数
    QFont font; // 设定文本格式对象
    font.setPixelSize(16); // 设定文本大小为16
    ui->count->setText(QString::number(count)); // 显示当前学生总量
    ui->count->setFont(font); // 设定文本格式
}

int mainmenu::checkState(){ // 文件保存状态更新函数
    if(preventState){ // 检测当文件保存状态
        QMessageBox::information(this,"提示","请先保存您的内容！"); // 提示用户内容未被保存
        return 1; // 返回状态
    }
    else{ // 若已保存
        return 0; // 返回状态
    }
}
