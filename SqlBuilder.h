#ifndef SQLBUILDER_H
#define SQLBUILDER_H

#include <QString>

class SqlBuilder
{
protected:
    QString table;
public:
    SqlBuilder(QString table);
};

SqlBuilder* db(QString table);

#endif // SQLBUILDER_H
