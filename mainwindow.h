#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();         // Slot for adding a service
    void on_updateButton_clicked();      // Slot for updating a service
    void on_deleteButton_clicked();      // Slot for deleting a service
    void on_displayButton_clicked();     // Slot for displaying services in the table view
    void on_sortByPriceButton_clicked(); // Slot for sorting services by price

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;               // Model for displaying data in the table view
};

#endif // MAINWINDOW_H
