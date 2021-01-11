#include "youssef.h"
#include "ui_youssef.h"
#include "QMessageBox"
#include "stati.h"
#include "commercial.h"
#include "horaire.h"
#include<QTableView>
#include<QSqlQueryModel>



youssef::youssef(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::youssef)
{
    ui->setupUi(this);
    ui->tableView->setModel(tabH.afficher());
    mysysteme=new QSystemTrayIcon(this);
    mysysteme->setIcon(QIcon(":/icon.png"));
    mysysteme->setVisible(true);
}

youssef::~youssef()
{
    delete ui;
}





void youssef::on_pushButton_clicked()

{

    horaire g (ui->lineEdit_5->text().toUInt(),ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_6->text().toUInt(),ui->lineEdit_3->text().toUInt(),ui->lineEdit_4->text().toUInt());
      g.ajouter();
       // ui->tableView->setModel(tabH.afficher());
}

void youssef::on_pushButton_5_clicked()
{
    horaire g;
    ui->tableView->setModel(g.afficher());
    ui->tableView_2->setModel(tabc.afficher());

}

void youssef::on_pushButton_2_clicked()
{ horaire g ;
    QString colonne=ui->comboBox->currentText();
    QString nouv=ui->lineEdit_11->text();
    int id=ui->lineEdit_7->text().toUInt();
    bool test=g.modifier(id,colonne,nouv);
            if(test){
                QMessageBox::information(this, "modifier", "modification effectuer ");

               }
            else
                QMessageBox::information(this, "modifier", "echec ");
}

void youssef::on_comboBox_activated(const QString &arg1)
{
    ui->comboBox->currentText();
}


void youssef::on_pushButton_3_clicked()
{
   horaire g;
      int id=ui->lineEdit_7->text().toUInt();
        bool test=g.supprimer(id);
                if(test){
                    QMessageBox::information(this, "sup", "sup effectuer ");

                   }
                else
                    QMessageBox::information(this, "sup", "echec ");
}

void youssef::on_pushButton_6_clicked()
{
    bool q=tabH.search(ui->lineEdit_7->text().toUInt());

       if( q == true){
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Found ! cette Agence existe deja."),
                               QMessageBox::Ok);

       }else{
           QMessageBox::information(nullptr,QObject::tr("not OK"),
                                QObject::tr("Not Found ! cette Agence n'existe pas"),
                                QMessageBox::Ok);
       }

}

void youssef::on_pushButton_7_clicked()
{
    horaire * g = new horaire(ui->lineEdit_5->text().toUInt(),ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_6->text().toUInt(),ui->lineEdit_3->text().toUInt(),ui->lineEdit_4->text().toUInt());
    if(ui->radioButton->isChecked()){
       ui->tableView->setModel(g->trier_horaire_asc());
    }
    if(ui->radioButton_2->isChecked()){
         ui->tableView->setModel(g->trier_horaire_desc());   }
    delete g;
}

void youssef::on_pushButton_8_clicked()
{
    commercial c (ui->lineEdit_12->text().toUInt(),ui->lineEdit_8->text(),ui->lineEdit_9->text(),ui->lineEdit_13->text(),ui->lineEdit_10->text().toUInt(),ui->lineEdit_14->text());
      c.ajouter();
       // ui->tableView->setModel(tabH.afficher());
}

void youssef::on_pushButton_12_clicked()
{
 commercial c;
 ui->tableView_2->setModel(c.afficher());
}

void youssef::on_pushButton_9_clicked()
{
    commercial c ;
        QString colonne=ui->comboBox_2->currentText();
        QString nouv=ui->lineEdit_16->text();
        int id=ui->lineEdit_15->text().toUInt();
        bool test=tabc.modifier(id,colonne,nouv);
                if(test){
                    QMessageBox::information(this, "modifier", "modification effectuer ");

                   }
                else
                {
                    QMessageBox::information(this, "modifier", "echec ");

                }
}

/*void youssef::on_comboBox_3_activated(const QString &arg1)
{
    ui->comboBox_3->currentText();
}*/

void youssef::on_pushButton_10_clicked()
{
    commercial c;
       int id=ui->lineEdit_15->text().toUInt();
         bool test=c.supprimer(id);
                 if(test){
                     QMessageBox::information(this, "sup", "sup effectuer ");

                    }
                 else
                     QMessageBox::information(this, "sup", "echec ");
}

void youssef::on_pushButton_13_clicked()
{
    bool q=tabc.search(ui->lineEdit_15->text().toUInt());

       if( q == true){
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Found ! cette Agence existe deja."),
                               QMessageBox::Ok);

       }else{
           QMessageBox::information(nullptr,QObject::tr("not OK"),
                                QObject::tr("Not Found ! cette Agence n'existe pas"),
                                QMessageBox::Ok);
       }

}

void youssef::on_pushButton_14_clicked()
{
    commercial * c = new commercial(ui->lineEdit_12->text().toUInt(),ui->lineEdit_8->text(),ui->lineEdit_9->text(),ui->lineEdit_13->text(),ui->lineEdit_10->text().toUInt(),ui->lineEdit_14->text());
    if(ui->radioButton_3->isChecked()){
       ui->tableView_2->setModel(c->trier_horaire_asc());
    }
    if(ui->radioButton_4->isChecked()){
         ui->tableView_2->setModel(c->trier_horaire_desc());   }
    delete c;
}

void youssef::on_comboBox_2_activated(const QString &arg1)
{
    ui->comboBox_2->currentText();
}
