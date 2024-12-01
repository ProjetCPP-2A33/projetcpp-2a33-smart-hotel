#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Employe.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTableView>  // This includes the necessary QTableView class




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool containsOnlyLetters(const QString &str);
private slots:
    void on_ajouter_clicked();
    void refreshTable();
    void on_stats_clicked();

    void on_pushButton_afficher_2_clicked();
    void on_modifier_clicked();
     void on_supprimer_2_clicked();
    void on_comboBox_critereRech_2_currentTextChanged(const QString &arg1);

    void on_pushButton_afficher_clicked();

    void on_lineEdit_critereRecherche_textChanged(const QString &arg1);

    void on_QrCode_clicked();

    void initSerialPort();  // Initialisation du port série
    void readSerialData();  // Fonction pour lire les données du port série

    void afficherEmployeParUID(const QString& uid);

    void handleCheckIn(const QString &uid);
    QSqlQueryModel* afficherCheckIn();
    void styleTableView(QTableView *tableView);

private:
    Ui::MainWindow *ui;
    Employe E;
    QSerialPort *serialPort;
};
#endif //

