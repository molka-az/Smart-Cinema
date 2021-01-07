#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"salles.h"
#include"materiels.h"
#include<QMessageBox>
#include <QMainWindow>
#include <QString>
#include<QVariant>
#include<QSqlQuery>
#include<QSqlQueryModel>

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


    void on_pb_ajoutersalle_clicked();

    void on_pb_triasalle_clicked();

    void on_pb_tridessalles_clicked();

    void on_pb_recherchesalle_clicked();

    void on_pb_modifiersalle_clicked();

    void on_pb_supprimersalle_clicked();

    void on_pb_ajoutermat_clicked();

    void on_pb_triasmat_clicked();

    void on_pb_tridesmat_clicked();

    void on_pb_recherchemat_clicked();

    void on_pb_modifmat_clicked();

    void on_pb_suppmat_clicked();

private:
    Ui::MainWindow *ui;
    salles tempSal;
    materiels tempmat;
};
#endif // MAINWINDOW_H
