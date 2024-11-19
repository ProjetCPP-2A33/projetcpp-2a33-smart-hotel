#include "client.h"
#include "mainwindow.h"
#include <QSqlError>
#include <QSqlQueryModel>
#include<QSqlQuery>


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
        //smtp->sendMail;
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
/*QString Client::clientLePlusFidele() {
    QSqlQuery query;
    // Requête SQL pour récupérer le client avec le plus grand nombre de réservations
    query.prepare("SELECT CLIENTS.NOMC, CLIENTS.PRENOMC, COUNT(RESERVATION.IDR) AS nombre_reservations "
                  "FROM CLIENTS "
                  "JOIN RESERVATION ON CLIENTS.IDC = RESERVATION.IDC "
                  "GROUP BY CLIENTS.IDC "
                  "ORDER BY nombre_reservations DESC "
                  "LIMIT 1");

    if (query.exec()) {
        if (query.next()) { // Si un client est trouvé
            QString nom = query.value("NOMC").toString();
            QString prenom = query.value("PRENOMC").toString();

            qDebug() << "Client le plus fidèle : "
                     << "Nom: " << nom
                     << "Prénom: " << prenom;

            return nom + " " + prenom; // Retourner le nom complet du client fidèle
        }
    } else {
        qDebug() << "Erreur lors de la recherche du client fidèle :" << query.lastError().text();
    }

    return ""; // Retourner une chaîne vide si aucun client n'est trouvé
}*/

/*Client Client::clientLePlusFidele() {
    QSqlQuery query;
    query.prepare("SELECT C.IDC, C.NOMC, C.PRENOMC, COUNT(R.IDC) AS nombre_reservations "
                  "FROM CLIENTS C "
                  "JOIN RESERVATION R ON C.IDC = R.IDC "
                  "GROUP BY C.IDC, C.NOMC, C.PRENOMC "
                  "ORDER BY nombre_reservations DESC "
                  "FETCH FIRST 1 ROWS ONLY");

    if (query.exec()) {
        if (query.next()) {  // Si un client est trouvé
            Client client;
            client.setIdC(query.value("IDC").toInt());
            client.setNomC(query.value("NOMC").toString());
            client.setPrenomC(query.value("PRENOMC").toString());
            return client;  // Retourner le client avec le plus grand nombre de réservations
        }
    } else {
        qDebug() << "Erreur lors de la recherche du client fidèle :" << query.lastError().text();
    }

    return Client();  // Retourner un client vide si aucun client n'est trouvé
}*/


/*QSqlQueryModel* Client::obtenirReservationsParClient() {
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;
    // Ajouter d'abord le client le plus fidèle
    Client clientFidele = clientLePlusFidele();
    QString messageFidele = "Client le plus fidèle :\n";
    messageFidele += "ID: " + QString::number(clientFidele.getIdC()) + "\n";
    messageFidele += "Nom: " + clientFidele.getNomC() + "\n";
    messageFidele += "Prénom: " + clientFidele.getPrenomC() + "\n";

    query.prepare("SELECT R.IDC, COUNT(R.IDC) AS nbr_reservations, C.NOMC, C.PRENOMC "
                  "FROM RESERVATION R "
                  "JOIN CLIENTS C ON R.IDC = C.IDC "
                  "GROUP BY R.IDC, C.NOMC, C.PRENOMC");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
    } else {
        model->setQuery(query);
        // Ajouter une ligne pour le client fidèle en haut de la liste
        model->insertRow(0);
        model->setData(model->index(0, 0), clientFidele.getIdC());
        model->setData(model->index(0, 1), clientFidele.getNomC());
        model->setData(model->index(0, 2), clientFidele.getPrenomC());
        model->setData(model->index(0, 3), 0); // nombre_reservations à 0 pour le client fidèle
    }

    return model;
}*/
/*Client Client::clientLePlusFidele() {
    QSqlQuery query;
    query.prepare("SELECT C.IDC, C.NOMC, C.PRENOMC, COUNT(R.IDC) AS nombre_reservations "
                  "FROM CLIENTS C "
                  "JOIN RESERVATION R ON C.IDC = R.IDC "
                  "GROUP BY C.IDC, C.NOMC, C.PRENOMC "
                  "ORDER BY nombre_reservations DESC "
                  "FETCH FIRST 1 ROWS ONLY");

    if (query.exec()) {
        if (query.next()) {  // Si un client est trouvé
            Client client;
            client.setIdC(query.value("IDC").toInt());
            client.setNomC(query.value("NOMC").toString());
            client.setPrenomC(query.value("PRENOMC").toString());
            return client;  // Retourner le client avec le plus grand nombre de réservations
        }
    } else {
        qDebug() << "Erreur lors de la recherche du client fidèle :" << query.lastError().text();
    }

    return Client();  // Retourner un client vide si aucun client n'est trouvé
}*/

/*QString Client::clientLePlusFidele()
{
    QSqlQuery query("SELECT CLIENTS.IDC, CLIENTS.NOMC, CLIENTS.PRENOMC, COUNT(RESERVATION.idR) AS total_reservations "
                    "FROM CLIENTS "
                    "JOIN RESERVATION ON CLIENTS.IDC = RESERVATION.IDC "
                    "GROUP BY CLIENTS.IDC "
                    "ORDER BY total_reservations DESC LIMIT 1");

    if (query.next()) {
        return query.value("NOMC").toString() + " " + query.value("PRENOMC").toString();
    }
    return "Aucun client fidèle trouvé.";
}*/
/*QString Client::afficherNbReservationsParClient()
{
    // Exécuter la requête pour obtenir le nombre de réservations par client
    QSqlQuery query("SELECT CLIENTS.NOMC, CLIENTS.PRENOMC, CLIENTS.IDC, COUNT(RESERVATION.IDR) AS total_reservations "
                    "FROM CLIENTS "
                    "LEFT JOIN RESERVATION ON CLIENTS.IDC = RESERVATION.IDC "
                    "GROUP BY CLIENTS.IDC");

    QString result;
    while (query.next()) {
        // Extraire les données de la requête
        QString nom = query.value("NOMC").toString();
        QString prenom = query.value("PRENOMC").toString();
        int nbReservations = query.value("total_reservations").toInt();

        // Ajouter les informations à la chaîne de résultat
        result += nom + " " + prenom + " (ID: " + QString::number(query.value("IDC").toInt()) + ") a " + QString::number(nbReservations) + " réservations\n";
    }

    if (result.isEmpty()) {
        return "Aucun client trouvé avec des réservations.";
    }
    return result;
}*/
QSqlQueryModel* Client::obtenirReservationsParClient() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Requête pour compter le nombre de réservations par client
    query.prepare("SELECT R.IDC, COUNT(R.IDC) AS nbr_reservations, C.NOMC, C.PRENOMC "
                  "FROM RESERVATION R "
                  "JOIN CLIENTS C ON R.IDC = C.IDC "
                  "GROUP BY R.IDC, C.NOMC, C.PRENOMC");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        delete model;
        return nullptr;
    }

    model->setQuery(query);
    // Requête pour trouver le client le plus fidèle
   /* QSqlQuery queryFidele; // Assurez-vous que queryFidele est bien déclaré ici.
    queryFidele.prepare("SELECT C.IDC, C.NOMC, C.PRENOMC, COUNT(R.IDC) AS nbr_reservations "
                        "FROM RESERVATION R "
                        "JOIN CLIENTS C ON R.IDC = C.IDC "
                        "GROUP BY C.IDC, C.NOMC, C.PRENOMC "
                        "ORDER BY nbr_reservations DESC "
                        "FETCH FIRST 1 ROWS ONLY");
    if (queryFidele.exec() && queryFidele.next()) {
        int idFidele = queryFidele.value("IDC").toInt();
        QString nomFidele = queryFidele.value("NOMC").toString();
        QString prenomFidele = queryFidele.value("PRENOMC").toString();
        int nbrReservations = queryFidele.value("nbr_reservations").toInt();

        // Ajouter une ligne pour le client le plus fidèle au début du modèle
        model->insertRow(0);
        model->setData(model->index(0, 0), idFidele);
        model->setData(model->index(0, 1), nbrReservations);
        model->setData(model->index(0, 2), nomFidele);
        model->setData(model->index(0, 3), prenomFidele);
    } else {
        qDebug() << "Erreur lors de la recherche du client fidèle : " << queryFidele.lastError().text();
    }*/

    return model;
}


