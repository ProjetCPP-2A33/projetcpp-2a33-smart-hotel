#include "service.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <qsqlrecord.h>
#include <QStandardItemModel>
#include <QPdfWriter>
#include <QPainter>
#include <QFile>
#include <QTextStream>
#include <QDateTime>


Service::Service() : ids(0), noms(""), prix(0.0), disponibilite(1) {}

Service::Service(int ids, QString noms, int prix, int disponibilite)
    : ids(ids), noms(noms), prix(prix), disponibilite(disponibilite) {}

int Service::getIds() const { return ids; }
QString Service::getNoms() const { return noms; }
float Service::getPrix() const { return prix; }
int Service::getDisponibilite() const { return disponibilite; }

void Service::setIds(int ids) { this->ids = ids; }
void Service::setNoms(const QString &noms) { this->noms = noms; }
void Service::setPrix(int prix) { this->prix = prix; }
void Service::setDisponibilite(int disponibilite) { this->disponibilite = disponibilite; }

bool Service::ajouter(int ids, const QString& noms,int prix,int disponibilite  ) {
    QSqlQuery query;
    query.prepare("INSERT INTO SERVICE (IDS, NOMS, PRIX, DISPONIBILITE) "
                  "VALUES (:ids, :noms, :prix, :disponibilite )");
    query.bindValue(":ids", ids);
    query.bindValue(":noms", noms);
    query.bindValue(":prix", prix);
    query.bindValue(":disponibilite", disponibilite);

    return query.exec();

}


QSqlQueryModel* Service::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from service");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr( "ids"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("noms"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("disponibilite"));
    return model;
}
bool Service::supprimer(int ids) {

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM SERVICE WHERE IDS = :ids");
    query.bindValue(":ids", ids);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la vérification de l'ID :" << query.lastError().text();
        return false;
    }

    query.next();
    if (query.value(0).toInt() == 0) {
        qDebug() << "ID non trouvé dans la base de données pour suppression.";
        return false;
    }


    query.prepare("DELETE FROM SERVICE WHERE IDS = :ids");
    query.bindValue(":ids", ids);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression :" << query.lastError().text();
        return false;
    }

    qDebug() << "Suppression réussie pour IDS :" << ids;
    return true;
}
bool Service::modifier(int ids, const QString& noms, float prix, int disponibilite) {

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM SERVICE WHERE IDS = :ids");
    query.bindValue(":ids", ids);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la vérification de l'ID :" << query.lastError().text();
        return false;
    }

    query.next();
    if (query.value(0).toInt() == 0) {
        qDebug() << "ID non trouvé dans la base de données pour modification.";
        return false;
    }


    query.prepare("UPDATE SERVICE SET NOMS = :noms, PRIX = :prix, DISPONIBILITE = :disponibilite WHERE IDS = :ids");
    query.bindValue(":ids", ids);
    query.bindValue(":noms", noms);
    query.bindValue(":prix", prix);
    query.bindValue(":disponibilite", disponibilite);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification :" << query.lastError().text();
        return false;
    }

    qDebug() << "Modification réussie pour IDS :" << ids;
    return true;
}
void Service::exporterPDF(const QString &nomFichier, QAbstractItemModel *model) {
    QPdfWriter pdfWriter(nomFichier);
    QPainter painter(&pdfWriter);

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));


    painter.drawText(2500, 1100, "Liste des Services");

    int startX = 200;
    int startY = 1800;
    int cellWidth = 1100;
    int cellHeight = 450;


    QStringList headers = {"ID Service", "Nom", "Prix", "Disponibilité"};
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    for (int col = 0; col < headers.size(); ++col) {
        painter.drawText(startX + col * cellWidth, startY, cellWidth, cellHeight, Qt::AlignCenter, headers[col]);
    }

    // Données des services
    int rowCount = model->rowCount();
    painter.setFont(QFont("Arial", 10));
    for (int row = 0; row < rowCount; ++row) {
        QColor bgColor = (row % 2 == 0) ? Qt::lightGray : Qt::white;

        for (int col = 0; col < headers.size(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            QRect cellRect(startX + col * cellWidth, startY + (row + 1) * cellHeight, cellWidth, cellHeight);

            painter.fillRect(cellRect, bgColor);
            painter.drawText(cellRect, Qt::AlignCenter, data);
            painter.drawRect(cellRect);
        }
    }

    QMessageBox::information(nullptr, "PDF Créé", "Un fichier PDF a été créé pour les services.");
}

QSqlQueryModel* Service::recherche(int ids) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;


    query.prepare("SELECT * FROM SERVICE WHERE IDS = :ids");
    query.bindValue(":ids", ids);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche :" << query.lastError().text();
        delete model;
        return nullptr;
    }


    model->setQuery(query);

    if (model->rowCount() == 0) {
        delete model;
        return nullptr;
    }

    return model;
}

QSqlQueryModel* Service::trierParPrix() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM SERVICE ORDER BY PRIX DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ids"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("noms"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("disponibilite"));
    addToHistory("Afficher", ids);
    return model;
}

QMap<QString, double> Service::obtenirStatistiquesDisponibilite() {
    QMap<QString, double> stats;
    QSqlQuery query;

    query.prepare("SELECT COUNT(*) FROM SERVICE");
    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération du nombre total de services :" << query.lastError().text();
        return stats;
    }

    query.next();
    int totalServices = query.value(0).toInt();
    if (totalServices == 0) {
        return stats;
    }

    query.prepare("SELECT DISPONIBILITE, COUNT(*) FROM SERVICE GROUP BY DISPONIBILITE");
    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des statistiques de disponibilité :" << query.lastError().text();
        return stats;
    }

    while (query.next()) {
        int disponibilite = query.value(0).toInt();
        int count = query.value(1).toInt();

        double percentage = (count * 100.0) / totalServices;

        if (disponibilite == 1) {
            stats["Disponible"] = percentage;
        } else {
            stats["Non Disponible"] = percentage;
        }
    }

    return stats;
}
QMap<QString, double> Service::statistiquesParDisponibilite() {
    QMap<QString, double> stats;
    QSqlQuery query;


    query.prepare("SELECT COUNT(*) FROM SERVICE");
    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération du nombre total de services :" << query.lastError().text();
        return stats;
    }

    query.next();
    int totalServices = query.value(0).toInt();
    if (totalServices == 0) {
        return stats;
    }


    query.prepare("SELECT DISPONIBILITE, COUNT(*) FROM SERVICE GROUP BY DISPONIBILITE");
    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des statistiques de disponibilité :" << query.lastError().text();
        return stats;
    }

    while (query.next()) {
        int disponibilite = query.value(0).toInt();
        int count = query.value(1).toInt();
        double percentage = (count * 100.0) / totalServices;

        if (disponibilite == 1) {
            stats["Disponible"] = percentage;
        } else {
            stats["Non Disponible"] = percentage;
        }
    }

    return stats;
}
void Service::addToHistory(const QString &action, int ids) {
    QString cheminFichier = "C:/Users/nour1/OneDrive/Documents/InterfaceCRUD/historique_service.txt";
    QFile file(cheminFichier);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Erreur lors de l'ouverture du fichier historique.";
        return;
    }

    QTextStream out(&file);
    QDateTime currentDateTime = QDateTime::currentDateTime();
    out << currentDateTime.toString("yyyy-MM-dd hh:mm:ss") << " - " << action;
    if (ids != 0) {
        out << " pour l'ID " << ids;
    }
    out << "\n";
    file.close();
}
