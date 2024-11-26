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
    initSerialPort();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initSerialPort()
{
    // Configurez ici votre port série (par exemple, COM3 sur Windows ou /dev/ttyUSB0 sur Linux)
    serialPort->setPortName("COM3");  // Changez-le selon votre système
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

    // Connectez le signal readyRead() au slot pour lire les données lorsque Arduino envoie quelque chose
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
}

void MainWindow::readSerialData()
{
    QString serialData = serialPort->readAll(); // Lecture des données série
    QString uid = serialData.trimmed();        // Nettoyage de l'UID

    qDebug() << "UID reçu :" << uid;           // Debug pour vérifier l'UID reçu
    afficherEmployeParUID(uid);                // Recherche dans la base de données
}

void MainWindow::afficherEmployeParUID(const QString& uid)
{
    QSqlQuery query;
    query.prepare("SELECT Nome, Prenom FROM Employes WHERE UID = :uid");
    query.bindValue(":uid", uid);

    if (query.exec() && query.next()) {
        QString nome = query.value("Nome").toString();
        QString prenom = query.value("Prenom").toString();
        ui->label_nome->setText(nome);    // Affiche le nom
        ui->label_prenom->setText(prenom); // Affiche le prénom
    } else {
        QMessageBox::warning(this, "Erreur", "Aucun employé trouvé pour cet UID.");
    }
}








// Refresh table with data from the database
void MainWindow::refreshTable()
{
    Employe E;
    QSqlQueryModel *model = E.afficher();
    ui->tab_affich_E->setModel(model);  // Set the model for the QTableView
}

// Add Employee
void MainWindow::on_ajouter_clicked()
{
    qDebug() << "Bouton Ajouter cliqué.";
    int id_e = ui->ide->text().toInt();
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
    ui->tab_affich_E->clearSelection();//annuler la selection
}


void MainWindow::on_QrCode_clicked()
{
    using namespace qrcodegen;

    QString value = ui->qr_code_bar->text(); // Récupérer la valeur du QR code (ID de l'employé)

    if (value.isEmpty()) {
        // Afficher un message d'erreur si le champ du QR code est vide
        QMessageBox::warning(this, "Erreur", "Le champ du QR Code ne peut pas être vide !");
    } else {
        int id = value.toInt();  // Supposer que l'ID est un entier

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
            ui->qrcodecommande_2->setPixmap(QPixmap::fromImage(im.scaled(200, 200, Qt::KeepAspectRatio, Qt::FastTransformation), Qt::MonoOnly));
        } else {
            // Si l'ID n'existe pas, afficher un message d'erreur
            QMessageBox::warning(this, "Erreur", "L'employé avec cet ID n'existe pas dans la base de données !");
        }
    }
}
void MainWindow::on_modifier_clicked()
{
    // Récupérer les valeurs des champs de saisie
    int id_e = ui->ide_modif->text().toInt();
    QString nome = ui->nom_modif->text().trimmed();
    QString prenom = ui->prenom_modif->text().trimmed();
    int salaire = ui->salaire_modif->text().toInt();
    int numero = ui->numero_modif->text().toInt();
    QString datenaissancee = ui->datenaissance_modif->text().trimmed();

    // Contrôle de saisie
    if (id_e <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID doit être un nombre positif.");
        return;
    }

    if (nome.isEmpty() || prenom.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le nom et le prénom ne peuvent pas être vides.");
        return;
    }

    if (salaire <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le salaire doit être un nombre positif.");
        return;
    }

    if (numero <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le numéro doit être un nombre positif.");
        return;
    }


    // Créer un objet Employe
    Employe E(id_e, nome, prenom, salaire, numero, datenaissancee);

    // Appeler la fonction modifier
    bool test = E.modifier();

    // Vérifier le résultat
    if (test) {
        QMessageBox::information(this, QObject::tr("Succès"), QObject::tr("Modification effectuée.\n"), QMessageBox::Ok);
        refreshTable(); // Rafraîchir la table après modification
    } else {
        QMessageBox::critical(this, QObject::tr("Échec"), QObject::tr("Modification non effectuée. Vérifiez que l'ID existe.\n"), QMessageBox::Ok);
    }
}



void MainWindow::on_supprimer_2_clicked()
{
    QString id = ui->id_supprimer->text(); // Récupérer l'ID depuis le champ de saisie

    // Vérification si le champ est vide
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID à supprimer !");
        return; // Arrêter l'exécution si aucun ID n'est fourni
    }

    // Vérification si l'ID est un entier valide
    bool isNumber;
    int idInt = id.toInt(&isNumber);
    if (!isNumber || idInt <= 0) {
        QMessageBox::warning(this, "Erreur", "L'ID doit être un entier positif valide !");
        return;
    }

    // Confirmation avant la suppression
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir supprimer cet employé ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Tentative de suppression
        if (E.supprimer2(id.toInt())) {
            QMessageBox::information(this, "Succès", "Employé supprimé avec succès !");
            refreshTable(); // Rafraîchir la table après suppression
        } else {
            QMessageBox::critical(this, "Échec", "Échec de la suppression. Vérifiez si l'ID existe !");
        }
    } else {
        QMessageBox::information(this, "Annulé", "Suppression annulée !");
    }
}
