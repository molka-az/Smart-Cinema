#include "connexion.h"
#include "QSqlDatabase"


// test tuto git
//test pull requeqt


connexion::connexion(){}

bool connexion::ouvrirconnexion()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-bd");
    db.setUserName("system");//inserer nom de l'utilisateur
    db.setPassword("system");//inserer mot de passe de cet utilisateur
    if (db.open()) test=true;
    return  test;


}
      void connexion::fermerconnexion()
      {db.close();}
