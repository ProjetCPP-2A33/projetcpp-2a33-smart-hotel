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
/*
#include "smtp.h"
//#include <QMessageBox>            // Affichage des boîtes de message (succès/échec).
//#include <QFileDialog>            // Pour choisir des fichiers (pièces jointes).
#include <QDesktopServices>       // Ouvrir des URLs ou des fichiers.
#include <QUrl>                   // Gestion des URLs.
#include <QDebug>
*/              // Pour déboguer et afficher des logs.







MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui (new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Cl.afficher());
    qDebug() << "MainWindow initialisé, prêt à écouter les événements.";

    // Connecter le bouton pour afficher les réservations par client
    //connect(ui->pushButton_client_fidele, &QPushButton::clicked, this, &MainWindow::on_pushButton_client_fidele_clicked);
    // Connecter le bouton "Envoyer" à la fonction d'envoi d'email
    connect(ui->pushButtonSend, &QPushButton::clicked, this, &MainWindow::sendEmailWithPostmark);

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
    delete ui;
}
// Slot pour vérifier l'ID de l'employé saisi dans le QLineEdit
void MainWindow::verifyEmployeeID()
{
    QString employeeID = ui->lineEditEmployeeID->text().trimmed(); // Récupérer et nettoyer l'ID de l'employé

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













// Fonction pour convertir l'UID en un nombre unique
/*quint64 MainWindow::convertUIDtoNumber(const QString &uid)
{
    QByteArray byteArray = QCryptographicHash::hash(uid.toUtf8(), QCryptographicHash::Sha256);
    quint64 numericUID = 0;
    for (int i = 0; i < 8; ++i) {
        numericUID = (numericUID << 8) | (byteArray[i] & 0xFF);
    }
    return numericUID;
}*/

// Slot pour vérifier l'ID de l'employé saisi dans le QLineEdit
/*void MainWindow::verifyEmployeeID()
{
    QString employeeID = ui->lineEditEmployeeID->text();  // Récupérer l'ID de l'employé depuis le QLineEdit

    if (employeeID.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un ID d'employé.");
        return;
    }
    // Convertir l'UID saisi en un nombre
   /* quint64 numericID = convertUIDtoNumber(employeeID);
    QString employeeCardCode = QString::number(numericID);  // Convertir le nombre en QString pour l'utiliser dans SQL*/

    // Traiter l'ID de l'employé
    //processEmployeeID(employeeID);
//}


/*void MainWindow::processEmployeeID(const QString &employeeID)
{
    // Vérifier si l'ID de l'employé existe dans la base de données en utilisant CARDUID
    QString employeeCardCode = getEmployeeCardCodeFromDatabase(employeeID);
    QString result_name;

    if (!employeeCardCode.isEmpty()) {
        // Si l'ID existe, récupérer le nom et le prénom de l'employé
        QString employeeName = getEmployeeNameFromDatabase(employeeCardCode).toUpper();
        QString employeeFirstName = getEmployeeFirstNameFromDatabase(employeeCardCode).toUpper();

        // Concatenation du nom et prénom
         result_name = "NAME:" + employeeName + " " + employeeFirstName;  // Ajout du préfixe "NAME:"
        //result_name = employeeName + " " + employeeFirstName;  // Concatenation du nom et prénom
        ui->labelResult->setText("Welcome, " + result_name);   // Afficher sur le QLabel
        QByteArray employeeFullNameData = result_name.toUtf8();
        A.write_to_arduino(employeeFullNameData); // Envoyer au Arduino
    } else {
        result_name = "ERROR: Card Not Found";  // Message d'erreur si l'ID n'est pas trouvé
        ui->labelResult->setText("Access Denied: " + result_name); // Afficher le message d'erreur sur le QLabel
        QByteArray errorMessage = result_name.toUtf8();
        A.write_to_arduino(errorMessage); // Envoyer le message d'erreur à Arduino
    }
}
*/

/*QString MainWindow::getEmployeeCardCodeFromDatabase(const QString &employeeID)
{
    QString employeeCardCode;
   // QString numericUID = QString::number(convertUIDtoNumber(employeeID)); // Convertir l'UID en nombre

    QSqlQuery query;
    query.prepare("SELECT CARDUID FROM MALEK.EMPLOYEES WHERE CARDUID = :employeeID");
    query.bindValue(":employeeID", employeeID.trimmed());
    qDebug() << "Executing query:" << query.lastQuery();  // Affiche la requête SQL

    if (!query.exec()) {
        qDebug() << "Query execution error:" << query.lastError().text();
        return employeeCardCode;
    }

    if (query.next()) {
        employeeCardCode = query.value(0).toString();  // Récupérer l'IDE (UID de la carte)
        qDebug() << "UID trouvé :" << employeeCardCode;
    } else {
        qDebug() << "Aucun UID trouvé pour :" << employeeID;
    }


       // qDebug() << "Found employee ID:" << employeeCardCode;  // Affiche l'ID trouvé
  //  }

    return employeeCardCode;
}*/

/*QString MainWindow::getEmployeeNameFromDatabase(const QString &employeeCardCode)
{
    QString employeeName;

    QSqlQuery query;
    query.prepare("SELECT NOME FROM MALEK.EMPLOYEES WHERE CARDUID = :employeeCardCode");
    query.bindValue(":employeeCardCode", employeeCardCode);

    if (!query.exec()) {
        qDebug() << "Query execution error:" << query.lastError();
        return employeeName;
    }

    if (query.next()) {
        employeeName = query.value(0).toString(); // Récupérer le nom
    }

    return employeeName;
}*/

/*QString MainWindow::getEmployeeFirstNameFromDatabase(const QString &employeeCardCode)
{
    QString employeeFirstName;

    QSqlQuery query;
    query.prepare("SELECT PRENOME FROM MALEK.EMPLOYEES WHERE CARDUID = :employeeCardCode");
    query.bindValue(":employeeCardCode", employeeCardCode);

    if (!query.exec()) {
        qDebug() << "Query execution error:" << query.lastError();
        return employeeFirstName;
    }

    if (query.next()) {
        employeeFirstName = query.value(0).toString(); // Récupérer le prénom
    }

    return employeeFirstName;
}*/

/*void MainWindow::on_pushButton_VerifyID_clicked() {
    // Appeler la méthode qui vérifie l'ID de l'employé
    verifyEmployeeID();  // Cette fonction doit être définie dans ton code comme tu l'as fait précédemment
}
*/

/*void MainWindow::readDataFromArduino()
{
    QByteArray newData = A.read_from_arduino();  // Lire les données envoyées par Arduino
    QString receivedData = QString::fromUtf8(newData).trimmed();  // Convertir les données en QString

    if (receivedData.length() >= 8) {
        QString cardUID = receivedData.left(8);  // Extraire l'UID de la carte
        processCardUID(cardUID);  // Appeler la fonction pour traiter l'UID
    } else {
        qDebug() << "Incomplete card UID received from Arduino:" << receivedData;
    }
}*/






//hedha lekdim

/*void MainWindow::readDataFromArduino()
{
    static QString receivedData; // Static variable to store partial data between function calls

        QByteArray newData = A.read_from_arduino(); // Read new data from Arduino
        QString newDataString = QString::fromUtf8(newData).trimmed(); // Convert to QString and remove leading/trailing whitespace

        // Concatenate new data with previously received data
        receivedData += newDataString;

        // Check if the received data contains a valid card UID
        if (receivedData.length() >= 8) {
            QString cardUID = receivedData.left(8); // Extract the first 8 characters as the card UID
            processCardUID(cardUID); // Process the card UID
            receivedData = receivedData.mid(8); // Remove the processed UID from the received data
        } else {
            qDebug() << "Incomplete card UID received from Arduino:" << receivedData;
        }


}*/


/*void MainWindow::processCardUID(const QString &cardUID) //hedhy deja en cmntr
{
    QString athleteCardCode = getAthleteCardCodeFromDatabase(cardUID);
    //qDebug()<<athleteCardCode;
    QString resultat_nom;
        if (!athleteCardCode.isEmpty()) {
            QString athleteName = getAthleteNameFromDatabase(athleteCardCode).toUpper();
            QString athleteFirstName = getAthleteFirstNameFromDatabase(athleteCardCode).toUpper();

            resultat_nom= athleteName+" "+athleteFirstName;
            QByteArray athleteFullNameData = resultat_nom.toUtf8();
            A.write_to_arduino(athleteFullNameData);
            //ui->lcd->clear();
            //ui->lcd->setText("Athlete: " + resultat_nom);
            //sendDataToArduino("athleteName");

        } else {
            qDebug()<<cardUID;
            qDebug() << "Athlete Name Not Found";
            resultat_nom= "Card not Found!";
            QByteArray errorMessage = resultat_nom.toUtf8();
            A.write_to_arduino(errorMessage);
            //ui->lcd->clear();
            //ui->lcd->setText("Access Denied");
            sendDataToArduino("false");
        }
}*/

/*void MainWindow::processCardUID(const QString &cardUID)
{
    QString athleteCardCode = getAthleteCardCodeFromDatabase(cardUID);
    QString resultat_nom;

    if (!athleteCardCode.isEmpty()) {
        QString athleteName = getAthleteNameFromDatabase(athleteCardCode).toUpper();
        QString athleteFirstName = getAthleteFirstNameFromDatabase(athleteCardCode).toUpper();

        resultat_nom = "NAME:" + athleteName + " " + athleteFirstName;
        QByteArray athleteFullNameData = resultat_nom.toUtf8();
        A.write_to_arduino(athleteFullNameData); // Send full name to Arduino
    } else {
        resultat_nom = "ERROR:Card Not Found";
        QByteArray errorMessage = resultat_nom.toUtf8();
        A.write_to_arduino(errorMessage); // Send error message to Arduino
    }
}



void MainWindow::sendDataToArduino(const QByteArray &data)
{
    if (A.getserial()->isOpen() && A.getserial()->isWritable()) {
        A.getserial()->write(data);
    }
}



QString MainWindow::getAthleteCardCodeFromDatabase(const QString &cardUID)
{
    QString athleteCardCode;

    QSqlQuery query;
    query.prepare("SELECT CARDUID FROM CLIENTS WHERE CARDUID = :cardUID");
    query.bindValue(":cardUID", cardUID);

    if (!query.exec()) {
        qDebug() << "Query execution error:";
        return athleteCardCode;
    }

    if (query.next()) {
        athleteCardCode = query.value(0).toString();
        //qDebug()<<athleteCardCode;


    }
    return athleteCardCode;

}

QString MainWindow::getAthleteNameFromDatabase(const QString &athleteCardCode)
{
    QString athleteName;

    QSqlQuery query;
    query.prepare("SELECT NOMC FROM CLIENTS WHERE CARDUID= :athleteCardCode");
    query.bindValue(":athleteCardCode", athleteCardCode);

    if (!query.exec()) {
        qDebug() << "Query execution error:";
        return athleteName;
    }

    if (query.next()) {
        athleteName = query.value(0).toString();
    }

    return athleteName;
}
QString MainWindow::getAthleteFirstNameFromDatabase(const QString &athleteCardCode)
{
    QString athleteFirstName;

    QSqlQuery query;
    query.prepare("SELECT PRENOMC FROM CLIENTS WHERE CARDUID= :athleteCardCode");
    query.bindValue(":athleteCardCode", athleteCardCode);

    if (!query.exec()) {
        qDebug() << "Query execution error:";
        return athleteFirstName;
    }

    if (query.next()) {
        athleteFirstName = query.value(0).toString();
    }


    return athleteFirstName;
}*/




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

/*void MainWindow::on_pushButton_modifier_clicked() {
    int idC = ui->lineedit_id_modif->text().toInt(); // Récupérez l'ID du client à modifier
    if (idC == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide pour modifier.");
        return;
    }

    Client clientTrouve = Cl.rechercher(idC); // Rechercher le client

    if (clientTrouve.getCIN() != 0) { // Vérifiez si un client a été trouvé


        // Remplissez les champs avec les attributs du client trouvé
        ui->lineedit_cin_modif->setText(QString::number(clientTrouve.getCIN()));
        ui->lineedit_nom_modif->setText(clientTrouve.getNom());
        ui->lineedit_prenom_modif->setText(clientTrouve.getPrenom());
        ui->lineedit_nationalite_modif->setText(clientTrouve.getNationalite());
        ui->lineedit_tel_modif->setText(QString::number(clientTrouve.getNum_tel()));
        ui->lineedit_adresse_modif->setText(clientTrouve.getEmail());
        ui->radiobutton_homme_modif->setChecked(clientTrouve.getGenre() == "homme");
        ui->radiobutton_femme_modif->setChecked(clientTrouve.getGenre() == "femme");

        // Lorsque les champs sont remplis, permettez à l'utilisateur de modifier les champs souhaités
        // Ensuite, implémentez la logique de modification (par exemple, avec un autre bouton "Enregistrer les modifications")
        connect(ui->pushButton_modifier, &QPushButton::clicked, this, [this, idC]() {
            // Récupérez les nouvelles valeurs
            int newCIN = ui->lineedit_cin->text().toInt();
            QString newNom = ui->lineedit_nom->text();
            QString newPrenom = ui->lineedit_prenom->text();
            QString newNationalite = ui->lineedit_nationalite->text();
            int newNumTel = ui->lineedit_tel->text().toInt();
            QString newEmail = ui->lineedit_adresse->text();
            QString newGenre = ui->radiobutton_homme->isChecked() ? "homme" : "femme";

            // Mettez à jour les attributs du client
            Client clientAModifier = Client(newCIN, newNumTel, newNom, newPrenom, newNationalite, newEmail, newGenre);
            clientAModifier.supprimer(idC); // Supprimez l'ancien client
            clientAModifier.ajouter(); // Ajoutez le nouveau client

            QMessageBox::information(this, "Modification réussie", "Les informations du client ont été modifiées.");
            actualiserListeClients(); // Mettez à jour l'affichage
        });
    } else {
        QMessageBox::information(this, "Non trouvé", "Aucun client avec cet ID n'a été trouvé.");
    }
}*/

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

/*void MainWindow::afficherClientFidele() {
     Client client;  // Créer un objet Client
    QString clientFidele = client.clientLePlusFidele();  // Appel de la méthode

    if (!clientFidele.isEmpty()) {
        // Afficher les informations du client fidèle dans une boîte de message
        QMessageBox::information(this, "Client Fidèle", "Le client le plus fidèle est : " + clientFidele);
    } else {
        QMessageBox::information(this, "Aucun client fidèle", "Aucun client n'a de réservations.");
    }
    // Afficher le résultat sur l'interface utilisateur
   // ui->label_client_fidele->setText(clientFidele);  // Assurez-vous que label_client_fidele existe dans votre UI
}*/

/*void MainWindow::afficherReservationsParClient() {
    Client client;
    QSqlQueryModel* model = client.obtenirReservationsParClient();
    QString message;

    for (int i = 0; i < model->rowCount(); ++i) {
        int idc = model->record(i).value("IDC").toInt();
        int nbr_reservations = model->record(i).value("nbr_reservations").toInt();
        QString nom = model->record(i).value("NOMC").toString();
        QString prenom = model->record(i).value("PRENOMC").toString();

        message += QString("Client ID: %1, Nom: %2, Prénom: %3, Nombre de réservations: %4\n")
                       .arg(idc)
                       .arg(nom)
                       .arg(prenom)
                       .arg(nbr_reservations);
    }

    if (message.isEmpty()) {
        message = "Aucun client n'a de réservation.";
    }

    QMessageBox::information(this, "Réservations par client", message);
}*/
/*void MainWindow::afficherReservationsParClient()
{
    Client client;
    QString clientFidele = client.clientLePlusFidele();  // Récupère le nom du client le plus fidèle

    if (!clientFidele.isEmpty()) {
        QMessageBox::information(this, "Client le plus fidèle", "Le client le plus fidèle est : " + clientFidele);
    } else {
        QMessageBox::information(this, "Aucun client", "Aucun client n'a encore effectué de réservation.");
    }
}*/
/*void MainWindow::afficherClientLePlusFidele()
{
    Client client;
    QString clientFidele = client.clientLePlusFidele();  // Appel de la fonction

    // Afficher le résultat dans une boîte de dialogue
    QMessageBox::information(this, "Client le plus fidèle", clientFidele);
}*/
/*void MainWindow::afficherNbReservationsClients()
{
    Client client;
    QString result = client.afficherNbReservationsParClient();  // Appeler la fonction

    // Afficher le résultat dans un QMessageBox
    QMessageBox::information(this, "Nombre de réservations par client", result);
}*/

/*void MainWindow::afficherReservationsParClient() {
    Client client;
    QSqlQueryModel* model = client.obtenirReservationsParClient();

    if (!model || model->rowCount() == 0) {
        QMessageBox::information(this, "Information", "Aucun client n'a de réservation.");
        return;
    }

    QString message;

    for (int i = 0; i < model->rowCount(); ++i) {
        int idc = model->record(i).value("IDC").toInt();
        QString nom = model->record(i).value("NOMC").toString();
        QString prenom = model->record(i).value("PRENOMC").toString();
        int nbr_reservations = model->record(i).value("nbr_reservations").toInt();

        message += QString("Client ID: %1, Nom: %2, Prénom: %3, Nombre de réservations: %4\n")
                       .arg(idc)
                       .arg(nom)
                       .arg(prenom)
                       .arg(nbr_reservations);
    }

    QMessageBox::information(this, "Réservations par client", message);
}
*/

void MainWindow::on_pushButton_client_fidele_clicked()
{
    Client client;
    QSqlQueryModel* model = client.obtenirReservationsParClient();
    if (model) {
        QString result;
        int maxReservations = 0;  // Stocke le nombre maximal de réservations
        QString plusFidele;       // Stocke les informations du client le plus fidèle

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

/*void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}*/

//mailing

/*void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("malekknani4@gmail.com",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("malekknani4@gmail.com", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("malekknani4@gmail.com", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}



/*void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("malekknani4@gmail.com",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("malekknani4@gmail.com", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("malekknani4@gmail.com", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}*/

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

/*void MainWindow::update_label()
{
    data=A.read_from_arduino();
    if(data=="1")
        ui->label_3->setText();
}*/




