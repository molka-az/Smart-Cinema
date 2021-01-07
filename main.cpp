#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connexion.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    if(c.ouvrirconnexion())
    {
        MainWindow w;
        w.show();
        qDebug() <<"Connexion réussite";
        return a.exec();
    }


        //QMessageBox::information(nullptr, QObject::tr("database is open"),
            //       QObject::tr("connexion successful.\n"
                    //            "Click Cancel to exit."), QMessageBox::Ok);


    else
       qDebug() <<"erreur de connexion";
       //QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                //  QObject::tr("connexion failed.\n"
              //                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();

}
