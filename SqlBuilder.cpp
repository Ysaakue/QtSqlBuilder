#include "SqlBuilder.h"

SqlBuilder::SqlBuilder(QString table)
{
  this->table = table;
}

SqlBuilder* db(QString table) {
  return new SqlBuilder(table);
}
