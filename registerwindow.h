#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H



#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>


class RegisterWindow:public QMainWindow
{
    Q_OBJECT
public:
    RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();
private slots:
    void onSubmitClicked(); // 槽函数：处理提交按钮点击事件
    void onBackToLoginClicked(); // 槽函数：处理返回登录按钮点击事件
private:
    // 提示：声明成员变量，如用户名、密码、确认密码输入框，提交按钮，返回按钮等
    QLabel *registerUsernameLable;
    QLabel *registerPasswordLable;
    QLabel *confirmPasswordLable;

    QLineEdit *registerUsernameEdit;
    QLineEdit *registerPasswordEdit;
    QLineEdit *confirmPasswordEdit;
    QPushButton *submitButton;
    QPushButton *returnLoginButton;

    QString  registerUsername;
    QString registerPassword;
    QString confirmPassword;
};
#endif // REGISTERWINDOW_H
