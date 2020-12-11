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

/**
 * @brief SqlBuilder::insert
 * @param values
 * @return
 */
SqlBuilder* SqlBuilder::insert(QVariantMap values) {
    this->sql += "insert into " + this->table;

    QStringList columnsToInsert, valuesToInsert;

    for (auto value : values.keys()) {
        columnsToInsert.append(value);

         valuesToInsert.append(values.value(value).toString());
    }

    this->sql += " (" + columnsToInsert.join(", ") + ")" + " values (" + valuesToInsert.join(", ") + ")";

    return this;
}

/**
 * @brief SqlBuilder::destroy
 * @return
 */
SqlBuilder* SqlBuilder::destroy() {
    this->sql += "delete from " + this->table;
    return this;
}

/**
 * @brief SqlBuilder::update
 * @param values
 * @return
 */
SqlBuilder* SqlBuilder::update(QVariantMap values) {

    this->sql += "update " + this->table + " set ";

    QStringList columnsToUpdate, valuesToUpdate;

    for (auto value : values.keys()) {
       this->sql += value + " = " + values.value(value).toString() + ", ";
    }

    this->sql = this->sql.remove(this->sql.size() - 2, 2);

    return this;
}

/**
 * @brief SqlBuilder::cleanSql
 */
void SqlBuilder::cleanSql() {
   this->sql = "";
}

/**
 * @brief SqlBuilder::execute
 */
void SqlBuilder::execute() {
    Database* db = Database::getInstance();
    QSqlQuery query = db->execute(this->sql, this->params);
    this->sql = "";
}

/**
 * @brief SqlBuilder::rows
 * @return
 */
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
