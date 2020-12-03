#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "profil.h"
#include<QMessageBox>
#include <QPixmap>
#include <QMovie>
#include <QMediaPlayer>
#include<QtMultimedia>
#include<QSound>
#include<QDialog>
#include<QPrintDialog>
#include<QPrinter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /*controle de saisie*/
    ui->setupUi(this);
    //employee int    age cin
ui->lineEdit_age->setValidator(new QIntValidator(100, 999, this));  // des nombres entre 100 et 999
ui->lineEdit_CIN->setValidator(new QIntValidator(100, 999, this));


//employe varchar
ui->lineEdit_nom->setMaxLength(100);
ui->lineEdit_prenom->setMaxLength(10);//controle de saisie je ne peut pas depasser les 10 lettres
ui->lineEdit_ID->setMaxLength(10);
ui->lineEdit_fonction->setMaxLength(10);

 //profile varchar
  ui->lineEdit_nomUtili->setMaxLength(10);
  ui->lineEdit_mot->setMaxLength(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user1/Documents/CRUD-MOLKA/button-8.mp3"));
       player->setVolume(100);
       player->play();

    QString ID =ui->lineEdit_ID->text();
    QString nom =ui->lineEdit_nom->text();
    QString prenom =ui->lineEdit_prenom->text();
    QString fonction=ui->lineEdit_fonction->text();

       int age =ui->lineEdit_age->text().toInt();
       int CIN =ui->lineEdit_CIN->text().toInt();



       employe e( nom,prenom, age,ID,CIN,fonction);
       bool test=e.ajouter();
               if (test)
                {   ui->tableView->setModel(e.afficher()) ;
                    QMessageBox::information(nullptr,QObject::tr("ok"),
                            QObject::tr("ajout effectue\n"
                                        "Clich cancel to exit ."),QMessageBox::Cancel );
                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                                QObject::tr("connexion failed.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

       }

void MainWindow::on_pushButton_3_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user1/Documents/CRUD-MOLKA/button-8.mp3"));
       player->setVolume(100);
       player->play();

    QString ID=ui->lineEdit_ID->text();
        bool test= e.supprimer(ID);
        if (test)
        {
            ui->tableView->setModel(e.afficher());

            QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("supression établie"),
                                 QMessageBox::Ok);}
        else{
        //qDebug()<<"connexion echouer";
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("supression non établie"),
                                QMessageBox::Cancel);}

        ui->lineEdit_ID->setText("");
        ui->lineEdit_nom->setText("");
        ui->lineEdit_prenom->setText("");
        ui->lineEdit_CIN->setText("");
        ui->lineEdit_age->setText("");
        ui->lineEdit_fonction->setText("");
}




void MainWindow::on_pushButton_MODIFIER_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user1/Documents/CRUD-MOLKA/button-8.mp3"));
       player->setVolume(100);
       player->play();

        QString nom=ui->lineEdit_nom->text();
        QString prenom=ui->lineEdit_prenom->text();
        int age=ui->lineEdit_age->text().toInt();
        QString ID=ui->lineEdit_ID->text();
        QString fonction=ui->lineEdit_fonction->text();
        int CIN=ui->lineEdit_CIN->text().toInt();

        employe e(nom,prenom, age, ID, CIN,fonction);

        bool test=e.modifier();
        if (test)
        {
            ui->tableView->setModel(e.afficher());

            QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("ajout effectue\n"
                                             "Clich cancel to exit ."),  QMessageBox::Cancel);}
        else{
        //qDebug()<<"connexion echouer";
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("modification non établie"),
                                QMessageBox::Cancel);}

}

void MainWindow::on_pushButton_7_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user1/Documents/CRUD-MOLKA/button-8.mp3"));
       player->setVolume(100);
       player->play();


    QString critere=ui->comboBox->currentText();
        QString mode;
        if (ui->checkBox_5->checkState()==false)
    {
             mode="DSC";
    }
         else if(ui->checkBox_4->checkState()==false)
         {
             mode="ASC";
         }
    ui->tableView->setModel(e.trie(critere,mode));
}
void MainWindow::on_pushButton_refresh_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user1/Documents/CRUD-MOLKA/button-8.mp3"));
       player->setVolume(100);
       player->play();

    ui->tableView->setModel(e.afficher());
}


void MainWindow::on_lineEdit_Recherche_textChanged(const QString &arg1)
{
    if(ui->lineEdit_Recherche->text() == "")
            {
                ui->tableView->setModel(e.afficher());
            }
            else
            {
                 ui->tableView->setModel(e.rechercher(ui->lineEdit_Recherche->text()));
            }
}


void MainWindow::on_pushButton_ajouter_clicked()
{
    /*sound*/
    QMediaPlayer *player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile("C:/Users/user1/Documents/CRUD-MOLKA/button-8.mp3"));
    player->setVolume(100);
    player->play();


    QString NOM_UTILI=ui->lineEdit_nomUtili->text();
    QString MOT_DE_PASSE=ui->lineEdit_mot->text();
    profil p(NOM_UTILI,MOT_DE_PASSE);

    bool test=p.modifier(NOM_UTILI, MOT_DE_PASSE);
    if (test)
    {
        ui->tableView_2->setModel(p.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("connexion effectue\n"
                                         "Clich cancel to exit ."),  QMessageBox::Cancel);}
    else{
    //qDebug()<<"connexion echouer";
    QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                            QObject::tr("connexion failed"),
                            QMessageBox::Cancel);}


}

void MainWindow::on_pushButton_modifier_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user1/Documents/CRUD-MOLKA/button-8.mp3"));
       player->setVolume(100);
       player->play();

    QString NOM_UTILI=ui->lineEdit_nomUtili->text();
        QString MOT_DE_PASSE=ui->lineEdit_mot->text();
        profil p(NOM_UTILI,MOT_DE_PASSE);

        bool test=p.modifier(NOM_UTILI, MOT_DE_PASSE);
    if (test)
    {
        ui->tableView_2->setModel(p.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("modification effectue\n"
                                         "Clich cancel to exit ."),  QMessageBox::Cancel);}
    else{
    //qDebug()<<"connexion echouer";
    QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                            QObject::tr("modification non établie"),
                            QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_supp_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user1/Documents/CRUD-MOLKA/button-8.mp3"));
       player->setVolume(100);
       player->play();

    QString NOM_UTILI=ui->lineEdit_nomUtili->text();
        bool test= p.supprimer(NOM_UTILI);
        if (test)
        {
            ui->tableView_2->setModel(p.afficher());

            QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("supression établie"),
                                 QMessageBox::Ok);}
        else{
        //qDebug()<<"connexion echouer";
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("supression non établie"),
                                QMessageBox::Cancel);}

        ui->lineEdit_nomUtili->setText("");
        ui->lineEdit_mot->setText("");

}

void MainWindow::on_pushButton_8_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user1/Documents/CRUD-MOLKA/button-8.mp3"));
       player->setVolume(100);
       player->play();

     ui->tableView_2->setModel(p.afficher());
}


void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{

    QString val =ui->tableView->model()->data(index).toString();
       QSqlQuery query;
       query.prepare("select *from PROFIL where NOM_UTILI='"+val+"' or MOT_DE_PASSE='"+val+"'");

       if(query.exec())
       { while(query.next())
           {  ui->lineEdit_nomUtili->setText(query.value(0).toString());
              ui->lineEdit_mot->setText(query.value(1).toString());
             }
       }
}



void MainWindow::on_pushButton_connecter_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user1/Documents/CRUD-MOLKA/button-8.mp3"));
       player->setVolume(100);
       player->play();


           QString email = ui->lineEdit_nomUtili->text(), pass = ui->lineEdit_nomUtili->text();
           if(email != "")
           {
               if(pass == "")
               {
                   QMessageBox::critical(nullptr,QObject::tr("Login."),QObject::tr("Le champs du mot de passe est vide !\n"));
                   ui->lineEdit_nomUtili->setText("");
               }
               else
               {
                   QString ID;
                   QSqlQuery query;
                   query.prepare("SELECT NOM from EMPOLYE where Nom d utilisateur = '"+email+"' or email = '"+email+"'");
                   query.exec();
                   while (query.next()) {
                       ID = query.value(0).toString();
                   }
                   if(	ID != "")
                   {
                       QString ID1;
                       QSqlQuery query1;
                       query1.prepare("SELECT NOM2 from EMPOLYE where Nom d utilisateur = '"+email+"' or email = '"+email+"' AND mdp = '"+pass+"'");
                       query1.exec();
                       while (query1.next()) {
                           ID1 = query1.value(0).toString();
                       }
                       if(ID1 != "")
                       {
                           QString role;
                           QSqlQuery query11;
                           query11.prepare("SELECT role from EMPLOYE where Nom d utilisateur = '"+email+"' AND mdp = '"+pass+"'");
                           query11.exec();
                           while (query11.next()) {
                               role = query11.value(0).toString();
                           }
                           close();
                       }
                       else
                       {
                           QMessageBox::critical(nullptr,QObject::tr("Nom d utilisateur."),QObject::tr("Le mot de passe est incorrecte, \nEssayez une autre fois !\n"));
                           ui->lineEdit_mot->setText("");
                       }
                   }
                   else
                   {
                       QMessageBox::critical(nullptr,QObject::tr("Login."),QObject::tr("Cet E mail n'existe pas !\n"));
                       ui->lineEdit_mot->setText("");
                       ui->lineEdit_mot->setText("");
                   }
               }
           }
           else
           {
               if(pass == "")
                   QMessageBox::critical(nullptr,QObject::tr("Nom d utilisateur."),QObject::tr("Les champs du mot de passe et du E mail \nsont vides !\n"));
               else
                   QMessageBox::critical(nullptr,QObject::tr("Nom d utilisateur."),QObject::tr("Le champs de l E mail est vide !\n"));
               ui->lineEdit_nomUtili->setText("");
               ui->lineEdit_mot->setText("");
           }
       }

void MainWindow::on_pushButton_modifier_2_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile("C:/Users/user1/Documents/CRUD-MOLKA/button-8.mp3"));
    player->setVolume(100);
    player->play();

 QString NOM_UTILI =ui->lineEdit_nomUtili->text();
 QString MOT_DE_PASSE =ui->lineEdit_mot->text();



    profil p(NOM_UTILI,MOT_DE_PASSE);
    bool test=p.ajouter();
            if (test)
             {   ui->tableView->setModel(p.afficher()) ;
                 QMessageBox::information(nullptr,QObject::tr("ok"),
                         QObject::tr("ajout effectue\n"
                                     "Clich cancel to exit ."),QMessageBox::Cancel );
             }
             else
                 QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                             QObject::tr("connexion failed.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_lineEdit_motdepasse_textChanged(const QString &arg2)
{
    if(ui->lineEdit_Recherche->text() == "")
            {
                ui->tableView->setModel(p.afficher());
            }
            else
            {
                 ui->tableView->setModel(p.mot_de_passe(ui->lineEdit_motdepasse->text()));
            }
}
