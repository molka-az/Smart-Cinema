#include "materiels.h"
#include "salles.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>
materiels::materiels()
{
id=0;
nom="";
cat="";
qt=0;
}
materiels::materiels(int id ,int qt,QString nom ,QString cat )
{

    this->id=id; this->nom=nom; this->cat=cat; this->qt=qt;
}

QString materiels::get_nom(){return  nom;}
QString materiels::get_cat(){return cat;}
int materiels::get_qt(){return qt;}
int materiels::get_id(){return  id;}

bool materiels::ajouter()
{
  QSqlQuery query;
   QString res=QString::number(id);

   query.prepare("INSERT INTO MATERIELS (id,nom,cat,qt) " "VALUES (:id,:nom,:cat,:qt,);");

          query.bindValue(":id",id);
          query.bindValue(":nom",nom);
          query.bindValue(":cat", cat);
          query.bindValue(":qt", qt);

         return query.exec();

}
bool materiels::modifier(int id ,int qt,QString cat,QString nom)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE MATERIELS SET nom=:nom,cat=:cat,qt=:qt WHERE id =:id");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":cat",cat);
    query.bindValue(":qt",qt);


    return query.exec();
}







QSqlQueryModel* materiels::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM MATERIELS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("cat"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("qt"));


   return  model;

}
bool materiels::supprimer (int id)
{
 QSqlQuery query;
 QString res=QString::number(id);
 query.prepare("Delete from MATERIELS where id=:id");
  query.bindValue(":id",id);

    return query.exec();

}
QSqlQueryModel * materiels::triermatparqt()
{
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM reclamations ORDER BY qt des ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("cat"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("qt"));

        return model ;
    }

}
QSqlQueryModel * materiels::triermatparnom()
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM MATERIELS ORDER BY nom asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cat"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("qt"));

    return model ;



}
QSqlQueryModel * materiels::triermatparcat()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM MATERIELS ORDER BY cat asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cat"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("qt"));

    return model ;



}
QSqlQueryModel * materiels::recherchematparid(int id)
 {

    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM MATERIELS WHERE id=: id");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("cat"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("qt"));

        return model ;


 }
QSqlQueryModel* materiels::recherchematparnom(QString nom)
{
    QSqlQueryModel *model = new QSqlQueryModel;
   model->setQuery("SELECT * FROM MATERIELS WHERE (nom LIKE '"+nom+"')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de depot"));


   return model;
}
QSqlQueryModel* materiels::recherchematparcat(QString cat)
{
    QSqlQueryModel *model = new QSqlQueryModel;
   model->setQuery("SELECT * FROM MATERIELS WHERE (cat LIKE '"+cat+"')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cat"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("qt"));


   return model;
}
