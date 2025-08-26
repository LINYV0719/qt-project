#include "resetpasswordwindow.h"
#include <QMessageBox>
#include <QFormLayout>
#include <QVBoxLayout>

ResetPasswordWindow::ResetPasswordWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口标题和大小
    setWindowTitle("重置密码");
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

    // 添加邮箱标签和输入框
    QLabel *emailLabel = new QLabel("邮箱:", centralWidget);
    emailLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    emailEdit = new QLineEdit(centralWidget);
    emailEdit->setPlaceholderText("请输入邮箱");
    emailEdit->setStyleSheet(
        "QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }"
        "QLineEdit:focus { border-color: #007bff; }");
    formLayout->addRow(emailLabel, emailEdit);

    // 添加验证码标签和输入框
    QLabel *codeLabel = new QLabel("验证码:", centralWidget);
    codeLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    codeEdit = new QLineEdit(centralWidget);
    codeEdit->setPlaceholderText("请输入验证码");
    codeEdit->setStyleSheet(
        "QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }"
        "QLineEdit:focus { border-color: #007bff; }");
    formLayout->addRow(codeLabel, codeEdit);

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
