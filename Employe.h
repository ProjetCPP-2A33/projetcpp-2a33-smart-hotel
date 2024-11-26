#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQueryModel>
#include <QtCharts/QChartView>    //statistique
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QSqlQuery>
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
// Employe class definition
class Employe {
public:
    // Default Constructor
    Employe();

    // Parameterized Constructor
    Employe(int id_e, QString nome, QString prenom, int salaire, int numero, QString datenaissancee);

    // Getters
    int getId_e() const { return id_e; }
    QString getNome() const { return nome; }
    QString getPrenom() const { return prenom; }
    int getSalaire() const { return salaire; }
    int getNumero() const { return numero; }
    QString getDatenaissancee() const { return datenaissancee; }

    // Setters
    void setId_e(int id_e) { this->id_e = id_e; }
    void setNome(QString nome) { this->nome = nome; }
    void setPrenom(QString prenom) { this->prenom = prenom; }
    void setSalaire(int salaire) { this->salaire = salaire; }
    void setNumero(int numero) { this->numero = numero; }
    void setDatenaissancee(QString datenaissancee) { this->datenaissancee = datenaissancee; }

    // CRUD Operations
    bool ajouter(); // Create
    QSqlQueryModel* afficher(); // Read
    bool supprimer2(int id_e);
    bool modifier(); // Update
    QChartView* createSalaireDistributionChart();
    void exportDataToPDF();
    QSqlQueryModel* trier(const QString& sortColumn);
    QSqlQueryModel* rechercher(const QString& searchType, const QString& value);
private:
    // Employee attributes
    int id_e;
    QString nome;
    QString prenom;
    int salaire;
    int numero;
    QString datenaissancee;
};

#endif // EMPLOYE_H
