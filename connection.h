#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql/QSqlDatabase>

class Connection {
public:
    bool createConnection();
private:
    QSqlDatabase db;
};

#endif // CONNECTION_H
