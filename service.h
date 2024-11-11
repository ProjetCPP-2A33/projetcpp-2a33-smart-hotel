#ifndef SERVICE_H
#define SERVICE_H

#include <QString>
//#include <QSqlQueryModel>

class Service {
public:
    Service(int id, QString name, double price, bool available);
    bool add();
    bool update(int id);
    bool remove(int id);
    //static QSqlQueryModel* displayAll();
private:
    int id;
    QString name;
    double price;
    bool available;
};

#endif // SERVICE_H
