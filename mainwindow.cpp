#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QMap>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->tableView->setModel(serviceModel.afficher());
}

MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::on_supprimerButton_clicked() {
    int ids = ui->lineedit_id_rech->text().toInt();

    // Appel de la fonction de suppression avec vérification d'existence de l'ID
    bool test = serviceModel.supprimer(ids);

    if (test) {
        // Rafraîchissement du modèle pour afficher les données mises à jour
        ui->tableView->setModel(serviceModel.afficher());
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
        ui->tableView->setModel(serviceModel.afficher());
        QMessageBox::information(this, "Succès", "Service ajouté avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors de l'ajout du service.");
    }
}
void MainWindow::on_modifierButton_clicked() {
    int ids = ui->lineedit_id_modif->text().toInt();
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
        ui->tableView->setModel(serviceModel.afficher());
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
        ui->tableView->setModel(model);
        QMessageBox::information(this, "Recherche réussie", "L'ID recherché a été trouvé.");
    } else {
        // Si l'ID n'existe pas, afficher un message d'erreur
        QMessageBox::warning(this, "Erreur", "L'ID recherché n'existe pas dans la base de données.");
        delete model;  // Libérer la mémoire du modèle si aucun résultat n'est trouvé
    }
}
void MainWindow::on_trierButton_clicked() {
    ui->tableView->setModel(serviceModel.trierParPrix());
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
}
