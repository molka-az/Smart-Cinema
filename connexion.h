#ifndef CONNEXION_H
#define CONNEXION_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>


class connexion
{
private:
    QSqlDatabase db;
public:
    connexion();
    bool ouvrirconnexion();
    void fermerconnexion();
};

#endif // CONNEXION_H
