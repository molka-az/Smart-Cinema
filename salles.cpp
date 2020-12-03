#include "salles.h"
#include <QDebug>

salles::salles()
{
    lettre="";
    id=0;
    type="";

}

salles::salles(std::string l,int nb,std::string t)
{
    nb=nb;
    lettre=l;
    type=t;
}


int salles::get_nb()
{
    return nb;
}

std::string salles::get_lettre()
{
    return lettre;
}

std::string salles::get_type()
{
    return type;
}


bool salles::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO tabsalles (lettre,nb,type)""VALUES(:lettre,:nb,:typee)");
    query.bindValue(":lettre",QString::fromStdString(lettre));
    query.bindValue(":nb",nb);
    query.bindValue(":type",QString::fromStdString(type));

    return query.exec();
}

QSqlQueryModel * salles::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::database();
    model->setQuery("select * from salles");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("lettre"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nb "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    return model;
}

bool salles::supprimer(std::string lettre)
{
    QSqlQuery query;
    query.prepare("DELETE FROM tabsalles WHERE lettre= :lettre");
    query.bindValue(":lettre",lettre);
    return query.exec();
}

bool salles::modifier(std::string lettre)
{
    QSqlQuery query;
    query.prepare("UPDATE tabsalles SET  nb= :nb, type= :type WHERE lettre= :lettre");
    qDebug() << "salle modifier avec succee" ;
    query.bindValue(":lettre",QString::fromStdString(lettre));
    query.bindValue(":nb",nb);
    query.bindValue(":type",QString::fromStdString(type)) ;

    return query.exec();
}


QSqlQueryModel * salles::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM salles ORDER BY nb");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("lettre"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nb"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));

    return model;
}

