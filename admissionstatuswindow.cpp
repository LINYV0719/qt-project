#include "../DoctorWindow/doctormainwindow.h"

AdmissionStatusWindow::AdmissionStatusWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("接诊状态设置");
    resize(400, 400);
    setStyleSheet("QMainWindow { background-color: #f0f4f8; }");

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->setContentsMargins(10, 10, 10, 10);
    layout->setSpacing(10);

    QFormLayout *formLayout = new QFormLayout();
    maxAppointmentsSpinBox = new QSpinBox();
    formLayout->addRow("每日最大预约人数:", maxAppointmentsSpinBox);
    receptionStatusCheckBox = new QCheckBox("接诊状态 (开启/关闭)");
    formLayout->addRow(receptionStatusCheckBox);
    saveButton = new QPushButton("保存");
    formLayout->addRow(saveButton);
    returnButton = new QPushButton("返回");
    formLayout->addRow(returnButton);

    layout->addLayout(formLayout);
    layout->addStretch();
    setCentralWidget(centralWidget);

    connect(returnButton,&QPushButton::clicked,this,&AdmissionStatusWindow::returnMainWindow);
}
void AdmissionStatusWindow::returnMainWindow()
{
    parentWidget()->show();
    this->hide();
};
