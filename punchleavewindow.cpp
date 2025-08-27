#include "../DoctorWindow/doctormainwindow.h"

PunchLeaveWindow::PunchLeaveWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("打卡与请假");
    resize(400, 400);
    setStyleSheet("QMainWindow { background-color: #f0f4f8; }");

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->setContentsMargins(10, 10, 10, 10);
    layout->setSpacing(10);

    punchCheckBox = new QCheckBox("今日打卡");
    punchHistoryTable = new QTableWidget();
    refreshHistoryButton = new QPushButton("刷新记录");
    returnButton = new QPushButton("返回");

    layout->addWidget(punchCheckBox);
    layout->addWidget(punchHistoryTable);
    layout->addWidget(refreshHistoryButton);
    layout->addWidget(returnButton);
    layout->addStretch();

    setCentralWidget(centralWidget);

    connect(punchCheckBox, &QCheckBox::toggled, this, &PunchLeaveWindow::onPunchCheckBoxToggled);
    connect(returnButton,&QPushButton::clicked,this,&PunchLeaveWindow::returnMainWindow);
}

void PunchLeaveWindow::onPunchCheckBoxToggled(bool checked)
{
    // Placeholder: Handle punch in/out with message box
}
void PunchLeaveWindow::returnMainWindow()
{
    parentWidget()->show();
    this->hide();
};

