#include "mainwindow.h"
#include "service.h"
#include <QMessageBox>

void MainWindow::on_addButton_clicked() {
    int id = ui->idEdit->text().toInt();
    QString name = ui->nameEdit->text();
    double price = ui->priceEdit->text().toDouble();
    bool available = ui->availabilityEdit->text() == "Yes";

    Service service(id, name, price, available);
    if(service.add()) {
        QMessageBox::information(this, "Success", "Service added successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to add service.");
    }
}

void MainWindow::on_deleteButton_clicked() {
    int id = ui->idEdit->text().toInt();
    Service service;
    if(service.remove(id)) {
        QMessageBox::information(this, "Success", "Service deleted successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to delete service.");
    }
}

void MainWindow::on_updateButton_clicked() {
    int id = ui->idEdit->text().toInt();
    QString name = ui->nameEdit->text();
    double price = ui->priceEdit->text().toDouble();
    bool available = ui->availabilityEdit->text() == "Yes";

    Service service(id, name, price, available);
    if(service.update(id)) {
        QMessageBox::information(this, "Success", "Service updated successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to update service.");
    }
}

void MainWindow::on_displayButton_clicked() {
    ui->tableView->setModel(Service::displayAll());
}
