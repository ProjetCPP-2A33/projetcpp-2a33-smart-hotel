#ifndef RESERVATION_H
#define RESERVATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class reservation
{public:
    reservation();
    reservation(int,int,QString,QString);
    int get_id();
    int get_nbrPerso();
    QString get_dateDebut();
    QString get_dateFin();
    bool ajouter();
    QSqlQueryModel* afficher(const QString& order = "ASC");
    bool supprimer(int);
    bool  modifier_reservation(int id, int nbrPerso, const QString &dateDebut, const QString &dateFin);
    void bt1_afficher_clicked();
    QSqlQuery rechercherParId(int id);
    void exportToPDF();
    double calculateOccupancyRate(const QString &startDate, const QString &endDate);
    QSqlQueryModel* rechercherParDate(const QString& dateDebut, const QString& dateFin);
    QSqlQueryModel* afficherHistorique();





private:
    int id,nbrPerso;
    QString dateDebut,dateFin;
};

#endif // RESERVATION_H
