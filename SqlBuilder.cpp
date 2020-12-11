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

    int i, j, columnsCount = this->columns.size();
    QVariantList rows, row;
    QVariant column;

    /**
     * Iterate all rows on result
     */
    for (i = 0; query.next(); i++) {
      /**
       * Catch all columns and append each on a the actual row.
       */
      for (j = 0; j < columnsCount; j++)
          row.append(query.value(j));
      /**
       * Append the row on rows list.
       */
      rows.append(row);
      row = {};
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
