#include "loginwindow.h"
#include <QMessageBox>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>

ResetPasswordWindow::ResetPasswordWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口标题和大小
    setWindowTitle("重置密码");
    resize(400, 400);

    // 设置窗口背景样式
    setStyleSheet("QMainWindow { background-color: #f0f4f8; }");

    // 创建中心部件和主垂直布局
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(10);

    // 角色选择
    roleCombo = new QComboBox(centralWidget);
    roleCombo->addItems({"患者", "医生"});
    roleCombo->setStyleSheet("QComboBox { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }");
    mainLayout->addWidget(new QLabel("角色:", centralWidget));
    mainLayout->addWidget(roleCombo);

    // 创建堆叠窗口
    stackedWidget = new QStackedWidget(centralWidget);

    // 患者重置页面
    QWidget *patientWidget = new QWidget(centralWidget);
    QFormLayout *patientLayout = new QFormLayout(patientWidget);
    patientLayout->setSpacing(10);

    patientNameLabel = new QLabel("姓名:", centralWidget);
    patientNameLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    patientNameEdit = new QLineEdit(centralWidget);
    patientNameEdit->setPlaceholderText("请输入姓名");
    patientNameEdit->setStyleSheet("QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }");
    patientLayout->addRow(patientNameLabel, patientNameEdit);

    patientIdCardLabel = new QLabel("身份证号:", centralWidget);
    patientIdCardLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    patientIdCardEdit = new QLineEdit(centralWidget);
    patientIdCardEdit->setPlaceholderText("请输入18位身份证号");
    patientIdCardEdit->setStyleSheet("QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }");
    patientLayout->addRow(patientIdCardLabel, patientIdCardEdit);

    patientPhoneLabel = new QLabel("手机号:", centralWidget);
    patientPhoneLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    patientPhoneEdit = new QLineEdit(centralWidget);
    patientPhoneEdit->setPlaceholderText("请输入11位手机号");
    patientPhoneEdit->setStyleSheet("QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }");
    patientLayout->addRow(patientPhoneLabel, patientPhoneEdit);

    patientBirthdateLabel = new QLabel("出生日期:", centralWidget);
    patientBirthdateLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    patientBirthdateEdit = new QLineEdit(centralWidget);
    patientBirthdateEdit->setPlaceholderText("格式：YYYY-MM-DD");
    patientBirthdateEdit->setStyleSheet("QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }");
    patientLayout->addRow(patientBirthdateLabel, patientBirthdateEdit);

    patientNewPasswordLabel = new QLabel("新密码:", centralWidget);
    patientNewPasswordLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    patientNewPasswordEdit = new QLineEdit(centralWidget);
    patientNewPasswordEdit->setEchoMode(QLineEdit::Password);
    patientNewPasswordEdit->setPlaceholderText("请输入新密码");
    patientNewPasswordEdit->setStyleSheet("QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }");
    patientLayout->addRow(patientNewPasswordLabel, patientNewPasswordEdit);

    stackedWidget->addWidget(patientWidget);

    // 医生重置页面
    QWidget *doctorWidget = new QWidget(centralWidget);
    QFormLayout *doctorLayout = new QFormLayout(doctorWidget);
    doctorLayout->setSpacing(10);

    doctorNameLabel = new QLabel("姓名:", centralWidget);
    doctorNameLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    doctorNameEdit = new QLineEdit(centralWidget);
    doctorNameEdit->setPlaceholderText("请输入姓名");
    doctorNameEdit->setStyleSheet("QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }");
    doctorLayout->addRow(doctorNameLabel, doctorNameEdit);

    doctorEmployeeIdLabel = new QLabel("工号:", centralWidget);
    doctorEmployeeIdLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    doctorEmployeeIdEdit = new QLineEdit(centralWidget);
    doctorEmployeeIdEdit->setPlaceholderText("请输入工号");
    doctorEmployeeIdEdit->setStyleSheet("QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }");
    doctorLayout->addRow(doctorEmployeeIdLabel, doctorEmployeeIdEdit);

    doctorDepartmentLabel = new QLabel("科室:", centralWidget);
    doctorDepartmentLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    doctorDepartmentCombo = new QComboBox(centralWidget);
    doctorDepartmentCombo->addItems({"内科", "外科", "儿科", "急诊"});
    doctorDepartmentCombo->setStyleSheet("QComboBox { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }");
    doctorLayout->addRow(doctorDepartmentLabel, doctorDepartmentCombo);

    doctorAdminCodeLabel = new QLabel("管理员验证码:", centralWidget);
    doctorAdminCodeLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    doctorAdminCodeEdit = new QLineEdit(centralWidget);
    doctorAdminCodeEdit->setPlaceholderText("请输入验证码");
    doctorAdminCodeEdit->setStyleSheet("QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }");
    doctorLayout->addRow(doctorAdminCodeLabel, doctorAdminCodeEdit);

    doctorNewPasswordLabel = new QLabel("新密码:", centralWidget);
    doctorNewPasswordLabel->setStyleSheet("font: 14px 'Arial'; color: #333;");
    doctorNewPasswordEdit = new QLineEdit(centralWidget);
    doctorNewPasswordEdit->setEchoMode(QLineEdit::Password);
    doctorNewPasswordEdit->setPlaceholderText("请输入新密码");
    doctorNewPasswordEdit->setStyleSheet("QLineEdit { border: 1px solid #ccc; border-radius: 5px; padding: 5px; }");
    doctorLayout->addRow(doctorNewPasswordLabel, doctorNewPasswordEdit);

    stackedWidget->addWidget(doctorWidget);

    // 添加堆叠窗口到主布局
    mainLayout->addWidget(stackedWidget);

    // 提交按钮
    submitButton = new QPushButton("提交", centralWidget);
    submitButton->setStyleSheet(
        "QPushButton { background-color: #007bff; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #0056b3; }"
        "QPushButton:pressed { background-color: #003d80; }");
    mainLayout->addWidget(submitButton);

    // 返回登录按钮
    returnLoginButton = new QPushButton("返回登录", centralWidget);
    returnLoginButton->setStyleSheet(
        "QPushButton { background-color: #6c757d; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #5a6268; }"
        "QPushButton:pressed { background-color: #4b545c; }");
    mainLayout->addWidget(returnLoginButton);

    // 居中布局
    mainLayout->addStretch();

    // 设置中心部件
    setCentralWidget(centralWidget);

    // 连接信号和槽
    connect(roleCombo, &QComboBox::currentTextChanged, this, &ResetPasswordWindow::onRoleChanged);
    connect(submitButton, &QPushButton::clicked, this, &ResetPasswordWindow::onSubmitClicked);
    connect(returnLoginButton, &QPushButton::clicked, this, &ResetPasswordWindow::onBackToLoginClicked);
}

ResetPasswordWindow::~ResetPasswordWindow()
{
}

void ResetPasswordWindow::onRoleChanged(const QString &role)
{
    stackedWidget->setCurrentIndex(role == "患者" ? 0 : 1);
}

void ResetPasswordWindow::onSubmitClicked()
{
    QString role = roleCombo->currentText();
    QMap<QString, QString> parameters;
    QString dirPath = "F:/CODE/QtProject/HospitalDatabase/";

    QDir dir(dirPath);
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            QMessageBox::warning(this, "保存失败", "无法创建目录: " + dirPath);
            return;
        }
    }

    if (role == "患者") {
        QString name = patientNameEdit->text();
        QString idcard = patientIdCardEdit->text();
        QString phone = patientPhoneEdit->text();
        QString birthdate = patientBirthdateEdit->text();
        QString newPassword = patientNewPasswordEdit->text();

        // 验证空输入
        if (name.isEmpty() || idcard.isEmpty() || phone.isEmpty() || birthdate.isEmpty() || newPassword.isEmpty()) {
            QMessageBox::warning(this, "输入错误", "所有字段均为必填项！");
            return;
        }

        // 格式验证
        QRegularExpression birthdateRx("^\\d{4}-\\d{2}-\\d{2}$");
        QRegularExpression phoneRx("^\\d{11}$");
        if (!birthdateRx.match(birthdate).hasMatch()) {
            QMessageBox::warning(this, "格式错误", "出生日期格式应为 YYYY-MM-DD！");
            return;
        }
        if (idcard.length() != 18) {
            QMessageBox::warning(this, "格式错误", "身份证号应为18位！");
            return;
        }
        if (!phoneRx.match(phone).hasMatch()) {
            QMessageBox::warning(this, "格式错误", "手机号应为11位数字！");
            return;
        }

        // 收集参数
        parameters["姓名"] = name;
        parameters["身份证号"] = idcard;
        parameters["手机号"] = phone;
        parameters["出生日期"] = birthdate;
        parameters["新密码"] = newPassword;

        // 保存到文件
        QString filename = "patient_parameters.txt";
        QFile file(dirPath + filename);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << "---- 新记录 ----\n";
            for (auto it = parameters.constBegin(); it != parameters.constEnd(); ++it) {
                out << it.key() << ": " << it.value() << "\n";
            }
            file.close();
            QMessageBox::information(this, "保存成功", "参数已保存到 " + dirPath + filename);
        } else {
            QMessageBox::warning(this, "保存失败", "无法写入文件 " + dirPath + filename + ": " + file.errorString());
            return;
        }

        // TODO: 验证患者信息并更新密码到数据库
        // - 验证字段：name, idcard, phone, birthdate
        // - 更新：newPassword
        QMessageBox::information(this, "重置成功", "患者密码重置成功");
    } else {
        QString name = doctorNameEdit->text();
        QString employeeId = doctorEmployeeIdEdit->text();
        QString department = doctorDepartmentCombo->currentText();
        QString adminCode = doctorAdminCodeEdit->text();
        QString newPassword = doctorNewPasswordEdit->text();

        // 验证空输入
        if (name.isEmpty() || employeeId.isEmpty() || department.isEmpty() || adminCode.isEmpty() || newPassword.isEmpty()) {
            QMessageBox::warning(this, "输入错误", "所有字段均为必填项！");
            return;
        }

        // 验证管理员验证码
        if (adminCode != "123456") {
            QMessageBox::warning(this, "验证码错误", "管理员验证码错误！");
            return;
        }

        // 收集参数
        parameters["姓名"] = name;
        parameters["工号"] = employeeId;
        parameters["科室"] = department;
        parameters["管理员验证码"] = adminCode;
        parameters["新密码"] = newPassword;

        // 保存到文件
        QString filename = "doctor_parameters.txt";
        QFile file(dirPath + filename);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << "---- 新记录 ----\n";
            for (auto it = parameters.constBegin(); it != parameters.constEnd(); ++it) {
                out << it.key() << ": " << it.value() << "\n";
            }
            file.close();
            QMessageBox::information(this, "保存成功", "参数已保存到 " + dirPath + filename);
        } else {
            QMessageBox::warning(this, "保存失败", "无法写入文件 " + dirPath + filename + ": " + file.errorString());
            return;
        }

        // TODO: 验证医生信息并更新密码到数据库
        // - 验证字段：name, employee_id, department
        // - 更新：newPassword
        QMessageBox::information(this, "重置成功", "医生密码重置成功");
    }
}

void ResetPasswordWindow::onBackToLoginClicked()
{
    parentWidget()->show();
    this->close();
}
