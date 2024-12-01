#include "Employe.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include "qrcode.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    serialPort(new QSerialPort(this)) // Initialisation du port série
{
    ui->setupUi(this);

    // Initialisation du port série


    QSqlQueryModel *model = afficherCheckIn();
    ui->tab_affich_E_2->setModel(model);

    // Style the table view for better visibility
    styleTableView(ui->tab_affich_E_2);

    initSerialPort();
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::styleTableView(QTableView *tableView) {
    // Set the section resize mode to ResizeToContents
    int columnCount = tableView->model()->columnCount();
    for (int i = 0; i < columnCount; ++i) {
        tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    }

    // Set custom style for the table view
    tableView->setStyleSheet("QTableView {"
                             "    gridline-color: #dcdcdc;"           // Color for grid lines
                             "    selection-background-color: #87ceeb;"  // Selection background color
                             "    background-color: #f9f9f9;"         // Background color
                             "    alternate-background-color: #f1f1f1;" // Alternate row background color
                             "    font-size: 12px;"                    // Font size
                             "    border: 1px solid #ccc;"             // Border around the table
                             "    padding: 5px;"                       // Padding inside the table
                             "}");

    // Enable alternating row colors
    tableView->setAlternatingRowColors(true);

    // Optionally, resize rows to fit content
    tableView->resizeRowsToContents();

    // Call resizeColumnsToContents after data is loaded
    tableView->resizeColumnsToContents();
}



void MainWindow::initSerialPort()
{
    bool arduino_is_available;
    QString arduino_port_name;
    // recherche du port sur lequel la carte arduino identifiée par 3  arduino_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
            if(serial_port_info.vendorIdentifier() == 9025 && serial_port_info.productIdentifier() == 67) {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
            }
        }
    }
    qDebug() << "arduino_port_name is :" << arduino_port_name;
    // Configurez ici votre port série (par exemple, COM3 sur Windows ou /dev/ttyUSB0 sur Linux)
    serialPort->setPortName(arduino_port_name);  // Changez-le selon votre système
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    // Vérifiez si le port est ouvert
    if (serialPort->open(QIODevice::ReadOnly)) {
        qDebug() << "Port série ouvert avec succès.";
    } else {
        qDebug() << "Échec de l'ouverture du port série.";
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le port série.");
    }
}

void MainWindow::readSerialData()
{
    // Accumulate data from the serial port into a buffer
    static QString serialBuffer; // Static to persist across function calls
    serialBuffer += QString::fromUtf8(serialPort->readAll()); // Append new data to the buffer

    // Check if the buffer contains a complete UID (terminated by '\n')
    if (serialBuffer.contains("\n")) {
        // Split the buffer by the delimiter
        QStringList messages = serialBuffer.split("\n", Qt::SkipEmptyParts);

        for (const QString &message : messages) {
            QString uid = message.trimmed(); // Clean up the UID

            // Process the UID only if it's valid and not empty
            if (!uid.isEmpty()) {
                qDebug() << "UID reçu :" << uid;

                // Check if the employee exists and handle check-in
                handleCheckIn(uid);
                QSqlQueryModel *model = afficherCheckIn();
                ui->tab_affich_E_2->setModel(model);
            }
        }

        // Clear the buffer after processing
        serialBuffer.clear();
    }
}

void MainWindow::handleCheckIn(const QString &uid)
{
    // Check if the employee exists in the Employee table
    QSqlQuery checkEmployeeQuery;
    checkEmployeeQuery.prepare("SELECT COUNT(*) FROM Employee WHERE ID_E = :id_e");
    checkEmployeeQuery.bindValue(":id_e", uid); // Bind the UID as the employee ID

    if (checkEmployeeQuery.exec()) {
        checkEmployeeQuery.next();
        if (checkEmployeeQuery.value(0).toInt() > 0) { // Employee exists
            qDebug() << "Employee found, proceeding with check-in.";
            afficherEmployeParUID(uid); // Display employee information

            // Format the current date and time as a string
            QString formattedDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

            // Get the last ID from the EmployeeCheckIn table
            QSqlQuery lastIdQuery;
            lastIdQuery.prepare("SELECT MAX(ID) FROM EmployeeCheckIn");

            int newId = 1; // Default to 1 if no entries exist
            if (lastIdQuery.exec() && lastIdQuery.next()) {
                QVariant lastIdValue = lastIdQuery.value(0);
                if (!lastIdValue.isNull()) {
                    newId = lastIdValue.toInt() + 1; // Increment the last ID
                }
            } else {
                qDebug() << "Error retrieving last ID: " << lastIdQuery.lastError().text();
                return; // Exit if we can't fetch the last ID
            }

            // Insert the check-in record into the EmployeeCheckIn table
            QSqlQuery insertQuery;
            insertQuery.prepare("INSERT INTO EmployeeCheckIn (ID, id_e, check_in_date) VALUES (:id, :id_e, :check_in_date)");
            insertQuery.bindValue(":id", newId);            // Bind the new incremented ID
            insertQuery.bindValue(":id_e", uid);            // Bind the UID as the employee ID
            insertQuery.bindValue(":check_in_date", formattedDateTime); // Bind the formatted date and time as a string

            if (insertQuery.exec()) {
                qDebug() << "Check-in record added successfully with ID: " << newId << " and date: " << formattedDateTime;
            } else {
                qDebug() << "Error adding check-in record: " << insertQuery.lastError().text();
            }
        } else {
            qDebug() << "Employee not found.";
            QMessageBox::warning(this, "Erreur", "Aucun employé trouvé avec cet ID !");
        }
    } else {
        qDebug() << "Error checking employee existence: " << checkEmployeeQuery.lastError().text();
    }
}




void MainWindow::afficherEmployeParUID(const QString& uid)
{
    QSqlQuery query;
    query.prepare("SELECT Nome, Prenom FROM EMPLOYEE WHERE ID_E = :id");
    query.bindValue(":id", uid);  // Binding the uid value correctly to the query

    qDebug() << "The ID being sent is:" << uid;

    if (query.exec()) {
        if (query.next()) {  // Ensure there is a valid row in the result set
            QString nome = query.value("Nome").toString();    // Fetch the 'Nome' column
            QString prenom = query.value("Prenom").toString(); // Fetch the 'Prenom' column

            // Display the values in the labels
            ui->label_nome->setText(nome);
            ui->label_prenom->setText(prenom);
        } else {
            QMessageBox::warning(this, "Erreur", "Aucun employé trouvé pour cet UID.");
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors de l'exécution de la requête SQL.");
    }

}

// Refresh table with data from the database
void MainWindow::refreshTable()
{
    Employe E;
    QSqlQueryModel *model = E.afficher();
    ui->tab_affich_E->setModel(model);  // Set the model for the QTableView
}
QSqlQueryModel* MainWindow::afficherCheckIn()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // Set the query to fetch data from the EmployeeCheckIn table
    model->setQuery("SELECT * FROM EmployeeCheckIn");

    // Set header data for each column
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Employee ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Check-in Date"));

    return model;
}

// Add Employee
void MainWindow::on_ajouter_clicked()
{
    qDebug() << "Bouton Ajouter cliqué.";
    QString id_e = ui->ide->text();  // Change to QString
    int numero = ui->numero->text().toInt();
    int salaire = ui->salaire->text().toInt();
    QString nome = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString datenaissancee = ui->datenaissance->text();

    Employe M(id_e, nome, prenom, salaire, numero, datenaissancee);
    bool test = M.ajouter();

    if (test) {
        QMessageBox::information(this, QObject::tr("Succès"), QObject::tr("Ajout effectué.\n"), QMessageBox::Ok);
        refreshTable();  // Refresh the table after adding
    } else {
        QMessageBox::critical(this, QObject::tr("Échec"), QObject::tr("Ajout non effectué.\n"), QMessageBox::Ok);
    }
}

void MainWindow::on_stats_clicked()
{
    QLayoutItem* item;
    while ((item = ui->verticalLayout->layout()->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    QChartView *chartView = nullptr;

    chartView = E.createSalaireDistributionChart();

    // Add the chart view to the layout if it was successfully created
    if (chartView != nullptr) {
        ui->verticalLayout->layout()->addWidget(chartView);
    }
}

void MainWindow::on_pushButton_afficher_2_clicked()
{
    E.exportDataToPDF();
}

void MainWindow::on_comboBox_critereRech_2_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel* sortedModel = E.trier(arg1);

    // Assuming you have a QTableView named tableView in your MainWindow UI to display the sorted data
    ui->tab_affich_E->setModel(sortedModel);
}

void MainWindow::on_pushButton_afficher_clicked()
{
    QSqlQueryModel *model = E.afficher();
    ui->tab_affich_E->setModel(model);
}

void MainWindow::on_lineEdit_critereRecherche_textChanged(const QString &arg1)
{
    QString selectedOption = ui->comboBox_critereRecherche->currentText(); // Get the selected search option

    if (arg1.isEmpty() && ui->lineEdit_critereRecherche->hasFocus() && !ui->lineEdit_critereRecherche->hasSelectedText()) {
        ui->tab_affich_E->setModel(E.afficher());
        ui->lineEdit_critereRecherche->setToolTip("Entrez un critère de recherche");
        return; // Exit early if there's no input
    }

    // Call the rechercher function with the selected option and input value
    ui->tab_affich_E->setModel(E.rechercher(selectedOption, arg1));
    ui->tab_affich_E->clearSelection(); //annuler la selection
}

void MainWindow::on_QrCode_clicked()
{
    using namespace qrcodegen;

    QString value = ui->qr_code_bar->text(); // Récupérer la valeur du QR code (ID de l'employé)

    if (value.isEmpty()) {
        // Afficher un message d'erreur si le champ du QR code est vide
        QMessageBox::warning(this, "Erreur", "Le champ du QR Code ne peut pas être vide !");
    } else {
        QString id = value;  // Treat as QString

        // Vérifier si l'ID existe dans la base de données
        QSqlQuery query;
        query.prepare("SELECT NOME, PRENOM, SALAIRE, NUMERO, DATENAISSANCEE FROM EMPLOYEE WHERE ID_E = :id");
        query.bindValue(":id", id);

        if (query.exec() && query.next()) {
            // Récupérer les informations de l'employé
            QString nome = query.value("NOME").toString();
            QString prenom = query.value("PRENOM").toString();
            int salaire = query.value("SALAIRE").toInt();
            int numero = query.value("NUMERO").toInt();
            QString datenaissancee = query.value("DATENAISSANCEE").toString();

            // Créer le texte du QR code avec les informations de l'employé
            QString text = QString("Employé: %1 %2\nSalaire: %3\nNuméro: %4\nDate de Naissance: %5")
                               .arg(nome).arg(prenom).arg(salaire).arg(numero).arg(datenaissancee);

            // Générer le QR code avec ces informations
            QrCode qr = QrCode::encodeText(text.toUtf8().data(), QrCode::Ecc::MEDIUM);

            qint32 sz = qr.getSize();
            QImage im(sz, sz, QImage::Format_RGB32);
            QRgb black = qRgb(9, 13, 12);
            QRgb white = qRgb(255, 255, 255);

            // Créer l'image du QR code
            for (int y = 0; y < sz; y++) {
                for (int x = 0; x < sz; x++) {
                    im.setPixel(x, y, qr.getModule(x, y) ? black : white);
                }
            }

            // Afficher l'image du QR code dans le label
            ui->qrcodecommande_2->setPixmap(QPixmap::fromImage(im.scaled(200, 200, Qt::KeepAspectRatio, Qt::FastTransformation)));
        } else {
            // Si l'employé n'existe pas dans la base de données
            QMessageBox::warning(this, "Erreur", "L'employé avec cet ID n'existe pas !");
        }
    }
}

void MainWindow::on_modifier_clicked()
{
    qDebug() << "Bouton Modifier cliqué.";
    QString id_e = ui->ide_modif->text();  // Change to QString
    int numero = ui->numero_modif->text().toInt();
    int salaire = ui->salaire_modif->text().toInt();
    QString nome = ui->nom_modif->text();
    QString prenom = ui->prenom_modif->text();
    QString datenaissancee = ui->datenaissance_modif->text();

    Employe E(id_e, nome, prenom, salaire, numero, datenaissancee);
    bool test = E.modifier();

    if (test) {
        QMessageBox::information(this, QObject::tr("Succès"), QObject::tr("Modification effectuée.\n"), QMessageBox::Ok);
        refreshTable();  // Refresh the table after modification
    } else {
        QMessageBox::critical(this, QObject::tr("Échec"), QObject::tr("Modification non effectuée.\n"), QMessageBox::Ok);
    }
}

void MainWindow::on_supprimer_2_clicked()
{
    QString id = ui->id_supprimer->text();
    Employe E;
    bool test = E.supprimer2(id);

    if (test) {
        QMessageBox::information(this, QObject::tr("Succès"), QObject::tr("Suppression effectuée.\n"), QMessageBox::Ok);
        refreshTable();  // Refresh the table after deletion
    } else {
        QMessageBox::critical(this, QObject::tr("Échec"), QObject::tr("Suppression non effectuée.\n"), QMessageBox::Ok);
    }
}
