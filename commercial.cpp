#include "commercial.h"
#include "stati.h"

#include "QString"
#include "QSqlQuery"
#include <QSqlQueryModel>
commercial::commercial()
{
    id=0;
    nom_client="";
    prenom_client="";
    type_de_facture="";
    montant=0;
    date="";


}
commercial::commercial(int id,QString nom_client,QString prenom_client,QString type_de_facture,int montant,QString date)
{
  this->id=id;
  this->nom_client=nom_client;
  this->prenom_client=prenom_client;
  this->date=date;
   this->montant=montant;
     this->type_de_facture=type_de_facture;


}
QString commercial::get_nom_client(){return nom_client;}
QString commercial::get_prenom_client(){return prenom_client;}

QString commercial::get_type_de_facture(){return  type_de_facture;}
QString commercial::get_date(){return  date;}
int  commercial::get_montant(){return  montant;}
int commercial::get_id(){return  id;}


bool commercial::ajouter()
{
QSqlQuery query;



query.prepare("INSERT INTO commercial (ID, nom_client, prenom_client,montant,type_de_facture,Datee) "
                    "VALUES (:id, :nom_client,:prenom_client,:montant,:type_de_facture,:date)");
query.bindValue(":id", id);
query.bindValue(":nom_client", nom_client);
query.bindValue(":prenom_client", prenom_client);
query.bindValue(":montant", montant);
query.bindValue(":type_de_facture", type_de_facture);
query.bindValue(":date", date);



return    query.exec();
}
bool commercial::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from commercial where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel * commercial::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMERCIAL");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CLIENT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_CLIENT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_DE_FACTURE"));
model->setHeaderData(4,Qt::Horizontal, QObject::tr("MONTANT"));
model->setHeaderData(5,Qt::Horizontal, QObject::tr("DATEE"));



    return model;
}
QSqlQueryModel * commercial::trier_horaire_asc()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMERCIAL order by ID ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CLIENT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_CLIENT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_DE_FACTURE"));
model->setHeaderData(4,Qt::Horizontal, QObject::tr("MONTANT"));
model->setHeaderData(5,Qt::Horizontal, QObject::tr("DATEE"));

    return model;
}
QSqlQueryModel * commercial::trier_horaire_desc()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMERCIAL order by ID DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CLIENT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_CLIENT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_DE_FACTURE"));
model->setHeaderData(4,Qt::Horizontal, QObject::tr("MONTANT"));
model->setHeaderData(5,Qt::Horizontal, QObject::tr("DATEE"));

    return model;
}
bool  commercial::search(int id )
{
       QSqlQuery query;
           query.prepare("Select * from commercial where id= :id");
           query.bindValue(":id", id);
           query.exec();
            QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery(query);
          if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
       return  true;
}
bool commercial::modifier(int id,QString colonne,QString nouv){

    QSqlQuery query;
QString select;
if(colonne=="nom_client"){
        query.prepare("update nom_client set nom_client=:nouv where id=:id ");
        query.bindValue(":nouv",nouv);
        query.bindValue(":id",id);

}
if(colonne=="prenom_client"){
        query.prepare("update prenom_client set prenom_client=:nouv   where id =:id");
        query.bindValue(":nouv",nouv);
        query.bindValue(":id",id);
}
if(colonne=="type_de_facture"){
        query.prepare("update type_de_facture set type_de_facture=:nouv  where id =:id");
        query.bindValue(":nouv",nouv);
        query.bindValue(":id",id);
}



return query.exec();

}
