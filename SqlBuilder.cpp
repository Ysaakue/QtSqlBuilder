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
 * @brief SqlBuilder::where
 * @param condition
 * @param params
 * @return
 */
SqlBuilder* SqlBuilder::where(QStringList condition, QVariantMap params) {
    this->sql += " where " + condition.join(" ");
    this->params = params;
    return this;
}

QVariantList SqlBuilder::rows() {
    Database* db = Database::getInstance();
    QSqlQuery query = db->execute(this->sql, this->params);

    int i;
    QVariantList rows, row;
    QVariant column;

    for (i = 0; query.next(); i++) {
      rows.append(query.value(0).toString());
    }

    return rows;
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
