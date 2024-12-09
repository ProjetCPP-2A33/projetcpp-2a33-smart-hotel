
#include "connection.h"
#include <QDebug>

connection::connection()
{
}

bool connection::createconnection()
{
    bool test = false;

    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("projercpp");  // Nom de la source de données
        db.setUserName("aziz1");          // Nom d'utilisateur
        db.setPassword("aziz");              // Mot de passe
    }

    if (db.open()) {
        test = true;
    } else {
        qDebug() << "Erreur lors de la connexion à la base de données:" << db.lastError().text();
    }

    return test;
}

void connection::closeconnection()
{
    if (db.isOpen()) {
        db.close();
    }
}
