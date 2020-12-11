#include "Database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

Database* Database::instance = nullptr;

Database::Database()
{
  this->connection = this->createConnection();
  this->query = this->createQuery();
}

Database::~Database()
{
  this->closeConnection();
}

QSqlQuery Database::execute(QString sql, QVariantMap params) {
  QSqlQuery query = this->query;
  query.prepare(sql);
  for (auto param : params.keys()) {
   query.bindValue(":" + param, params.value(param));
  }
  query.exec();
  return query;
}

void Database::closeConnection()
{
    this->query.clear();
    this->connection.close();
}

Database* Database::getInstance() {
    if (Database::instance == 0)
    {
        Database::instance = new Database();
    }
    return Database::instance;
}

/*
 * @brief Database::createQuery
 * @return
 */
QSqlQuery Database::createQuery() {
  QSqlQuery query(this->connection);
  return query;
}

/**
 * Returns an instance of database connection.
 * @brief Database::createConnection
 * @return
 */
QSqlDatabase Database::createConnection() {
    /**
     * Instanciate database connection object
     * using SQLITE driver.
     * @brief db
     */
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/tmp/db_name.db");

    if (!db.open()) {
      /**
       * Throws an exception if had some error on connection attempt.
       * @throws exception
       */
       throw std::runtime_error("Error connecting to database.");
    }

    return db;
}
