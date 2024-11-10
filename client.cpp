#include "client.h"
#include "mainwindow.h"
#include <QSqlError>

Client::Client()
{
    nomC="";
    prenomC="";
    //idC=0;
    num_telC=0;
    genre="";
    emailC="";
    nationalite="";
    CIN="";

}
Client::Client(QString CIN,int num_telC,QString nomC,QString prenomC,QString nationalite,QString emailC,QString genre )
{
    //this->idC=idC;
    this->CIN=CIN;
    this->num_telC=num_telC;
    this->nomC=nomC;
    this->prenomC=prenomC;
    this->nationalite=nationalite;
    this->emailC=emailC;
    this->genre=genre;

}

bool Client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENTS(CIN, NOMC, PRENOMC, NATIONALITE, GENRE, NUM_TELC, EMAILC) "
                  "VALUES(:CIN, :NOMC, :PRENOMC, :NATIONALITE, :GENRE, :NUM_TELC, :EMAILC)");

    query.bindValue(":CIN", CIN);
    query.bindValue(":NOMC", nomC);
    query.bindValue(":PRENOMC", prenomC);
    query.bindValue(":NATIONALITE", nationalite);
    query.bindValue(":GENRE", genre);
    query.bindValue(":NUM_TELC", num_telC);
    query.bindValue(":EMAILC", emailC);

    // Debugging output
    qDebug() << "CIN:" << CIN
             << "Nom:" << nomC
             << "Prénom:" << prenomC
             << "Email:" << emailC
             << "Num Tel:" << num_telC;

    // Execute the query and check for errors
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout : " << query.lastError().text();
        return false;
    }
    return true;
}


QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENTS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDC"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOMC"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOMC"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NATIONALITE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("EMAILC"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("GENRE"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("NUM_TELC"));
    return model;
}

Client Client::rechercher(int idC)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTS WHERE IDC = :idC");
    query.bindValue(":idC", idC);

    if (query.exec()) {
        qDebug() << "Requête exécutée avec succès pour ID :" << idC;
        if (query.next()) { // Si un client est trouvé
            // Initialiser un objet Client avec les valeurs de la base de données
            this->CIN = query.value("CIN").toString();
            this->nomC = query.value("NOMC").toString();
            this->prenomC = query.value("PRENOMC").toString();
            this->nationalite = query.value("NATIONALITE").toString();
            this->genre = query.value("GENRE").toString();
            this->num_telC = query.value("NUM_TELC").toInt();
            this->emailC = query.value("EMAILC").toString();
            // Ajoutez un message de débogage ici
            qDebug() << "Client trouvé : CIN=" << this->CIN
                     << ", Nom=" << this->nomC
                     << ", Prénom=" << this->prenomC
                     << ", Nationalité=" << this->nationalite
                     << ", Genre=" << this->genre
                     << ", Num Tel=" << this->num_telC
                     << ", Email=" << this->emailC;
            return *this; // Retourner l'objet Client avec les données récupérées
        }
    } else {
        qDebug() << "Erreur lors de la recherche :" << query.lastError().text();
    }

    return Client(); // Retourner un client vide si aucun client n'est trouvé ou en cas d'erreur
}


bool Client::supprimer(int idC)
{
    QSqlQuery query;
    //QString res=QString::number(idC);
    query.prepare("DELETE FROM CLIENTS WHERE IDC= :idC");
    query.bindValue(":idC",idC);
    return query.exec();

}

bool Client::modifier(int idC)
{
    QSqlQuery query;
    query.prepare("UPDATE CLIENTS SET CIN = :CIN, NOMC = :NOMC, PRENOMC = :PRENOMC, "
                  "NATIONALITE = :NATIONALITE, GENRE = :GENRE, NUM_TELC = :NUM_TELC, "
                  "EMAILC = :EMAILC WHERE IDC = :idC");

    query.bindValue(":CIN", CIN);
    query.bindValue(":NOMC", nomC);
    query.bindValue(":PRENOMC", prenomC);
    query.bindValue(":NATIONALITE", nationalite);
    query.bindValue(":GENRE", genre);
    query.bindValue(":NUM_TELC", num_telC);
    query.bindValue(":EMAILC", emailC);
    query.bindValue(":idC", idC);

    // Debugging output
    qDebug() << "Mise à jour du client : " << "ID:" << idC
             << "CIN:" << CIN
             << "Nom:" << nomC
             << "Prénom:" << prenomC
             << "Email:" << emailC
             << "Num Tel:" << num_telC;

    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour : " << query.lastError().text();
        return false;
    }
    return true;
}
QSqlQueryModel* Client::trierParNom(const QString& ordre)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryText = "SELECT * FROM CLIENTS ORDER BY NOMC ";
    model->setQuery(queryText);
    return model;
}

QSqlQueryModel* Client::trierParNom_desc(const QString& ordre)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryText = "SELECT * FROM CLIENTS ORDER BY NOMC DESC";
    model->setQuery(queryText);
    return model;
}


QSqlQueryModel* Client::rechercher(const QString& critere, const QString& typeRecherche) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Utilisez le critère pour effectuer la recherche en fonction du type choisi
    QString queryString;
    if (typeRecherche == "Nom") {
        queryString = "SELECT * FROM CLIENTS WHERE NOMC LIKE :criterePattern";
    } else if (typeRecherche == "Prenom") {
        queryString = "SELECT * FROM CLIENTS WHERE PRENOMC LIKE :criterePattern";
    } else if (typeRecherche == "IdClient") {
        queryString = "SELECT * FROM CLIENTS WHERE IDC LIKE :criterePattern";
    }else if (typeRecherche == "CIN") {
        queryString = "SELECT * FROM CLIENTS WHERE CIN LIKE :criterePattern";
    }
    // Ajoutez d'autres conditions en fonction des types de recherche disponibles

    query.prepare(queryString);
    query.bindValue(":criterePattern", "%" + critere + "%");  // Recherche partielle (LIKE %critere%)

    if (query.exec()) {
        model->setQuery(query);
        return model;
    } else {
        // Gérer les erreurs ou retourner nullptr selon vos besoins
        delete model;
        return nullptr;
    }
}





