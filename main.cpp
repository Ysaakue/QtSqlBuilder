#include <QCoreApplication>
#include<QDebug>

#include <SqlBuilder.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // return a.exec();

    QVariantMap params;
    params["id"] = 1;

    qDebug() <<

    db("users")
      ->select({"id", "nome"})
      ->where({"id", "=", ":id"}, params)
      ->rows()

             << "\n";

    return 0;
}
