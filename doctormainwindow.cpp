#include "../DoctorWindow/doctormainwindow.h"


DoctorMainWindow::DoctorMainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    setWindowTitle("Doctor");
    resize(400,400);
    setStyleSheet("QMainWindow { background-color: #f0f4f8; }");

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *vLayout = new QVBoxLayout(centralWidget);
    vLayout->setContentsMargins(20,20,20,20);
    vLayout->setSpacing(10);

    imageLabel = new QLabel(this);
    QPixmap doctorImage("C:/Users/lin/Pictures/youngdoctor.jpg");
    imageLabel->setPixmap(doctorImage.scaled(200, 300,
        Qt::KeepAspectRatio, Qt::SmoothTransformation));
    imageLabel->setAlignment(Qt::AlignCenter);



    QFormLayout *formLayout = new QFormLayout(this);
    formLayout->setSpacing(10);

    admissionStatusButton = new QPushButton("接诊状态");
    formLayout->addRow(admissionStatusButton);
    admissionStatusButton->setStyleSheet(
        "QPushButton { background-color: #4dabf7; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #339af0; }"
        "QPushButton:pressed { background-color: #228be6; }");

    registerInformationButton = new QPushButton("挂号信息");
    formLayout->addRow(registerInformationButton);
    registerInformationButton->setStyleSheet(
        "QPushButton { background-color: #4dabf7; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #339af0; }"
        "QPushButton:pressed { background-color: #228be6; }");

    patientInformationButton = new QPushButton("患者信息");
    formLayout->addRow(patientInformationButton);
    patientInformationButton->setStyleSheet(
        "QPushButton { background-color: #4dabf7; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #339af0; }"
        "QPushButton:pressed { background-color: #228be6; }");

    punchAndAskForLeaveButton = new QPushButton("打卡与请假");
    formLayout->addRow(punchAndAskForLeaveButton);
    punchAndAskForLeaveButton->setStyleSheet(
        "QPushButton { background-color: #4dabf7; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #339af0; }"
        "QPushButton:pressed { background-color: #228be6; }");

    receptionButton = new QPushButton("接诊");
    formLayout->addRow(receptionButton);
    receptionButton->setStyleSheet(
        "QPushButton { background-color: #4dabf7; color: white; border-radius: 5px; padding: 8px; font: 14px 'Arial'; }"
        "QPushButton:hover { background-color: #339af0; }"
        "QPushButton:pressed { background-color: #228be6; }");

    vLayout->addWidget(imageLabel);
    vLayout->addLayout(formLayout);
    vLayout->addStretch();

    setCentralWidget(centralWidget);

    connect(admissionStatusButton,&QPushButton::clicked,this,&DoctorMainWindow::onAdmissionStatusClicked);
    connect(registerInformationButton,&QPushButton::clicked,this,&DoctorMainWindow::onRegisterInformationClicked);
    connect(patientInformationButton,&QPushButton::clicked,this,&DoctorMainWindow::onPatientInformationClicked);
    connect(punchAndAskForLeaveButton,&QPushButton::clicked,this,&DoctorMainWindow::onPunchAndAskForLeaveClicked);
    connect(receptionButton,&QPushButton::clicked,this,&DoctorMainWindow::onReceptionClicked);

}

DoctorMainWindow::~DoctorMainWindow(){}

void DoctorMainWindow::onAdmissionStatusClicked()
{
    AdmissionStatusWindow *window = new AdmissionStatusWindow(this);
    window->show();
    this->hide();
};
void DoctorMainWindow::onRegisterInformationClicked()
{
    RegistrationInfoWindow *window = new RegistrationInfoWindow(this);
    window->show();
    this->hide();
};
void DoctorMainWindow::onPatientInformationClicked()
{
    PatientInfoWindow *window = new PatientInfoWindow(this);
    window->show();
    this->hide();
};
void DoctorMainWindow::onPunchAndAskForLeaveClicked()
{
    PunchLeaveWindow *window = new PunchLeaveWindow(this);
    window->show();
    this->hide();
};
void DoctorMainWindow::onReceptionClicked()
{
    ReceptionWindow *window = new ReceptionWindow(this);
    window->show();
    this->hide();
};


