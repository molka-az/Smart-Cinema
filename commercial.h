#ifndef COMMERCIAL.H
#define COMMERCIAL.H
#include "QString"
#include "QSqlQuery"
#include <QSqlQueryModel>



class commercial{
public:
    commercial();
    commercial(int,QString,QString,QString,int,QString);
    QString get_nom_client();
    QString get_prenom_client();
    QString get_type_de_facture();
    QString get_date();
    int get_id();
    int get_montant();
     bool ajouter();

     bool supprimer(int);
      QSqlQueryModel * afficher();
      bool modifier(int id,QString colonne,QString nouv);
      bool  search(int id );
      QSqlQueryModel * trier_horaire_asc();
       QSqlQueryModel * trier_horaire_desc();








private:
    int id;
    int montant;
    QString date;
    QString nom_client;
   QString prenom_client;
   QString type_de_facture;


};
#endif // COMMERCIAL.H
