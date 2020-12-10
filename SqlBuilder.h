#ifndef SQLBUILDER_H
#define SQLBUILDER_H

#include <QString>
#include <QStringList>

class SqlBuilder
{
protected:
    QString sql;
    QString table;
    QStringList columns = {"*"};
public:
    SqlBuilder(QString table);
    SqlBuilder* select(QStringList columns = {"*"});

    void setSql(QString sql);
    QString getSql();
};

SqlBuilder* db(QString table);

#endif // SQLBUILDER_H
