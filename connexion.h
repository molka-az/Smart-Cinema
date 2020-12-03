#ifndef CONNEXION_H
#define CONNEXION_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>


class Connexion
{
public:
    Connexion();
    bool createconnect();
};

#endif // CONNEXION_H
