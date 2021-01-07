#include "salles.h"
#include "QSqlRecord"
#include<QMessageBox>
#include<QSqlRecord>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include <QMessageBox>
#include<QSqlQueryModel>


salles::salles()
{

}



salles::salles(QString lettre,QString tp, int nbp)
{

    this->lettre = lettre;
    this->tp = tp;
    this->nbp = nbp;

}

bool salles::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO SALLES (lettre,tp,nbp) "
                      "VALUES (:lettre,:tp,:nbp)");
        query.bindValue(":lettre",lettre);
        query.bindValue(":tp",tp);
        query.bindValue(":nbp",nbp);


        return    query.exec();



}
QSqlQueryModel * salles ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from SALLES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("lettre"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("tp "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbp "));



        return model;
}

QSqlQueryModel *salles ::afficher1()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from SALLES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("lettre"));

        return model;
}



bool salles :: supprimer(QString lettre)
{
    QSqlQuery query;
    query.prepare("Delete from SALLES where lettre = :lettre ");
    query.bindValue(":lettre",lettre);
    return    query.exec();

}

bool salles::modifier(QString lettre, QString tp,int nbp)
{

    QSqlQuery query;

    query.prepare("UPDATE SALLES SET tp= :tp, nbp= :nbp where lettre= :lettre ");
    query.bindValue(":lettre", lettre);
    query.bindValue(":tp",tp);
    query.bindValue(":nbp",nbp);
       return    query.exec();

}


bool  salles::search(QString lettre ){
       QSqlQuery query;
           query.prepare("Select * from SALLES where lettre= :lettre");
           query.bindValue(":lettre", lettre);
           query.exec();
            QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery(query);
          if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL hedhika el 7aja mawjouda wala la
       return  true;
}
QSqlQueryModel * salles::sort(){

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from SALLES order by NBP DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("LETTRE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TP "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBP "));



        return model;
}
QSqlQueryModel * salles :: sortAsc(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from SALLES order by NBP ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("LETTRE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TP "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBP "));



        return model;
}
QSqlQueryModel * salles ::modi1()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from SALLES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("lettre"));

        return model;

}
