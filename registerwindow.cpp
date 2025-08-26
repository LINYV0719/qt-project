#include "registerwindow.h"
#include <QMessageBox>


RegisterWindow::RegisterWindow(QWidget *parent)
    :QMainWindow(parent)
{

    // 提示：设置窗口标题和大小
    setWindowTitle("Register");
    resize(400,300);

    // 提示：创建中心部件和垂直布局（QVBoxLayout）
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // 提示：添加用户名标签和输入框
    registerUsernameLable = new QLabel("registerUsername:",centralWidget);
    registerUsernameEdit = new QLineEdit(centralWidget);
    layout->addWidget(registerUsernameLable);
    layout->addWidget(registerUsernameEdit);

    // 提示：添加密码标签和输入框（设置为密码模式）
    registerPasswordLable = new QLabel("Password:",centralWidget);
    registerPasswordEdit = new QLineEdit(centralWidget);
    registerPasswordEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    layout->addWidget(registerPasswordLable);
    layout->addWidget(registerPasswordEdit);

    // 提示：添加确认密码标签和输入框（设置为密码模式）
    confirmPasswordLable = new QLabel("Confirm Password:",centralWidget);
    confirmPasswordEdit = new QLineEdit(centralWidget);
    confirmPasswordEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    layout->addWidget(confirmPasswordLable);
    layout->addWidget(confirmPasswordEdit);

    // 提示：添加提交按钮
    submitButton = new QPushButton("Submit", centralWidget);
    layout->addWidget(submitButton);

    // 提示：添加返回登录按钮
    returnLoginButton = new QPushButton("Return to Login", centralWidget);
    layout->addWidget(returnLoginButton);

    // 提示：添加伸缩项使布局居中
    layout->addStretch();

    // 提示：设置中心部件
    setCentralWidget(centralWidget);

    // 提示：连接信号和槽（如提交按钮和返回按钮的clicked信号）
    connect(submitButton,&QPushButton::clicked,this,&RegisterWindow::onSubmitClicked);
    connect(returnLoginButton,&QPushButton::clicked,this,&RegisterWindow::onBackToLoginClicked);

}
RegisterWindow::~RegisterWindow()
{
    // 提示：通常无需手动清理，Qt父子关系会自动管理内存
}

void RegisterWindow::onSubmitClicked()
{
    // 提示：获取用户名、密码、确认密码的输入内容
    QString  registerUsername = registerUsernameEdit->text();
    QString registerPassword = registerPasswordEdit->text();
    QString confirmPassword = confirmPasswordEdit->text();


    // 提示：验证密码和确认密码是否一致
    bool isEmpty = (registerUsername.isEmpty()||registerPassword.isEmpty()||confirmPassword.isEmpty());
    if(isEmpty){
        QMessageBox::warning(this,"mistake",
                                 "the username/password is empty, please rewrite");
        return;

    };
    if(!(registerPassword == confirmPassword)){
        QMessageBox::warning(this,"mistake","the password is incorrect");
        return;
    };


    // 提示：显示注册成功或失败的消息（使用QMessageBox）
        QMessageBox::information(this,"message","sucess");

    // 提示：可选 - 将数据保存到数据库或文件
}

void RegisterWindow::onBackToLoginClicked()
{
    // 提示：关闭当前窗口并返回登录窗口
    parentWidget()->show();
    this->close();
    // 提示：可选 - 发射信号通知LoginWindow显示
}
