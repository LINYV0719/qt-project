#include "loginwindow.h"
#include "registerwindow.h"
#include "resetpasswordwindow.h"
#include <QWidget>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口标题和大小
    setWindowTitle("Login");
    resize(400, 300);

    // 创建中心部件和布局
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // 创建用户名输入框
    QLabel *usernameLabel = new QLabel("Username:", centralWidget);
    usernameEdit = new QLineEdit(centralWidget);
    layout->addWidget(usernameLabel);
    layout->addWidget(usernameEdit);

    // 创建密码输入框
    QLabel *passwordLabel = new QLabel("Password:", centralWidget);
    passwordEdit = new QLineEdit(centralWidget);
    passwordEdit->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordEdit);

    // 创建登录按钮
    loginButton = new QPushButton("Login", centralWidget);
    layout->addWidget(loginButton);

    // 创建注册和重置密码按钮
    registerButton = new QPushButton("Register", centralWidget);
    resetPasswordButton = new QPushButton("Reset Password", centralWidget);
    layout->addWidget(registerButton);
    layout->addWidget(resetPasswordButton);

    // 添加伸缩项保持布局居中
    layout->addStretch();

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
    // 登录逻辑（待实现）
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();
    QMessageBox::information(this, "Login", "Login attempt with:\nUsername: " + username + "\nPassword: " + password);
}

void LoginWindow::onRegisterClicked()
{
    // 跳转到注册界面（待实现）
    RegisterWindow *registerwindow = new RegisterWindow(this);
    registerwindow->show();
    this->hide();
}

void LoginWindow::onResetPasswordClicked()
{
    ResetPasswordWindow *resetpasswordwindow = new ResetPasswordWindow(this);
    resetpasswordwindow->show();
    this->hide();
}
