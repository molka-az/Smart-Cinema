#include "materiels.h"
materiels::materiels()
{
    nom="";
    cat="";
    nbq=0;
    ns=0;
}

materiels::materiels(std::string n,std::string c,int q,int s)
{
    nom=n;
    cat=c;
    nbq=q;
    ns=s;


}

std::string materiels::get_nom(){return nom;}
std::string materiels::get_cat(){return cat;}
int materiels::get_nbq(){return nbq;}
int materiels::get_ns(){return ns;}


materiels::~materiels()
{

}
bool materiels::ajouter_mat()
{
    QSqlQuery query;

    query.prepare("INSERT INTO tabmateriels (nom,cat,nbq,ns)""VALUES(:nom,:cat,:nbq,:ns)");
    query.bindValue(":nom",QString::fromStdString (nom));
    query.bindValue(":cat",QString::fromStdString(cat));
    query.bindValue(":ns",ns);
    query.bindValue(":nbq",nbq);

    return query.exec();
}
QSqlQueryModel * materiels::afficher_mat()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::database();
    model->setQuery("select NOM,CAT,NBR,NS FROM tabmateriels",db);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CAT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NBQ"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NS"));
    return model;
}
bool materiels::supprimer_mat(int ns)
{
    QSqlQuery query;
    query.prepare("DELETE FROM tabmateriels WHERE ns= :ns");
    query.bindValue(":ns",ns);
    return query.exec();
}
bool materiels::modifier_mat(int ns)
{
    QSqlQuery query;
    query.prepare("UPDATE tabmateriels SET  nom= :nom, cat= :cat , nbq= :nbq  WHERE ns= :ns");
    query.bindValue(":nom",QString::fromStdString(nom));
    query.bindValue(":cat",QString::fromStdString(cat));
    query.bindValue(":ns",ns);
    query.bindValue(":nbq",nbq);

    return query.exec();
}

