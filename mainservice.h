#ifndef MAINSERVICE_H
#define MAINSERVICE_H

#include <QMainWindow>
#include <qnetworkreply.h>
#include "service.h"
#include <QSerialPort>
#include "arduinoservices.h"
//#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouterButton_clicked();
    void on_supprimerButton_clicked();
    void on_modifierButton_clicked();
    void on_rechercherButton_clicked();
    void on_trierButton_clicked();
    void on_statistiqueButton_clicked();
    void on_statistiqueButton_2_clicked();
    void on_pb_pdf_clicked();
    void on_pb_historiqueService_clicked();

    void on_sendSMSButton_clicked();
    void envoyerSMS(const QString &destinataire, const QString &message);
    void on_ButtonOuvrir_Clicked();

private:
    Ui::MainWindow *ui;
    Service serviceModel;
    void afficherHistoriqueService();
    void addToHistory(const QString &action, int ids);
    QSerialPort *serialPort; // Port série pour Arduino
    arduinoServices *arduinoServices;
    //QString arduinoPortName; // Nom du port série utilisé
    //bool arduinoIsAvailable;
};

#endif // MAINSERVICE_H
