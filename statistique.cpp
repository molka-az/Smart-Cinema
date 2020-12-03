#include "statistique.h"


statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}


int statistique::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from ETUDIANT where ID BETWEEN '21' AND '31'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int statistique::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from ETUDIANT where ID BETWEEN '41' AND '100'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int statistique::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from ETUDIANT where ID BETWEEN '10' AND '40'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}

void statistique::on_pushButton_clicked()
{
    hide();
}
