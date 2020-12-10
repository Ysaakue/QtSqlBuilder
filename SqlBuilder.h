#ifndef SQLBUILDER_H
#define SQLBUILDER_H

#include <QString>
#include <QStringList>
#include <QVariantMap>

#include <Database.h>

class SqlBuilder
{
protected:
    QString sql;
    QString table;
    QVariantMap params;
    QStringList columns = {"*"};
public:
    SqlBuilder(QString table);
    SqlBuilder* select(QStringList columns = {"*"});
    SqlBuilder* where(QStringList condition, QVariantMap params = {});

    QVariantList rows();

    void setSql(QString sql);
    QString getSql();
};

SqlBuilder* db(QString table);

#endif // SQLBUILDER_H
