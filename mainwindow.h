#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "salles.h"
#include "materiels.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *agence = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();



    void on_pb_ajouter_mat_clicked();
    void on_pb_supp_mat_clicked();
    void on_pb_modif_mat_clicked();

    void on_pb_trier_clicked();
    void on_pb_recherche_clicked();

private:
    Ui::MainWindow *ui;
    salles tmpsalles;
    materiels tmpmateriels;

};

#endif // MAINWINDOW_H
