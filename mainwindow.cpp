#include "client.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRegularExpression>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Cl.afficher());
    qDebug() << "MainWindow initialisé, prêt à écouter les événements.";
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::actualiserListeClients() {
    ui->tableView->setModel(Cl.afficher()); // Mettez à jour le modèle de la table
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



