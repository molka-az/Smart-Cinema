#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "salles.h"
#include "materiels.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tempSal->setModel(tempSal.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajoutersalle_clicked()
{
    QString l = ui->lineEdit_lettre->text();
    int n = ui->lineEdit_nbp->text().toInt();
    QString t = ui->lineEdit_tp->text();
    salles s(l,n,t);
       s.ajouter();
    bool test = s.ajouter();
    if (test)
    {
        ui->tempSal->setModel(tempSal.afficher());
        QMessageBox::information(nullptr,"ajouter salles","salle ajouté");
    }
    else
    {
        QMessageBox::warning(nullptr,"suppression salles","salle non ajouté");
    }
}

void MainWindow::on_pb_triasalle_clicked()
{

}

void MainWindow::on_pb_tridessalles_clicked()
{

}

void MainWindow::on_pb_recherchesalle_clicked()
{

}

void MainWindow::on_pb_modifiersalle_clicked()
{

}

void MainWindow::on_pb_supprimersalle_clicked()
{
   QString ls =ui->lineEdit_supplettre->text();
   bool test=tempsalles.supprimer(ls);
   if (test)
   {
       ui->tempSal->setModel(tempSal.afficher());
       QMessageBox::information(nullptr,"supprimer salles","salle supprimé");
   }
   else
   {
       QMessageBox::warning(nullptr,"suppression salles","salle non supprimé");
   }
}

void MainWindow::on_pb_ajoutermat_clicked()
{

}

void MainWindow::on_pb_triasmat_clicked()
{

}

void MainWindow::on_pb_tridesmat_clicked()
{

}

void MainWindow::on_pb_recherchemat_clicked()
{

}

void MainWindow::on_pb_modifmat_clicked()
{

}

void MainWindow::on_pb_suppmat_clicked()
{

}
