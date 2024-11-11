#include "connection.h"
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

bool Connection::createConnection() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("hotel_database.db");

    if (!db.open()) {
        qDebug() << "Database connection failed!";
        return false;
    }
    qDebug() << "Database connected successfully.";
    return true;
}
