#include "arduinoservice.h"
#include "client.h"
#include "gestionclients.h"
#include "ui_gestionclients.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QPrinter>
#include <QFileDialog>
#include <QPainter>
#include <QTableView>
#include <QFont>
#include <QRect>
#include <QPixmap>
#include <QString>


#include <QtCharts/QPieSeries>
#include <QDesktopServices>
#include <QUrl>


#include <QSqlQuery>
#include <QChart>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QSqlRecord>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

#include "Arduino.h"
#include <QSerialPort>
#include <QtSql/QSqlError>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),  arduinoServices(new class arduinoServices(this))
{
    ui->setupUi(this);
    ui->tableView_2->setModel(serviceModel.afficher());
    ui->tableView->setModel(Cl.afficher());
    qDebug() << "MainWindow initialisé, prêt à écouter les événements.";
    if (!arduinoServices->ouvrirPort("COM3")) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le port série.");
    }
    // Connecter le bouton pour afficher les réservations par client
    //connect(ui->pushButton_client_fidele, &QPushButton::clicked, this, &MainWindow::on_pushButton_client_fidele_clicked);
    // Connecter le bouton "Envoyer" à la fonction d'envoi d'email
    connect(ui->pushButtonSend, &QPushButton::clicked, this, &MainWindow::sendEmailWithPostmark);
    connect(ui->ButtonOuvrir, &QPushButton::clicked, this, &MainWindow::on_ButtonOuvrir_Clicked);

    connect(ui->pushButton_VerifyID, &QPushButton::clicked, this, &MainWindow::on_pushButton_VerifyID_clicked);

    int ret=A.connect_arduino();
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
    }
   // QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(readDataFromArduino()));
}

MainWindow::~MainWindow()
{
    serialPort->close();
    delete ui;
}


void MainWindow::verifyEmployeeID()
{
    QString employeeID = ui->lineEditEmployeeID->text().trimmed();
    if (employeeID.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un ID de carte valide.");
        return;
    }

    // Appeler la méthode processEmployeeID et stocker le résultat dans un QString
    QString resultMessage = processEmployeeID(employeeID);

    // Afficher le résultat dans le QLabel
    ui->labelResult->setText(resultMessage);

    // Envoyer le message correspondant à l'Arduino
    QByteArray messageToArduino = resultMessage.toUtf8();
    A.write_to_arduino(messageToArduino);
}


QString MainWindow::processEmployeeID(const QString &employeeID)
{
    QSqlQuery query;
    query.prepare("SELECT NOME, PRENOME FROM MALEK.EMPLOYEES WHERE ID_E = :employeeID");
    query.bindValue(":employeeID", employeeID);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête SQL :" << query.lastError();
        return "Erreur: Base de données inaccessible.";
    }

    if (query.next()) {
        // Récupérer le nom et le prénom
        QString employeeName = query.value("NOME").toString().toUpper();
        QString employeeFirstName = query.value("PRENOME").toString().toUpper();

        // Retourner le message de bienvenue
        return "Welcome, " + employeeName + " " + employeeFirstName + "!";
    }

    // Si l'ID n'existe pas
    return "Access Denied: Card Not Found";
}

// Slot déclenché lors du clic sur le bouton
void MainWindow::on_pushButton_VerifyID_clicked()
{
    verifyEmployeeID(); // Appeler la méthode de vérification
}

void MainWindow::actualiserListeClients() {
    ui->tableView->setModel(Cl.afficher());
    ui->tableView->resizeColumnsToContents();
    // Mettez à jour le modèle de la table
}
void MainWindow::on_pushButton_ajouter_clicked()
{
    // Gather input values
    QString CIN = ui->lineedit_cin->text();
    int num_telC = ui->lineedit_tel->text().toInt();
    QString nomC = ui->lineedit_nom->text();
    QString prenomC = ui->lineedit_prenom->text();
    QString nationalite = ui->lineedit_nationalite->text();
    QString emailC = ui->lineedit_adresse->text();
    // Expressions régulières statiques pour chaque champ
    static const QRegularExpression lettreRegex("^[a-zA-ZÀ-ÿ\\s]+$"); // Lettres et espaces
    static const QRegularExpression chiffreRegex("^\\d{8}$"); // 8 chiffres exacts
    static const QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");

    // Validation des champs
    if (!lettreRegex.match(nomC).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom ne doit contenir que des lettres !");
        return;
    }
    if (!lettreRegex.match(prenomC).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le prénom ne doit contenir que des lettres !");
        return;
    }
    if (CIN.length()!=8) {
        QMessageBox::warning(this, "Erreur", "Le CIN doit contenir exactement 8 chiffres !");
        return;
    }
    if (!chiffreRegex.match(QString::number(num_telC)).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres !");
        return;
    }
    if (!lettreRegex.match(nationalite).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "La nationalité ne doit contenir que des lettres !");
        return;
    }

    // Validate email format
    if (emailC.isEmpty() || !emailRegex.match(emailC).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Adresse e-mail non valide !");
        return;
    }

    // Determine gender
    QString genre;
    if (ui->radiobutton_homme->isChecked()) {
        genre = "homme";
    } else if (ui->radiobutton_femme->isChecked()) {
        genre = "femme";
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner le genre (homme ou femme) !");
        return;
    }

    // Create Client object and set values
    Client a(CIN, num_telC, nomC, prenomC, nationalite, emailC, genre);

    // Attempt to add the Client to the database
    bool test = a.ajouter();
    if (test) {
        QMessageBox::information(this, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        actualiserListeClients(); // Actualiser l'affichage après l'ajout
        on_comboBoxCritere_currentIndexChanged();
        // Réinitialisez les champs après l'ajout
        ui->lineedit_cin->clear();
        ui->lineedit_tel->clear();
        ui->lineedit_nom->clear();
        ui->lineedit_prenom->clear();
        ui->lineedit_nationalite->clear();
        ui->lineedit_adresse->clear();
        ui->radiobutton_homme->setChecked(false);
        ui->radiobutton_femme->setChecked(false);
    } else {
        QMessageBox::critical(this, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_rechercher_clicked() {
    qDebug() << "Le bouton Rechercher a été cliqué.";
    int idC = ui->lineedit_id_rech->text().toInt();
    Client clientTrouve = Cl.rechercher(idC);

    if (clientTrouve.getCIN() != "") {  // Vérifiez si un client a été trouvé
        ui->lineedit_cin_supp->setText(clientTrouve.getCIN());
        ui->lineedit_nom_supp->setText(clientTrouve.getNom());
        ui->lineedit_prenom_supp->setText(clientTrouve.getPrenom());
        ui->lineedit_nationalite_supp->setText(clientTrouve.getNationalite());
        ui->lineedit_tel_supp->setText(QString::number(clientTrouve.getNum_tel()));
        ui->lineedit_adresse_supp->setText(clientTrouve.getEmail());
        if (clientTrouve.getGenre() == "homme") {
            ui->radioButton_homme_supp->setChecked(true);
        } else {
            ui->radioButton_femme_supp->setChecked(true);
        }
    } else {
        QMessageBox::information(this, "Non trouvé", "Aucun client avec cet ID n'a été trouvé.");
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int idC =ui->lineedit_id_rech->text().toInt();
    // Vérifiez que l'ID n'est pas vide
    if (idC == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide pour supprimer.");
        return;
    }
    bool test=Cl.supprimer(idC);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        actualiserListeClients(); // Actualiser l'affichage après la suppression
        on_comboBoxCritere_currentIndexChanged();
        // Réinitialisez les champs de l'interface après la suppression
        ui->lineedit_id_rech->clear();
        ui->lineedit_cin_supp->clear();
        ui->lineedit_nom_supp->clear();
        ui->lineedit_prenom_supp->clear();
        ui->lineedit_nationalite_supp->clear();
        ui->lineedit_tel_supp->clear();
        ui->lineedit_adresse_supp->clear();
        ui->radioButton_homme_supp->setChecked(false);
        ui->radioButton_femme_supp->setChecked(false);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Supression non effectuée._n"
                                          " Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_rechercher2_clicked() {
    int idC = ui->lineedit_id_modif->text().toInt(); // Récupérez l'ID du client à rechercher
    if (idC == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    Client clientTrouve = Cl.rechercher(idC); // Rechercher le client

    if (clientTrouve.getCIN() != "") { // Vérifiez si un client a été trouvé
        // Remplissez les champs avec les attributs du client trouvé
        ui->lineedit_cin_modif->setText(clientTrouve.getCIN());
        ui->lineedit_nom_modif->setText(clientTrouve.getNom());
        ui->lineedit_prenom_modif->setText(clientTrouve.getPrenom());
        ui->lineedit_nationalite_modif->setText(clientTrouve.getNationalite());
        ui->lineedit_tel_modif->setText(QString::number(clientTrouve.getNum_tel()));
        ui->lineedit_adresse_modif->setText(clientTrouve.getEmail());
        ui->radiobutton_homme_modif->setChecked(clientTrouve.getGenre() == "homme");
        ui->radiobutton_femme_modif->setChecked(clientTrouve.getGenre() == "femme");

        // Enable the modify button
        ui->pushButton_modifier->setEnabled(true);
    } else {
        QMessageBox::information(this, "Non trouvé", "Aucun client avec cet ID n'a été trouvé.");
    }
}
void MainWindow::on_pushButton_modifier_clicked() {
    int idC = ui->lineedit_id_modif->text().toInt(); // Récupérez l'ID du client à modifier
    if (idC == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide pour modifier.");
        return;
    }

    // Get the new values from the line edits
    QString newCIN = ui->lineedit_cin_modif->text();
    QString newNom = ui->lineedit_nom_modif->text();
    QString newPrenom = ui->lineedit_prenom_modif->text();
    QString newNationalite = ui->lineedit_nationalite_modif->text();
    int newNumTel = ui->lineedit_tel_modif->text().toInt();
    QString newEmail = ui->lineedit_adresse_modif->text();
    QString newGenre = ui->radiobutton_homme_modif->isChecked() ? "homme" : "femme";

    // Create a new Client object with the updated data
    Client clientAModifier(newCIN, newNumTel, newNom, newPrenom, newNationalite, newEmail, newGenre);

    // Call the modifier function
    if (clientAModifier.modifier(idC)) {
        QMessageBox::information(this, "Modification réussie", "Les informations du client ont été modifiées.");
        actualiserListeClients();
        on_comboBoxCritere_currentIndexChanged();
        ui->lineedit_id_modif->clear();
        ui->lineedit_cin_modif->clear();
        ui->lineedit_nom_modif->clear();
        ui->lineedit_prenom_modif->clear();
        ui->lineedit_nationalite_modif->clear();
        ui->lineedit_tel_modif->clear();
        ui->lineedit_adresse_modif->clear();
        ui->radiobutton_homme_modif->setChecked(false);
        ui->radiobutton_femme_modif->setChecked(false);
        // Mettez à jour l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification des informations du client.");
    }
}
void MainWindow::on_pushButton_trierParNom_clicked()
{
    QString ordre = ui->comboBox_ordre->currentText();  // Ex. "ASC" ou "DESC"
    ui->tableView->setModel(Cl.trierParNom(ordre));
}


void MainWindow::on_pushButton_trierParNom_3_clicked()
{
    QString ordre = ui->comboBox_ordre->currentText();  // Ex. "ASC" ou "DESC"
    ui->tableView->setModel(Cl.trierParNom_desc(ordre));
}

void MainWindow::exportToPdf(const QString &fileName)
{
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A3));

    QString filePath = QFileDialog::getSaveFileName(this, tr("Enregistrer sous"), fileName, tr("Fichiers PDF (*.pdf)"));
    if (filePath.isEmpty()) return;

    printer.setOutputFileName(filePath);

    QPainter painter(&printer);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    QFont titreFont("Arial", 20, QFont::Bold);
    painter.setFont(titreFont);

    // Utilisation de `pageLayout().fullRect(QPageLayout::Point).width()` pour la largeur de la page
    QRect titreRect(0, 0, printer.pageLayout().fullRect(QPageLayout::Point).width(), 50);
    painter.drawText(titreRect, Qt::AlignCenter, "Liste des Clients");

    ui->tableView->render(&painter);
}

void MainWindow::on_pushButton_export_pdf_clicked()
{
    exportToPdf("liste_clients.pdf");
}

void MainWindow::on_comboBoxCritere_currentIndexChanged()
{
    QString critere = ui->comboBoxCritere->currentText();
    if (critere == "Genre") {
        createPieChart(critere);
    }
}

void MainWindow::createPieChart(QString critere)
{
    QSqlQuery query("SELECT " + critere + ", COUNT(*) FROM CLIENTS GROUP BY " + critere);
    QBarSeries *barSeries = new QBarSeries();

    while (query.next()) {
        QString label = query.value(0).toString();
        int count = query.value(1).toInt();
        QString labelText = QString::number(count) + "-" + label;
        QBarSet *barSet = new QBarSet(labelText);
        *barSet << count;
        barSeries->append(barSet);
    }

    QChart *chart = new QChart();
    chart->addSeries(barSeries);
    chart->setTitle("Statistiques des clients par " + critere);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QSize size = ui->graphicsView_chart->size();
    chartView->resize(size.width(), size.height());

    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget();
    proxy->setWidget(chartView);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->addItem(proxy);

    ui->graphicsView_chart->setScene(scene);
}

void MainWindow::on_pushButtonRechercher_met_clicked() {
    QString critereRecherche = ui->lineEdit_critereRecherche->text();
    QString typeRecherche = ui->comboBox_critereRecherche->currentText();

    Client c;

    // Appel de la fonction de recherche avec le critère et le type de recherche
    QSqlQueryModel* model = c.rechercher(critereRecherche, typeRecherche);
    if (model != nullptr) {
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    } else {
        // Gérer les erreurs ou afficher un message à l'utilisateur selon vos besoins
        QMessageBox::warning(this, "Avertissement", "Erreur lors de la recherche!", QMessageBox::Ok);
    }
}



void MainWindow::on_pushButton_afficher_clicked()
{
    Client c;

    // Afficher la liste des clients dans le QTableView
    QSqlQueryModel* model = c.afficher();

    if (model != nullptr) {
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    }
    actualiserListeClients();
}


void MainWindow::on_pushButton_client_fidele_clicked()
{
    Client client;
    QSqlQueryModel* model = client.obtenirReservationsParClient();
    if (model) {
        QString result;
        int maxReservations = 0;
        QString plusFidele;

        for (int i = 0; i < model->rowCount(); ++i) {
            int id = model->data(model->index(i, 0)).toInt();
            int reservations = model->data(model->index(i, 1)).toInt();
            QString nom = model->data(model->index(i, 2)).toString();
            QString prenom = model->data(model->index(i, 3)).toString();

            // Vérifier si ce client a le plus grand nombre de réservations jusqu'à présent
            if (reservations > maxReservations) {
                maxReservations = reservations;
                plusFidele = QString("Client le plus fidèle : ID: %1, Nom: %2, Prénom: %3, Réservations: %4\n")
                                 .arg(id)
                                 .arg(nom)
                                 .arg(prenom)
                                 .arg(reservations);
            }

            // Ajouter chaque client à la liste des résultats
            result += QString("Client ID: %1, Nom: %2, Prénom: %3, Nombre de réservations: %4\n")
                          .arg(id)
                          .arg(nom)
                          .arg(prenom)
                          .arg(reservations);
        }

        // Ajouter le client le plus fidèle au début du message
        result = plusFidele + "\n" + result;

        QMessageBox::information(this, "Fidélité du client", result);
    }
}

//mail
void MainWindow::sendEmailWithPostmark() {
    // Récupérer les informations saisies par l'utilisateur
    QString recipient = ui->lineEditRecipient->text(); // Email du destinataire
   // QString messageBody = ui->textEditMessage->toPlainText(); // Contenu du message
    if (recipient.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir l'adresse email du destinataire.");
        return;
    }
   /* if (messageBody.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un contenu pour le message.");
        return;*/

    // Initialiser le manager réseau
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // Préparer la requête HTTP vers l'API Postmark
    QNetworkRequest request(QUrl("https://api.postmarkapp.com/email"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-Postmark-Server-Token", ""); // Votre token API

    // Construire le contenu de l'email
    QJsonObject emailObject;
    emailObject["From"] = ""; // Adresse email expéditeur (vérifiée dans Postmark)
    emailObject["To"] = recipient; // Adresse email du destinataire
    emailObject["Subject"] = "Email de test depuis Qt et Postmark"; // Sujet de l'email
    emailObject["TextBody"] = "Bonjour,\nCeci est un test envoyé avec Qt et Postmark."; // Contenu texte de l'email
 //   emailObject["TextBody"] = messageBody; // Contenu texte de l'email

    QJsonDocument emailDoc(emailObject);

    // Envoyer la requête POST
    QNetworkReply *reply = manager->post(request, emailDoc.toJson());

    // Gérer la réponse de l'API
    connect(reply, &QNetworkReply::finished, this, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QMessageBox::information(nullptr, "Succès", "Email envoyé avec succès !");
        } else {
            QMessageBox::critical(nullptr, "Erreur", "Échec de l'envoi de l'email : " + reply->errorString());
        }
        reply->deleteLater();
    });
}

void MainWindow::on_pushButtonSend_clicked()
{
    // Appeler la fonction pour envoyer l'email
    sendEmailWithPostmark();
}

// nour


void MainWindow::on_supprimerButton_clicked() {
    int ids = ui->lineedit_id_rech_2->text().toInt();

    // Appel de la fonction de suppression avec vérification d'existence de l'ID
    bool test = serviceModel.supprimer(ids);

    if (test) {
        // Rafraîchissement du modèle pour afficher les données mises à jour
        ui->tableView_2->setModel(serviceModel.afficher());
        addToHistory("Supprimer", ids);
        QMessageBox::information(this, QObject::tr("Succès"),
                                 QObject::tr("Suppression effectuée.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(this, QObject::tr("Erreur"),
                              QObject::tr("Erreur : l'ID n'existe pas dans la base de données."), QMessageBox::Cancel);
    }
}

void MainWindow::on_ajouterButton_clicked() {
    int ids = ui->l1->text().toInt();
    if (ids == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide non null et sous forme de entier.");
        return;
    }

    QString noms = ui->l2->text();

    bool isPrixFloat;
    float prix = ui->l3->text().toFloat(&isPrixFloat);
    if (!isPrixFloat) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un prix valide sous forme de float.");
        return;
    }
    if (prix < 0) {
        QMessageBox::warning(this, "Erreur", "Le prix ne peut pas être négatif.");
        return;
    }

    int disponibilite = ui->l4->text().toInt();
    if (disponibilite != 0 && disponibilite != 1) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une disponibilité valide : 1 pour disponible, 0 pour non disponible.");
        return;
    }

    if (serviceModel.ajouter(ids, noms, prix, disponibilite)) {
        ui->tableView_2->setModel(serviceModel.afficher());
        addToHistory("Ajouter", ids);
        QMessageBox::information(this, "Succès", "Service ajouté avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors de l'ajout du service.");
    }
}

void MainWindow::on_modifierButton_clicked() {
    int ids = ui->lineedit_id_modif_2->text().toInt();
    if (ids == 0) {
        QMessageBox::warning(this, "Erreur", "La modification ne peut pas se faire sur l'ID.");
        return;
    }

    QString noms = ui->l6->text();
    bool isPrixFloat;
    float prix = ui->l7->text().toFloat(&isPrixFloat);
    if (prix < 0) {
        QMessageBox::warning(this, "Erreur", "Le prix ne peut pas être négatif.");
        return;
    }

    int disponibilite = ui->l8->text().toInt();

    // Vérification si au moins une case est remplie
    bool isValid = false;
    if (!noms.isEmpty() || isPrixFloat || (disponibilite == 0 || disponibilite == 1)) {
        isValid = true;
    }

    if (!isValid) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir au moins une case valide.");
        return;
    }

    // Appel de la fonction modifier avec les données
    if (serviceModel.modifier(ids, noms.isEmpty() ? QString() : noms,
                              isPrixFloat ? prix : -1,
                              (disponibilite == 0 || disponibilite == 1) ? disponibilite : -1)) {
        ui->tableView_2->setModel(serviceModel.afficher());
        addToHistory("Modifier", ids);
        QMessageBox::information(this, "Succès", "Service modifié avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur : l'ID n'existe pas dans la base de données.");
    }
}

void MainWindow::on_pb_pdf_clicked() {
    QString nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichiers PDF (*.pdf)");
    if (!nomFichier.isEmpty()) {
        Service service;

        // Récupère les données des services
        QSqlQueryModel *model = service.afficher();

        // Exportation vers PDF
        service.exporterPDF(nomFichier, model);

        // Libération de mémoire
        delete model;
        addToHistory("pdf", 0);

        QMessageBox::information(this, "Exportation PDF", "Exportation vers PDF réussie !");
    }
}

void MainWindow::on_rechercherButton_clicked() {
    int ids = ui->l5->text().toInt();  // Récupérer l'ID à partir de l'interface
    if (ids == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide (entier) pour la recherche.");
        return;
    }

    // Appel de la fonction recherche avec l'ID donné
    QSqlQueryModel* model = serviceModel.recherche(ids);

    if (model && model->rowCount() > 0) {
        // Si le modèle contient la ligne recherchée, l'afficher
        ui->tableView_2->setModel(model);
        addToHistory("Rechercher", ids);
        QMessageBox::information(this, "Recherche réussie", "L'ID recherché a été trouvé.");
    } else {
        // Si l'ID n'existe pas, afficher un message d'erreur
        QMessageBox::warning(this, "Erreur", "L'ID recherché n'existe pas dans la base de données.");
        delete model;  // Libérer la mémoire du modèle si aucun résultat n'est trouvé
    }
}

void MainWindow::on_trierButton_clicked() {
    ui->tableView_2->setModel(serviceModel.trierParPrix());
    QMessageBox::information(this, "Tri par Prix", "Données triées du plus cher au moins cher.");
}

void MainWindow::on_statistiqueButton_clicked() {
    // Appel de la méthode statique
    QMap<QString, double> stats = Service::obtenirStatistiquesDisponibilite();

    // Effacer les éléments précédents dans le listWidget
    ui->listWidget->clear();

    // Ajouter les résultats au listWidget sous forme de pourcentages
    for (auto it = stats.constBegin(); it != stats.constEnd(); ++it) {
        QString result = QString("%1 : %2%").arg(it.key()).arg(QString::number(it.value(), 'f', 2));
        ui->listWidget->addItem(result);
    }
    addToHistory("Statistique numerique", 0);
}

void MainWindow::on_statistiqueButton_2_clicked() {
    QMap<QString, double> stats = serviceModel.statistiquesParDisponibilite();

    // Calculer le total des services
    double totalServices = 0;
    for (auto it = stats.constBegin(); it != stats.constEnd(); ++it) {
        totalServices += it.value();
    }

    // Vider le layout avant d'ajouter un nouveau graphique
    QLayoutItem* item;
    while ((item = ui->verticalLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Créer un pie series pour le graphique
    QPieSeries *series = new QPieSeries();

    // Ajouter les données de disponibilité dans le graphique avec le pourcentage
    for (auto it = stats.constBegin(); it != stats.constEnd(); ++it) {
        QString label = QString("%1: %2%").arg(it.key()).arg(it.value(), 0, 'f', 1);
        series->append(label, it.value());
    }

    // Créer un graphique à partir de la série
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques de disponibilité des services");

    // Créer un chart view pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);  // Améliorer l'anti-aliasing

    // Afficher le graphique dans le layout
    ui->verticalLayout->addWidget(chartView);
    addToHistory("Statistique par graphe", 0);
}

void MainWindow::afficherHistoriqueService() {
    QString cheminFichier = "C:/Users/nour1/OneDrive/Documents/InterfaceCRUDhistorique_service.txt";
    QFile file(cheminFichier);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier d'historique.");
        return;
    }

    QTextStream in(&file);
    QString historique = in.readAll();
    file.close();

    QMessageBox msgBox;
    msgBox.setWindowTitle("Historique des services");
    msgBox.setText(historique);
    msgBox.exec();
}

void MainWindow::addToHistory(const QString &action, int idService) {
    Service Stemp;
    Stemp.addToHistory(action, idService);
}

void MainWindow::on_pb_historiqueService_clicked() {
    QString cheminFichier = "C:/Users/nour1/OneDrive/Documents/InterfaceCRUD/historique_service.txt";
    QDesktopServices::openUrl(QUrl::fromLocalFile(cheminFichier));
    QMessageBox::information(this, "Historique", "Les actions ont été enregistrées dans l'historique.");
}

void MainWindow::on_sendSMSButton_clicked()
{
    QString destinataire = "+21624119339";
    QString message = ui->contenu->toPlainText();

    envoyerSMS(destinataire, message);


}

void MainWindow::envoyerSMS(const QString &destinataire, const QString &message)
{
    // SID et auth token de Twilio
    QString sid = "AC33a7a85609d980ad8c5f6af6ea4407b8";
    QString authToken = "e7831917593e61169112e26f7ff93a5a";

    // URL de l'API Twilio
    QString url = "https://api.twilio.com/2010-04-01/Accounts/" + sid + "/Messages.json";

    // Créer un gestionnaire de requêtes
    QNetworkAccessManager *networkAccessManager = new QNetworkAccessManager(this);

    // Connecter le signal pour traiter la réponse
    //   connect(networkAccessManager, &QNetworkAccessManager::finished, this, &MainWindow::replyFinished);

    // Construire les données POST
    QByteArray postData;
    postData.append("To=" + QUrl::toPercentEncoding(destinataire)); // Encodage pour les caractères spéciaux
    postData.append("&From=%2B12029293390"); // Numéro de l'expéditeur avec "%2B" pour "+"
    postData.append("&Body=" + QUrl::toPercentEncoding(message));

    // Configurer la requête HTTP
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Ajouter l'autorisation avec Basic Auth
    QString credentials = QString("%1:%2").arg(sid).arg(authToken);
    request.setRawHeader("Authorization", "Basic " + credentials.toUtf8().toBase64());

    // Envoyer la requête
    networkAccessManager->post(request, postData);

    QMessageBox::information(this, "Envoi SMS", "Le SMS est en cours d'envoi...");
}
void MainWindow::on_ButtonOuvrir_Clicked()
{
    // Récupérer l'ID saisi dans l'interface
    int idReservation = ui->l11->text().toInt();
    if (idReservation == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    // Rechercher l'ID dans la table "reservation"
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM reservation WHERE id = :id");
    query.bindValue(":id", idReservation);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'accès à la base de données : " + query.lastError().text());
        return;
    }

    // Vérifier si l'ID existe dans la table
    query.next(); // Accéder au premier (et unique) résultat
    int count = query.value(0).toInt();

    if (count > 0) {
        // ID valide, envoyer la commande au servomoteur
        if (arduinoServices->estPortOuvert()) {
            if(arduinoServices->envoyerCommande("ouvrir")){
                QMessageBox::information(this, "Succès", "L'ID est valide. Le servomoteur tourne.");}
        } else {
            QMessageBox::critical(this, "Erreur", "Le port série n'est pas ouvert !");
        }
    } else {
        // ID invalide, afficher un message d'erreur
        QMessageBox::warning(this, "Erreur", "L'ID saisi n'existe pas dans la table 'reservation'.");
    }
}
