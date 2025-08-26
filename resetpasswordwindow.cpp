#include "resetpasswordwindow.h"
#include <QMessageBox>

ResetPasswordWindow::ResetPasswordWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口标题和大小
    setWindowTitle("Reset Password");
    resize(400, 300);

    // 创建中心部件和垂直布局
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // 添加邮箱标签和输入框
    QLabel *emailLabel = new QLabel("Email:", centralWidget);
    emailEdit = new QLineEdit(centralWidget);
    emailEdit->setPlaceholderText("请输入邮箱");
    layout->addWidget(emailLabel);
    layout->addWidget(emailEdit);

    // 添加验证码标签和输入框
    QLabel *codeLabel = new QLabel("Verification Code:", centralWidget);
    codeEdit = new QLineEdit(centralWidget);
    codeEdit->setPlaceholderText("请输入验证码");
    layout->addWidget(codeLabel);
    layout->addWidget(codeEdit);

    // 添加提交按钮
    submitButton = new QPushButton("Submit", centralWidget);
    layout->addWidget(submitButton);

    // 添加返回登录按钮
    returnLoginButton = new QPushButton("Return to Login", centralWidget);
    layout->addWidget(returnLoginButton);

    // 添加伸缩项使布局居中
    layout->addStretch();

    // 设置中心部件
    setCentralWidget(centralWidget);

    // 连接信号和槽
    connect(submitButton, &QPushButton::clicked, this, &ResetPasswordWindow::onSubmitClicked);
    connect(returnLoginButton, &QPushButton::clicked, this, &ResetPasswordWindow::onBackToLoginClicked);
}

ResetPasswordWindow::~ResetPasswordWindow()
{
    // Qt 父子关系自动管理内存，无需手动清理
}

void ResetPasswordWindow::onSubmitClicked()
{
    // 获取输入内容
    QString email = emailEdit->text();
    QString code = codeEdit->text();

    // 检查是否有空输入
    if (email.isEmpty() || code.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "邮箱或验证码不能为空，请重新输入！");
        return;
    }

    // 验证邮箱格式（简单示例，实际需更复杂的正则表达式）
    if (!email.contains("@")) {
        QMessageBox::warning(this, "邮箱错误", "请输入有效的邮箱地址！");
        return;
    }

    // 假设验证码验证通过（实际需后端验证）
    QMessageBox::information(this, "重置结果", "密码重置成功！");

    // 可选：将数据保存或发送到服务器（待实现）
}

void ResetPasswordWindow::onBackToLoginClicked()
{
    // 关闭当前窗口并显示登录窗口
    parentWidget()->show();
    this->close();
}
