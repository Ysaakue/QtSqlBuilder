#include "SqlBuilder.h"

SqlBuilder::SqlBuilder(QString table)
{
  this->table = table;
}

/**
 * @brief SqlBuilder::select
 * @param columns
 * @return
 */
SqlBuilder* SqlBuilder::select(QStringList columns) {
    this->columns = columns;
    this->sql += "select " + columns.join(", ") + " from " + this->table;
    return this;
}

/**
 * @brief SqlBuilder::setSql
 * @param sql
 */
void SqlBuilder::setSql(QString sql) { this->sql = sql; }
/**
 * @brief SqlBuilder::getSql
 * @return
 */
QString SqlBuilder::getSql() { return this->sql; }

/**
 * @brief db
 * @param table
 * @return
 */
SqlBuilder* db(QString table) {
  return new SqlBuilder(table);
}
