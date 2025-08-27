#include "../DoctorWindow/doctormainwindow.h"

PatientInfoWindow::PatientInfoWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("患者信息");
    resize(400, 400);
    setStyleSheet("QMainWindow { background-color: #f0f4f8; }");

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->setContentsMargins(10, 10, 10, 10);
    layout->setSpacing(10);

    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchEdit = new QLineEdit();
    searchButton = new QPushButton("搜索");
    searchLayout->addWidget(searchEdit);
    searchLayout->addWidget(searchButton);

    patientTable = new QTableWidget();
    medicalRecordEdit = new QTextEdit();
    prescriptionEdit = new QTextEdit();
    endVisitButton = new QPushButton("结束就诊");

    layout->addLayout(searchLayout);
    layout->addWidget(patientTable);
    layout->addWidget(new QLabel("病例记录:"));
    layout->addWidget(medicalRecordEdit);
    layout->addWidget(new QLabel("医嘱:"));
    layout->addWidget(prescriptionEdit);
    layout->addWidget(endVisitButton);
    layout->addStretch();

    setCentralWidget(centralWidget);

    connect(searchButton, &QPushButton::clicked, this, &PatientInfoWindow::onSearchClicked);
    connect(endVisitButton, &QPushButton::clicked, this, &PatientInfoWindow::onEndVisitClicked);
}

void PatientInfoWindow::onSearchClicked()
{
    // Placeholder: Handle patient search
}

void PatientInfoWindow::onEndVisitClicked()
{
    parentWidget()->show();
    this->hide();
}
