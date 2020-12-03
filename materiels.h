#ifndef MATERIELS_H
#define MATERIELS_H
#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QString>

class materielsData;

class materiels
{
public:
    materiels();
    materiels(std::string,std::string,int,int);
    ~materiels();
    std::string get_nom();
    std::string get_cat();
    int get_nbq();
    int get_ns();

    bool ajouter_mat();
    bool modifier_mat(int);
    QSqlQueryModel * afficher_mat();
    bool supprimer_mat(int);
private:


    std::string nom;
    std::string cat;
    int nbq;
    int ns;

};

#endif // MATERIELS_H
