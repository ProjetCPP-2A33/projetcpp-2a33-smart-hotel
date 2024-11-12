#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouterButton_clicked();
    void on_supprimerButton_clicked();
    void on_modifierButton_clicked();
    void on_rechercherButton_clicked();
    void on_trierButton_clicked();
    void on_statistiqueButton_clicked();
    void on_statistiqueButton_2_clicked();
    void on_pb_pdf_clicked();

private:
    Ui::MainWindow *ui;
    Service serviceModel;
};

#endif // MAINWINDOW_H
