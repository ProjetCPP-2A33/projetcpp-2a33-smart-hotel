#include"connection.h"
#include <QDebug>
#include <QSqlError>
Connection::Connection(){}

bool Connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    //bool test=false;
    db.setDatabaseName("ProjetCpp2A33");
    db.setUserName("Malek");
    db.setPassword("oracle");
    if (db.open()) {
        qDebug() << "Connexion réussie!";
        return true;
    } else {
        qDebug() << "Erreur de connexion : " << db.lastError().text();
        return false;
    }

}

void Connection::closeConnection(){db.close();}
