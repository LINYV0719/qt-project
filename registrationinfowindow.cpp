#include "../DoctorWindow/doctormainwindow.h"

RegistrationInfoWindow::RegistrationInfoWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("挂号信息");
    resize(400, 400);
    setStyleSheet("QMainWindow { background-color: #f0f4f8; }");

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->setContentsMargins(10, 10, 10, 10);
    layout->setSpacing(10);

    registrationTable = new QTableWidget();
    layout->addWidget(registrationTable);
    refreshButton = new QPushButton("刷新");
    returnButton = new QPushButton("返回");
    layout->addWidget(refreshButton);
    layout->addWidget(returnButton);
    layout->addStretch();

    setCentralWidget(centralWidget);

    connect(registrationTable, &QTableWidget::cellDoubleClicked, this, &RegistrationInfoWindow::onViewDetailsClicked);
    connect(returnButton,&QPushButton::clicked,this,&RegistrationInfoWindow::returnMainWindow);
}

void RegistrationInfoWindow::onViewDetailsClicked(int row)
{
    // Placeholder: Handle viewing patient details
}
void RegistrationInfoWindow::returnMainWindow()
{
    parentWidget()->show();
    this->hide();
};
