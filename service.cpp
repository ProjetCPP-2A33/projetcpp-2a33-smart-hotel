#include "service.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QtSql/qsqlquery.h>

Service::Service(int id, QString name, double price, bool available)
    : id(id), name(name), price(price), available(available) {}

bool Service::add() {
    QSqlQuery query;
    query.prepare("INSERT INTO services (id, name, price, availability) VALUES (?, ?, ?, ?)");
    query.addBindValue(id);
    query.addBindValue(name);
    query.addBindValue(price);
    query.addBindValue(available);
    return query.exec();
}

bool Service::update(int id) {
    QSqlQuery query;
    query.prepare("UPDATE services SET name = ?, price = ?, availability = ? WHERE id = ?");
    query.addBindValue(name);
    query.addBindValue(price);
    query.addBindValue(available);
    query.addBindValue(id);
    return query.exec();
}

bool Service::remove(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM services WHERE id = ?");
    query.addBindValue(id);
    return query.exec();
}


