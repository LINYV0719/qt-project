#include "registerwindow.h"
#include <QMessageBox>
#include <QFormLayout>
#include <QVBoxLayout>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口标题和大小
    setWindowTitle("用户注册");
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

    // 添加用户名标签和输入框
    registerUsernameLable = new QLabel("用户名:", centralWidget);
    registerUsernameLable->setStyleSheet("font: 14px 'Arial'; color: #333;");
    registerUsernameEdit = new QLineEdit(centralWidget);
    registerUsernameEdit->setPlaceholderText("请输入用户名");
    registerUsernameEdit->setStyleSheet(
        "QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }"
        "QLineEdit:focus { border-color: #007bff; }");
    formLayout->addRow(registerUsernameLable, registerUsernameEdit);

    // 添加密码标签和输入框
    registerPasswordLable = new QLabel("密码:", centralWidget);
    registerPasswordLable->setStyleSheet("font: 14px 'Arial'; color: #333;");
    registerPasswordEdit = new QLineEdit(centralWidget);
    registerPasswordEdit->setEchoMode(QLineEdit::Password);
    registerPasswordEdit->setPlaceholderText("请输入密码");
    registerPasswordEdit->setStyleSheet(
        "QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }"
        "QLineEdit:focus { border-color: #007bff; }");
    formLayout->addRow(registerPasswordLable, registerPasswordEdit);

    // 添加确认密码标签和输入框
    confirmPasswordLable = new QLabel("确认密码:", centralWidget);
    confirmPasswordLable->setStyleSheet("font: 14px 'Arial'; color: #333;");
    confirmPasswordEdit = new QLineEdit(centralWidget);
    confirmPasswordEdit->setEchoMode(QLineEdit::Password);
    confirmPasswordEdit->setPlaceholderText("请再次输入密码");
    confirmPasswordEdit->setStyleSheet(
        "QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }"
        "QLineEdit:focus { border-color: #007bff; }");
    formLayout->addRow(confirmPasswordLable, confirmPasswordEdit);

    // 添加提交按钮
    submitButton = new QPushButton("提交", centralWidget);
    submitButton->setStyleSheet(
        "QPushButton { background-color: #007bff; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #0056b3; }"
        "QPushButton:pressed { background-color: #003d80; }");
    formLayout->addRow(submitButton);

    // 添加返回登录按钮
    returnLoginButton = new QPushButton("返回登录", centralWidget);
    returnLoginButton->setStyleSheet(
        "QPushButton { background-color: #6c757d; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #5a6268; }"
        "QPushButton:pressed { background-color: #4b545c; }");
    formLayout->addRow(returnLoginButton);

    // 将表单布局添加到主垂直布局，并添加弹性空间实现居中
    mainLayout->addStretch();
    mainLayout->addLayout(formLayout);
    mainLayout->addStretch();

    // 设置中心部件
    setCentralWidget(centralWidget);

    // 连接信号和槽
    connect(submitButton, &QPushButton::clicked, this, &RegisterWindow::onSubmitClicked);
    connect(returnLoginButton, &QPushButton::clicked, this, &RegisterWindow::onBackToLoginClicked);
}

RegisterWindow::~RegisterWindow()
{
    // Qt 父子关系自动管理内存，无需手动清理
}

void RegisterWindow::onSubmitClicked()
{
    // 获取输入内容
    QString username = registerUsernameEdit->text();
    QString password = registerPasswordEdit->text();
    QString confirmPassword = confirmPasswordEdit->text();

    // 检查是否有空输入
    if (username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "用户名或密码不能为空，请重新输入！");
        return;
    }

    // 验证密码和确认密码是否一致
    if (password != confirmPassword) {
        QMessageBox::warning(this, "密码错误", "两次输入的密码不一致，请重新输入！");
        return;
    }

    // 注册成功，显示成功消息
    QMessageBox::information(this, "注册结果", "注册成功！");

    // 可选：将数据保存到数据库或文件（待实现）
}

void RegisterWindow::onBackToLoginClicked()
{
    // 关闭当前窗口并显示登录窗口
    parentWidget()->show();
    this->close();
}
