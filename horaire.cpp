#include "horaire.h"
#include "stati.h"

#include "QString"
#include "QSqlQuery"
#include <QSqlQueryModel>





horaire::horaire()
{
}



horaire::horaire(int id,QString nom,QString prenom,int cin,int jours_off,int HT)
{this->id=id;
 this->nom=nom;
 this->prenom=prenom;
 this->cin=cin;

 this->Jours_off=jours_off;
    this->HT=HT;
  }

int horaire::get_id(){return id;}
QString horaire::get_nom(){return  nom;}
QString horaire::get_prenom(){return  prenom;}
int horaire::get_cin(){return  cin;}
int horaire::get_Jours_off(){return  Jours_off;}
int horaire::get_HT(){return HT;}


bool horaire::ajouter(){
  QSqlQuery query;

  query.prepare("INSERT INTO HORAIRE (ID, NOM, PRENOM, CIN, HT, Jours_off) "
                "VALUES (:id, :nom,:prenom,:cin,:HT, :Jours_off)");
                          query.bindValue(":id",id);
                           query.bindValue(":nom",nom);
                           query.bindValue(":prenom",prenom);
                           query.bindValue(":cin",cin);
                           query.bindValue(":Jours_off",Jours_off);
                           query.bindValue(":HT",HT);

                   return query.exec();
           }
bool horaire::supprimer(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM horaire where ID= :id");
            query.bindValue(":id",id);
    return query.exec();

}
QSqlQueryModel  * horaire:: afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from horaire");
    model->setHeaderData(1,Qt::Vertical,QObject::tr("id"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("nom"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("prenom"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("cin"));
    model->setHeaderData(5,Qt::Vertical,QObject::tr("Jours_off"));
    model->setHeaderData(6,Qt::Vertical,QObject::tr("HT"));
return model;


}
bool horaire::modifier(int id,QString colonne,QString nouv){

    QSqlQuery query;
QString select;
if(colonne=="nom"){
        query.prepare("update horaire set nom=:nouv where id=:id ");
        query.bindValue(":nouv",nouv);
        query.bindValue(":id",id);

}
if(colonne=="prenom"){
        query.prepare("update horaire set prenom=:nouv   where id =:id");
        query.bindValue(":nouv",nouv);
        query.bindValue(":id",id);
}
if(colonne=="cin"){
        query.prepare("update cin set cin=:nouv  where id =:id");
        query.bindValue(":nouv",nouv);
        query.bindValue(":id",id);
}
if(colonne=="jours_off"){
        query.prepare("update jours_off set jours_off=:nouv  where id =:id");
        query.bindValue(":nouv",nouv);
        query.bindValue(":id",id);
}


return query.exec();

}

QSqlQueryModel * horaire::trier_horaire_asc()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * from horaire ORDER BY NOM ASC");
model->setHeaderData(1,Qt::Vertical,QObject::tr("id"));
model->setHeaderData(2,Qt::Vertical,QObject::tr("nom"));
model->setHeaderData(3,Qt::Vertical,QObject::tr("prenom"));
model->setHeaderData(4,Qt::Vertical,QObject::tr("cin"));
model->setHeaderData(5,Qt::Vertical,QObject::tr("age"));
model->setHeaderData(5,Qt::Vertical,QObject::tr("num"));
return model;
}
QSqlQueryModel * horaire::trier_horaire_desc()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * from horaire ORDER BY NOM DESC");
model->setHeaderData(1,Qt::Vertical,QObject::tr("id"));
model->setHeaderData(2,Qt::Vertical,QObject::tr("nom"));
model->setHeaderData(3,Qt::Vertical,QObject::tr("prenom"));
model->setHeaderData(4,Qt::Vertical,QObject::tr("cin"));
model->setHeaderData(5,Qt::Vertical,QObject::tr("age"));
model->setHeaderData(5,Qt::Vertical,QObject::tr("num"));
return model;
}


bool  horaire::search(int id )
{
       QSqlQuery query;
           query.prepare("Select * from horaire where id= :id");
           query.bindValue(":id", id);
           query.exec();
            QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery(query);
          if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
       return  true;
}
