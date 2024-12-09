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
    Employe(QString id_e, QString nome, QString prenom, int salaire, int numero, QString datenaissancee);

    // Getters
    QString getId_e() const { return id_e; }  // Updated to QString
    // Other getters remain the same

    // Setters
    void setId_e(QString id_e) { this->id_e = id_e; }  // Updated to QString
    // Other setters remain the same

    // CRUD Operations
    bool ajouter(); // Create
    QSqlQueryModel* afficher(); // Read
    bool supprimer2(QString id_e);  // Updated to QString
    bool modifier(); // Update
    QChartView* createSalaireDistributionChart();
    void exportDataToPDF();
    QSqlQueryModel* trier(const QString& sortColumn);
    QSqlQueryModel* rechercher(const QString& searchType, const QString& value);

private:
    // Employee attributes
    QString id_e;  // Updated to QString
    QString nome;
    QString prenom;
    int salaire;
    int numero;
    QString datenaissancee;
};

#endif // EMPLOYE_H
