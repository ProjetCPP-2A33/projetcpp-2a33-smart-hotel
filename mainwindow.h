#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include <QMainWindow>

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

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_rechercher_clicked();
    void actualiserListeClients();
    void on_pushButton_modifier_clicked();
    void on_pushButton_rechercher2_clicked();

private:
    Ui::MainWindow *ui;
    Client Cl;

};




#endif // MAINWINDOW_H
