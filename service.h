#ifndef SERVICE_H
#define SERVICE_H

#include "qsqlquerymodel.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <qstandarditemmodel.h>
#include <QStandardItemModel>

class Service {
public:
    Service();
    Service(int ids, QString noms, int prix, int disponibilite);

    int getIds() const;
    QString getNoms() const;
    float getPrix() const;
    int getDisponibilite() const;

    void setIds(int ids);
    void setNoms(const QString &noms);
    void setPrix(int prix);
    void setDisponibilite(int disponibilite);

    bool ajouter(int ids, const QString& noms,int prix,int disponibilite  );
    QSqlQueryModel* afficher();
    bool supprimer(int ids);
    bool modifier(int ids, const QString& noms, float prix, int disponibilite);
    QSqlQueryModel* recherche(int ids);
    QSqlQueryModel* trierParPrix();
    static QMap<QString, double> obtenirStatistiquesDisponibilite();
    QMap<QString, double> statistiquesParDisponibilite();
    void exporterPDF(const QString &nomFichier, QAbstractItemModel *model);
    void addToHistory(const QString &action, int ids);

private:
    int ids;
    QString noms;
    float prix;
    int disponibilite;
};

#endif // SERVICE_H
