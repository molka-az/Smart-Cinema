#ifndef HORAIRE_H
#define HORAIRE_H
#include "QString"
#include "QSqlQuery"
#include <QSqlQueryModel>


class horaire
{
public:
    horaire();
    horaire(int ,QString ,QString ,int ,int,int );
   int getid();
    QString get_nom();
    QString get_prenom();
    int get_id();
    int get_cin();
    int get_HT();
    int get_Jours_off();
        void setid(int id);
        void setnom(QString nom);
        void setcin();
        void setprenom(QString prenom);
        void setHT();
        void set_Jours_off();
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int id);
    bool modifier(int id,QString colonne,QString nouv);
    QSqlQueryModel * trier_horaire_asc();
     QSqlQueryModel * trier_horaire_desc();
    bool  search(int id );


        private:
    int id;
    QString nom;
   QString prenom;
   int cin;
   int Jours_off;
   int HT;
};
#endif // HORAIRE_H

