#ifndef GESTIONCLIENTS_H
#define GESTIONCLIENTS_H
#include "client.h"
#include <QMainWindow>
#include "Arduino.h"
#include "Connection.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

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
     //quint64 convertUIDtoNumber(const QString &cardUID);

     void on_pushButton_VerifyID_clicked();


private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_rechercher_clicked();
    void actualiserListeClients();
    void on_pushButton_modifier_clicked();
    void on_pushButton_rechercher2_clicked();
    void on_pushButtonSend_clicked();
  //  void afficherClientLePlusFidele();
   // void afficherNbReservationsClients();
   // void afficherReservationsParClient();
    //void afficherClientFidele();

    void on_pushButton_client_fidele_clicked();

  //  void on_pushButton_VerifyID_clicked(); // Bouton pour vérifier l'UID

   // void readDataFromArduino();

  //  void processEmployeeID(const QString &employeeID);
  //  void processCardUID(const QString &cardUID);
   // void sendDataToArduino(const QByteArray &data);
    /*QString getAthleteCardCodeFromDatabase(const QString &cardUID);
    QString getAthleteNameFromDatabase(const QString &athleteCardCode);
    QString getAthleteFirstNameFromDatabase(const QString &athleteCardCode);*/

    // Méthodes pour interagir avec la base de données
   // QString getEmployeeCardCodeFromDatabase(const QString &employeeID); // Récupérer le code de la carte de l'employé depuis la base
   // QString getEmployeeNameFromDatabase(const QString &employeeCardCode); // Récupérer le nom de l'employé depuis la base
  //  QString getEmployeeFirstNameFromDatabase(const QString &employeeCardCode); // Récupérer le prénom de l'employé depuis la base


private:
    Ui::MainWindow *ui;
    Client Cl;
   // QByteArray data;
    Arduino A;
    Connection conn;    // Instance de la classe Connection

};




#endif // GESTIONCLIENTS_H
