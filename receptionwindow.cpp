#include "../DoctorWindow/doctormainwindow.h"

ReceptionWindow::ReceptionWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("接诊");
    resize(400, 400);
    setStyleSheet("QMainWindow { background-color: #f0f4f8; }");

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->setContentsMargins(10, 10, 10, 10);
    layout->setSpacing(10);

    patientInfoLabel = new QLabel("患者信息");
    medicalRecordEdit = new QTextEdit();
    prescriptionEdit = new QTextEdit();
    adviceEdit = new QTextEdit();
    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchPatientEdit = new QLineEdit();
    searchPatientButton = new QPushButton("查询患者");
    searchLayout->addWidget(searchPatientEdit);
    searchLayout->addWidget(searchPatientButton);
    nextPatientButton = new QPushButton("下一个患者");
    returnButton = new QPushButton("返回");

    layout->addWidget(patientInfoLabel);
    layout->addWidget(new QLabel("病例:"));
    layout->addWidget(medicalRecordEdit);
    layout->addWidget(new QLabel("医嘱:"));
    layout->addWidget(adviceEdit);
    layout->addWidget(new QLabel("处方:"));
    layout->addWidget(prescriptionEdit);
    layout->addLayout(searchLayout);
    layout->addWidget(nextPatientButton);
    layout->addWidget(returnButton);
    layout->addStretch();

    setCentralWidget(centralWidget);

    connect(nextPatientButton, &QPushButton::clicked, this, &ReceptionWindow::onNextPatientClicked);
    connect(searchPatientButton, &QPushButton::clicked, this, &ReceptionWindow::onSearchPatientClicked);
    connect(returnButton,&QPushButton::clicked,this,&ReceptionWindow::returnMainWindow);
}

void ReceptionWindow::onNextPatientClicked()
{
    // Placeholder: Handle next patient in queue
}

void ReceptionWindow::onSearchPatientClicked()
{
    // Placeholder: Handle patient search
}
void ReceptionWindow::returnMainWindow()
{
    parentWidget()->show();
    this->hide();
};
