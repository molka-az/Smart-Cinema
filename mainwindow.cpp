#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "salles.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *agence) :
    QMainWindow(agence),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabsalles->setModel(tmpsalles.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int nb = ui->lineEdit_nb->text().toInt();
     QString lettre = ui->lineEdit_lettre->text();
      QString type = ui->lineEdit_type->text();



  salles e(nb,lettre,type);
  bool test=e.ajouter();
  if(test)
{ui->tabsalles->setModel(tmpsalles.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une salle"),
                  QObject::tr("salle ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une salle"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
QString lettre = ui->lineEdit_lettre->text();
bool test=tmpsalles.supprimer(id);
if(test)
{ui->tabsalles->setModel(tmpsalles.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une salle"),
                QObject::tr("salle supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une salle"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


