#include "loginwindow.h"
#include "registerwindow.h"
#include "resetpasswordwindow.h"
#include <QWidget>
#include <QMessageBox>
#include <QFormLayout>
#include <QVBoxLayout>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口标题和大小
    setWindowTitle("用户登录");
    resize(400, 300);

    // 设置窗口背景样式
    setStyleSheet("QMainWindow { background-color: #f0f4f8; }");

    // 创建中心部件和主垂直布局
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(20, 20, 20, 20); // 设置布局边距
    mainLayout->setSpacing(10); // 设置控件间距

    // 创建表单布局
    QFormLayout *formLayout = new QFormLayout();
    formLayout->setSpacing(10); // 设置表单内间距

    // 创建用户名输入框
    QLabel *usernameLabel = new QLabel("用户名:", centralWidget);
    usernameLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    usernameEdit = new QLineEdit(centralWidget);
    usernameEdit->setPlaceholderText("请输入用户名");
    usernameEdit->setStyleSheet(
        "QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }"
        "QLineEdit:focus { border-color: #007bff; }");
    formLayout->addRow(usernameLabel, usernameEdit);

    // 创建密码输入框
    QLabel *passwordLabel = new QLabel("密码:", centralWidget);
    passwordLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    passwordEdit = new QLineEdit(centralWidget);
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setPlaceholderText("请输入密码");
    passwordEdit->setStyleSheet(
        "QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }"
        "QLineEdit:focus { border-color: #007bff; }");
    formLayout->addRow(passwordLabel, passwordEdit);

    // 创建登录按钮
    loginButton = new QPushButton("登录", centralWidget);
    loginButton->setStyleSheet(
        "QPushButton { background-color: #007bff; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #0056b3; }"
        "QPushButton:pressed { background-color: #003d80; }");
    formLayout->addRow(loginButton);

    // 创建注册按钮
    registerButton = new QPushButton("注册", centralWidget);
    registerButton->setStyleSheet(
        "QPushButton { background-color: #28a745; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #218838; }"
        "QPushButton:pressed { background-color: #1e7e34; }");
    formLayout->addRow(registerButton);

    // 创建重置密码按钮
    resetPasswordButton = new QPushButton("重置密码", centralWidget);
    resetPasswordButton->setStyleSheet(
        "QPushButton { background-color: #dc3545; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #c82333; }"
        "QPushButton:pressed { background-color: #bd2130; }");
    formLayout->addRow(resetPasswordButton);

    // 将表单布局添加到主垂直布局，并添加弹性空间实现居中
    mainLayout->addStretch();
    mainLayout->addLayout(formLayout);
    mainLayout->addStretch();

    // 设置中心部件
    setCentralWidget(centralWidget);

    // 连接信号和槽
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::onRegisterClicked);
    connect(resetPasswordButton, &QPushButton::clicked, this, &LoginWindow::onResetPasswordClicked);
}

LoginWindow::~LoginWindow()
{
}

void LoginWindow::onLoginClicked()
{
    // 登录逻辑
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();
    QMessageBox::information(this, "登录", "尝试登录：\n用户名: " + username + "\n密码: " + password);
}

void LoginWindow::onRegisterClicked()
{
    // 跳转到注册界面
    RegisterWindow *registerWindow = new RegisterWindow(this);
    registerWindow->show();
    this->hide();
}

void LoginWindow::onResetPasswordClicked()
{
    // 跳转到重置密码界面
    ResetPasswordWindow *resetPasswordWindow = new ResetPasswordWindow(this);
    resetPasswordWindow->show();
    this->hide();
}
