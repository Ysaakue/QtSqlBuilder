#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariantMap>

class Database
{
public:
    QSqlDatabase connection;
    QSqlQuery query;

    void closeConnection();
    static Database* getInstance();
    QSqlQuery execute(QString sql, QVariantMap params = {});

private:
    Database();
    ~Database();

    QSqlQuery createQuery();
    QSqlDatabase createConnection();
protected:
    static Database* instance;
};

#endif // DATABASE_H
