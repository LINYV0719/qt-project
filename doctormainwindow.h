#ifndef DOCTORMAINWINDOW_H
#define DOCTORMAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QTableWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QMessageBox>

class AdmissionStatusWindow;
class RegistrationInfoWindow;
class PatientInfoWindow;
class PunchLeaveWindow;
class ReceptionWindow;







class DoctorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    DoctorMainWindow(QWidget *parent = nullptr);
    ~DoctorMainWindow();

private slots:
    void onAdmissionStatusClicked();
    void onRegisterInformationClicked();
    void onPatientInformationClicked();
    void onPunchAndAskForLeaveClicked();
    void onReceptionClicked();

private:
    QLabel *imageLabel;
    QPushButton *admissionStatusButton;
    QPushButton *registerInformationButton;
    QPushButton *patientInformationButton;
    QPushButton *punchAndAskForLeaveButton;
    QPushButton *receptionButton;
};






class AdmissionStatusWindow : public QMainWindow
{
    Q_OBJECT

public:
    AdmissionStatusWindow(QWidget *parent = nullptr);

private slots:
    void returnMainWindow();
private:
    QSpinBox *maxAppointmentsSpinBox;
    QCheckBox *receptionStatusCheckBox;
    QPushButton *saveButton;
    QPushButton *returnButton;
};





class RegistrationInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    RegistrationInfoWindow(QWidget *parent = nullptr);

private slots:
    void onViewDetailsClicked(int row);
    void returnMainWindow();


private:
    QTableWidget *registrationTable;
    QPushButton *refreshButton;
    QPushButton *returnButton;
};






class PatientInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    PatientInfoWindow(QWidget *parent = nullptr);

private slots:
    void onSearchClicked();
    void onEndVisitClicked();

private:
    QLineEdit *searchEdit;
    QTableWidget *patientTable;
    QTextEdit *medicalRecordEdit;
    QTextEdit *prescriptionEdit;
    QPushButton *searchButton;
    QPushButton *endVisitButton;
};










class PunchLeaveWindow : public QMainWindow
{
    Q_OBJECT

public:
    PunchLeaveWindow(QWidget *parent = nullptr);

private slots:
    void onPunchCheckBoxToggled(bool checked);
    void returnMainWindow();


private:
    QCheckBox *punchCheckBox;
    QTableWidget *punchHistoryTable;
    QPushButton *refreshHistoryButton;
    QPushButton *returnButton;
};








class ReceptionWindow : public QMainWindow
{
    Q_OBJECT

public:
    ReceptionWindow(QWidget *parent = nullptr);

private slots:
    void onNextPatientClicked();
    void onSearchPatientClicked();
    void returnMainWindow();


private:
    QLabel *patientInfoLabel;
    QTextEdit *medicalRecordEdit;
    QTextEdit *prescriptionEdit;
    QTextEdit *adviceEdit;
    QLineEdit *searchPatientEdit;
    QPushButton *nextPatientButton;
    QPushButton *searchPatientButton;
    QPushButton *returnButton;
};

#endif // DOCTORMAINWINDOW_H
