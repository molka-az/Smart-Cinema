#ifndef SALLES_H
#define SALLES_H


#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QVariant>

class salles
{
public:
    salles();
    salles(std::string,int,std::string);
    //salles(std::string,int,std::string);

    std::string get_lettre();
    int get_nb();
    std::string get_type();

    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);
   QSqlQueryModel * trier();

private:
    std::string lettre;
    int nb;
    std::string type;

};

#endif // salles_H
