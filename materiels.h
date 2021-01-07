#ifndef MATERIELS_H
#define MATERIELS_H
#include <QString>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
class materiels
{
 private:
    int  id,qt;
    QString nom,cat;


public:
    materiels();
    materiels(int,int,QString,QString);
    QSqlQueryModel*afficher();
    bool ajouter();
    bool supprimer(int);
    bool modifier(int,int,QString,QString);
    int get_id();
    QString get_nom();
    QString get_cat();
    int get_qt();
  QSqlQueryModel* triermatparqt();
   QSqlQueryModel* triermatparnom();
   QSqlQueryModel* triermatparcat();
QSqlQueryModel * recherchematparnom(QString);
QSqlQueryModel * recherchematparid(int);
QSqlQueryModel* recherchematparcat(QString);


};

#endif // MATERIELS_H
