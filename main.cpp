#include <QCoreApplication>
#include<QDebug>

#include <SqlBuilder.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // return a.exec();

    QVariantMap params;
    params["id"] = 4;

    /**
     * Select example.
     */
    // db("users")
    //   ->select({"id", "name", "registration"})
    //   ->where({"id", "=", ":id"}, params)
    //   ->rows();

    /**
     * Insert example.
     */

    // QVariantMap values;

    // values["name"] = "'Chaves'";
    // values["registration"] = "'123456'";

    // db("users")
    //   ->insert(values)->execute();

    /**
     * Delete example.
     */
    // db("users")
    // ->destroy()->where({"id","=", "14"})
    // ->execute();

    /**
     * Update example.
     */

   // QVariantMap values;

   // values["name"] = "'Ñoño'";
   // values["registration"] = "'654321'";

   // db("users")
   // ->update(values)->where({"id", "=", "4"})->execute();

    return 0;
}
