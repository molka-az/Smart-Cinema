#ifndef YOUSSEF_H
#define YOUSSEF_H
#include"horaire.h"
#include"commercial.h"


#include <QDialog>
#include "QSystemTrayIcon"

namespace Ui {
class youssef;
}

class youssef : public QDialog
{
    Q_OBJECT

public:
    explicit youssef(QWidget *parent = nullptr);
    ~youssef();

private slots:


    void on_pushButton_clicked();


    void on_pushButton_5_clicked();


    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_9_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::youssef *ui;
    QSystemTrayIcon * mysysteme;
    horaire tabH;
    commercial tabc;

};

#endif // YOUSSEF_H
