#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "profil.h"

#include <QMainWindow>
#include<QMessageBox>
#include<QTableView>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_MODIFIER_clicked();

    void on_pushButton_7_clicked();

    void on_lineEdit_Recherche_textChanged(const QString &arg1);

    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_supp_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_refresh_clicked();

    void on_tableView_2_activated(const QModelIndex &index);




    void on_pushButton_connecter_clicked();



    void on_pushButton_modifier_2_clicked();



    void on_lineEdit_motdepasse_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    employe e;
    profil p;
};
#endif // MAINWINDOW_H
