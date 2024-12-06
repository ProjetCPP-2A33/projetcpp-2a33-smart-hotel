#include "reservation.h"
#include <QString>
#include <QDebug>
#include <QVariant>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include <QSqlError>

reservation::reservation()
{
    id=0;
    nbrPerso=0;
    dateDebut="";
    dateFin="";
}

reservation::reservation(int id,int nbrPerso,QString dateDebut,QString dateFin)
{
    this->id=id;
    this->nbrPerso=nbrPerso;
    this->dateDebut=dateDebut;
    this->dateFin=dateFin;
}
QString reservation::get_dateDebut(){return dateDebut;}
QString reservation::get_dateFin(){return dateFin;}
int reservation::get_id(){return id;}
int reservation::get_nbrPerso(){return nbrPerso;}

bool reservation::ajouter()
{
    reservation R;
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO reservation (id, nbrPerso, dateDebut, dateFin)""VALUES(:id, :nbrPerso, :dateDebut, :dateFin)");
    query.bindValue(":id", res);
    query.bindValue(":nbrPerso", nbrPerso);
    query.bindValue(":dateDebut", dateDebut);
    query.bindValue(":dateFin", dateFin);
    return query.exec();
}
QSqlQueryModel *reservation::afficher(const QString& order)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    QString queryString = QString("SELECT * FROM reservation ORDER BY dateDebut %1").arg(order);
    query.prepare(queryString);
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
        return nullptr; // Retournez nullptr en cas d'erreur
    }

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbrPerso"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateDebut"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateFin"));

    return model;
}
bool reservation::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from reservation WHERE id = :id");
    query.bindValue(":id",res);
    return query.exec();
}
bool reservation :: modifier_reservation(int id, int nbrPerso, const QString &dateDebut, const QString &dateFin)
{

    QSqlQuery query;
    query.prepare("UPDATE reservation SET nbrPerso = :nbrPerso, dateDebut = :dateDebut, dateFin = :dateFin WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":nbrPerso", nbrPerso);
    query.bindValue(":dateDebut", dateDebut);
    query.bindValue(":dateFin", dateFin);

    bool success = query.exec();
    if (!success) {
        qDebug() << "Erreur lors de la modification :" << query.lastError().text();
    }
    return success;
}
QSqlQuery reservation::rechercherParId(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM reservation WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche par ID:" << query.lastError().text();
    }
    return query;
}
double reservation::calculateOccupancyRate(const QString &dateDebut, const QString &dateFin)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM reservation WHERE dateDebut AND dateFin ");
    query.bindValue(":dateDebut", dateDebut);
    query.bindValue(":dateFin", dateFin);

    if (!query.exec()) {
        qDebug() << "Erreur lors du calcul du taux d'occupation :" << query.lastError().text();
        return -1; // Return -1 to indicate an error
    }

    query.next();
    int reservationCount = query.value(0).toInt();

    // Assuming that you have a way to calculate total possible reservations,
    // For example, a constant value or fetched from another table.
    int totalPossibleReservations = 100; // Example value; replace with your actual logic.

    if (totalPossibleReservations == 0) {
        return 0;
    }

    return (reservationCount / (double)totalPossibleReservations) * 100;
}
