#ifndef GESTIONCLIENTS_H
#define GESTIONCLIENTS_H
#include "arduinoservice.h"
#include "client.h"
#include <QMainWindow>
#include "Arduino.h"
#include "Connection.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMainWindow>
#include <qnetworkreply.h>
#include "service.h"
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void on_pushButton_trierParNom_clicked();
    void on_pushButton_trierParNom_3_clicked();
    void exportToPdf(const QString &fileName);
    void on_pushButton_export_pdf_clicked();
    void createPieChart(QString critere);
    void on_comboBoxCritere_currentIndexChanged();
    void on_pushButtonRechercher_met_clicked();
    void on_pushButton_afficher_clicked();
    void sendEmailWithPostmark();
    void verifyEmployeeID();
    QString processEmployeeID(const QString &employeeID);
    void on_pushButton_VerifyID_clicked();

    // nour
    void on_ajouterButton_clicked();
    void on_supprimerButton_clicked();
    void on_modifierButton_clicked();
    void on_rechercherButton_clicked();
    void on_trierButton_clicked();
    void on_statistiqueButton_clicked();
    void on_statistiqueButton_2_clicked();
    void on_pb_pdf_clicked();
    void on_pb_historiqueService_clicked();
    void on_ButtonOuvrir_Clicked();
    void on_sendSMSButton_clicked();
    void envoyerSMS(const QString &destinataire, const QString &message);


private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_rechercher_clicked();
    void actualiserListeClients();
    void on_pushButton_modifier_clicked();
    void on_pushButton_rechercher2_clicked();
    void on_pushButtonSend_clicked();
    void on_pushButton_client_fidele_clicked();

private:
    Ui::MainWindow *ui;
    Client Cl;
    Arduino A;
    Connection conn;
    Service serviceModel;
    void afficherHistoriqueService();
    void addToHistory(const QString &action, int ids);
    QSerialPort *serialPort;
   arduinoServices *arduinoServices;
};




#endif // GESTIONCLIENTS_H
