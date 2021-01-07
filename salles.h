#ifndef SALLES_H
#define SALLES_H
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>

class salles
{
    QString lettre,tp;
    int nbp  ;

public:
     //constructor
    salles();
    salles(QString,QString, int);
    //getters and setters
    QString getlettre(){return lettre;}
    QString getatp(){return tp;}
    // methodes
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString lettre , QString tp, int nbp);

    bool  search(QString lettre );
    QSqlQueryModel * sort();
    QSqlQueryModel * sortAsc();
    static QSqlQueryModel * afficher1();
    static QSqlQueryModel *modi1();

};

#endif // SALLES_H
