#include "connexion.h"

Connexion::Connexion(){

}

bool Connexion::createconnect(){
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("base");
    db.setUserName("SMARTCINE");//inserer nom de l'utilisateur
    db.setPassword("SMARTCINE");//inserer mot de passe de cet utilisateur
    if (db.open()) test=true;
    return  test;
}
