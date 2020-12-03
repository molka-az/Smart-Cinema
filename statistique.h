#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMainWindow>

#include <QDialog>

#include <QApplication>
using namespace std;


namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    int Statistique_partie2() ;
    int Statistique_partie3() ;
    int Statistique_partie4() ;


    ~statistique();

private slots:
    void on_pushButton_clicked();

private:
    Ui::statistique *ui;
};


#endif // STATISTIQUE_H
