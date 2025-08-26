#ifndef RESETPASSWORDWINDOW_H
#define RESETPASSWORDWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class ResetPasswordWindow : public QMainWindow
{
    Q_OBJECT

public:
    ResetPasswordWindow(QWidget *parent = nullptr);
    ~ResetPasswordWindow();

private slots:
    void onSubmitClicked(); // 槽函数：处理提交按钮点击事件
    void onBackToLoginClicked(); // 槽函数：处理返回登录按钮点击事件

private:
    QLineEdit *emailEdit; // 邮箱输入框
    QLineEdit *codeEdit; // 验证码输入框
    QPushButton *submitButton; // 提交按钮
    QPushButton *returnLoginButton; // 返回登录按钮
};

#endif // RESETPASSWORDWINDOW_H
