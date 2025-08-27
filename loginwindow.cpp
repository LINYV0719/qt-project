#include "loginwindow.h"
#include "doctormainwindow.h"
#include <QWidget>
#include <QMessageBox>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口标题和大小、样式
    setWindowTitle("用户登录");
    resize(400, 400);
    setStyleSheet("QMainWindow { background-color: #f0f4f8; }");

    // 创建中心部件和主垂直布局
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(10);

    // 创建表单布局
    QFormLayout *formLayout = new QFormLayout();
    formLayout->setSpacing(10);

    // 角色选择
    roleCombo = new QComboBox(centralWidget);
    roleCombo->addItems({"患者", "医生"});
    roleCombo->setStyleSheet("QComboBox { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }");
    formLayout->addRow("角色:", roleCombo);

    // 账号输入框
    accountLabel = new QLabel("手机号:", centralWidget);
    accountLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    accountEdit = new QLineEdit(centralWidget);
    accountEdit->setPlaceholderText("请输入手机号");
    accountEdit->setStyleSheet(
        "QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }"
        "QLineEdit:focus { border-color: #007bff; }");
    formLayout->addRow(accountLabel, accountEdit);

    // 密码输入框
    QLabel *passwordLabel = new QLabel("密码:", centralWidget);
    passwordLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    passwordEdit = new QLineEdit(centralWidget);
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setPlaceholderText("请输入密码");
    passwordEdit->setStyleSheet(
        "QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }"
        "QLineEdit:focus { border-color: #007bff; }");
    formLayout->addRow(passwordLabel, passwordEdit);

    // 登录按钮
    loginButton = new QPushButton("登录", centralWidget);
    loginButton->setStyleSheet(
        "QPushButton { background-color: #007bff; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #0056b3; }"
        "QPushButton:pressed { background-color: #003d80; }");
    formLayout->addRow(loginButton);

    // 注册按钮
    registerButton = new QPushButton("注册", centralWidget);
    registerButton->setStyleSheet(
        "QPushButton { background-color: #28a745; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #218838; }"
        "QPushButton:pressed { background-color: #1e7e34; }");
    formLayout->addRow(registerButton);

    // 重置密码按钮
    resetPasswordButton = new QPushButton("重置密码", centralWidget);
    resetPasswordButton->setStyleSheet(
        "QPushButton { background-color: #dc3545; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #c82333; }"
        "QPushButton:pressed { background-color: #bd2130; }");
    formLayout->addRow(resetPasswordButton);

    // 居中布局、设置中心部件
    mainLayout->addStretch();
    mainLayout->addLayout(formLayout);
    mainLayout->addStretch();
    setCentralWidget(centralWidget);

    // 连接信号和槽
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::onRegisterClicked);
    connect(resetPasswordButton, &QPushButton::clicked, this, &LoginWindow::onResetPasswordClicked);
    connect(roleCombo, &QComboBox::currentTextChanged, this, &LoginWindow::onRoleChanged);
}

LoginWindow::~LoginWindow()
{
}

QMap<QString, QString> LoginWindow::getLineEditData() const
{
    QMap<QString, QString> data;
    QString role = roleCombo->currentText();
    QString accountLabelText = (role == "患者") ? "手机号" : "工号";
    data[accountLabelText] = accountEdit->text();
    data["密码"] = passwordEdit->text();
    return data;
}

void LoginWindow::onRoleChanged(const QString &role)
{
    // 动态更新账号标签和占位符
    if (role == "患者") {
        accountLabel->setText("手机号:");
        accountEdit->setPlaceholderText("请输入手机号");
    } else {
        accountLabel->setText("工号:");
        accountEdit->setPlaceholderText("请输入工号");
    }
}

void LoginWindow::onLoginClicked()
{
    QString role = roleCombo->currentText();
    QString account = accountEdit->text();
    QString password = passwordEdit->text();

    if (account.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "账号或密码不能为空！");
        return;
    }


    // 保存参数到txt文件
    QMap<QString, QString> parameters = getLineEditData();
    QString filename = (role == "患者") ? "patient_parameters.txt" : "doctor_parameters.txt";
    QString dirPath = "F:/CODE/QtProject/HospitalDatabase/";
    QString fullPath = dirPath + filename;

    // Ensure directory exists
    QDir dir(dirPath);
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            QMessageBox::warning(this, "保存失败", "无法创建目录: " + dirPath);
            return;
        }
    }

    QFile file(fullPath);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << "---- 新记录 ----\n"; // Separator for readability
        for (auto it = parameters.constBegin(); it != parameters.constEnd(); ++it) {
            out << it.key() << ": " << it.value() << "\n";
        }
        file.close();
        QMessageBox::information(this, "保存成功", "参数已保存到 " + fullPath);
    } else {
        QMessageBox::warning(this, "保存失败", "无法写入文件 " + fullPath + ": " + file.errorString());
    }

    // TODO: 数据库验证逻辑
    // TODO: 患者：验证手机号和密码
    // TODO: 医生：验证工号和密码

    // 登录成功信息
    QMessageBox::information(this, "登录成功", "欢迎！进入主页面（角色：" + role + "）。");

    //TODO：验证失败
    // TODO: 跳转到患者/医生界面
    if(role == "医生"){
        LoginWindow::jumpToDoctorWindow();
    }



}

void LoginWindow::onRegisterClicked()
{
    RegisterWindow *registerWindow = new RegisterWindow(this);
    registerWindow->show();
    this->hide();
}

void LoginWindow::onResetPasswordClicked()
{
    ResetPasswordWindow *resetPasswordWindow = new ResetPasswordWindow(this);
    resetPasswordWindow->show();
    this->hide();
}

void LoginWindow::jumpToDoctorWindow()
{
    DoctorMainWindow *doctorwindow = new DoctorMainWindow(this);
    doctorwindow->show();
    this->hide();

}

void LoginWindow::jumpToPatientWindow()
{

}
