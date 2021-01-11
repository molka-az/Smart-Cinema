#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etudiant.h"
#include "QMessageBox"
#include "stati.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mysysteme=new QSystemTrayIcon(this);
    mysysteme->setIcon(QIcon(":/icon.png"));
    mysysteme->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int i=ui->lineEdit->text().toInt();
    QString nom_c=ui->lineEdit_2->text();
    QString prenom_ct=ui->lineEdit_3->text();
    int mont=ui->lineEdit_4->text().toInt();
    QString type_de_fac=ui->lineEdit_5->text();
    QString dat=ui->lineEdit_6->text();
  commercial g(i,nom_c,prenom_ct,dat,mont,type_de_fac);
bool test=g.ajouter();
  if(test)
{

mysysteme->showMessage(tr("notification"),tr("ajout avec succes"));
QMessageBox::information(nullptr, QObject::tr("Ajouter un groupe de client"),
                  QObject::tr("groupe de client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      mysysteme->showMessage(tr("critical"),tr("erreur"));
      QMessageBox::critical(nullptr, QObject::tr("ajouter un groupe de client "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    int id= ui->lineEdit->text().toInt();
    commercial e;
    bool test=e.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un groupe de client"),
                    QObject::tr("groupe de client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un groupe de client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()
{

    commercial e;
    ui->tableView->setModel(e.afficher());
}

void MainWindow::on_pushButton_4_clicked()
{
    commercial e;
    ui->tableView->setModel(e.tri_par_id());
}

void MainWindow::on_pushButton_5_clicked()
{
    int id = ui->lineEdit_4->text().toInt();
commercial e;
bool test=true;
if(test==true)
{

ui->tableView->setModel(e.chercher(id));
QMessageBox::information(nullptr, QObject::tr("chercher un client"),
                  QObject::tr("client existe.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

}

void MainWindow::on_pushButton_6_clicked()
{
    stati s;
    s.exec();
}

void MainWindow::on_pushButton_7_clicked()
{

    QString nom=ui->lineEdit_2->text();
    int id=ui->lineEdit->text().toInt();
   QString prenom=ui->lineEdit_3->text();
  commercial e(id,nom,prenom);
  bool test=e.update();
  if(test)
{


QMessageBox::information(nullptr, QObject::tr("Ajouter un groupe de client"),
                  QObject::tr("groupe de client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("ajouter un groupe de client "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
