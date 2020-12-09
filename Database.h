#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>

class Database
{
public:
    QSqlDatabase connection;
    QSqlQuery query;

    void closeConnection();
    static Database* getInstance();
private:
    Database();
    ~Database();

    QSqlQuery createQuery();
    QSqlDatabase createConnection();
protected:
    static Database* instance;
};

#endif // DATABASE_H
