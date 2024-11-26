#include "Employe.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QSqlQuery>
#include <QDebug>
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
// Default Constructor
Employe::Employe() {}

// Parameterized Constructor
Employe::Employe(int id_e, QString nome, QString prenom, int salaire, int numero, QString datenaissancee)
{
    this->id_e = id_e;
    this->nome = nome;
    this->prenom = prenom;
    this->salaire = salaire;
    this->numero = numero;
    this->datenaissancee = datenaissancee;
}

// Add (Create) Employee
bool Employe::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYEE (ID_E, NOME, DATENAISSANCEE, PRENOM, NUMERO, SALAIRE) "
                  "VALUES (:id_e, :nome, :datenaissancee, :prenom, :numero, :salaire)");
    query.bindValue(":id_e", id_e);
    query.bindValue(":nome", nome);
    query.bindValue(":datenaissancee", datenaissancee);
    query.bindValue(":prenom", prenom);
    query.bindValue(":numero", numero);
    query.bindValue(":salaire", salaire);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de l'ajout de l'employé:" << query.lastError().text();
        return false;
    }
}

// Read (Display) Employee
QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYEE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date de naissance"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numéro"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));
    return model;
}

// Delete Employee by ID
bool Employe::supprimer2(int id_e)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYEE WHERE ID_E = :id_e");
    query.bindValue(":id_e", id_e);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de la suppression de l'employé:" << query.lastError().text();
        return false;
    }
}



// Update Employee
bool Employe::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYEE SET NOME = :nome, DATENAISSANCEE = :datenaissancee, "
                  "PRENOM = :prenom, NUMERO = :numero, SALAIRE = :salaire "
                  "WHERE ID_E = :id_e");
    query.bindValue(":id_e", id_e);
    query.bindValue(":nome", nome);
    query.bindValue(":datenaissancee", datenaissancee);
    query.bindValue(":prenom", prenom);
    query.bindValue(":numero", numero);
    query.bindValue(":salaire", salaire);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de la modification de l'employé:" << query.lastError().text();
        return false;
    }
}
QChartView* Employe::createSalaireDistributionChart()
{
    // Initialize counters for salary ranges
    int lowSalaryCount = 0;    // Salaries less than 2000
    int midSalaryCount = 0;    // Salaries between 2000 and 5000
    int highSalaryCount = 0;   // Salaries above 5000

    // Query to select all salaries from the employe table
    QSqlQuery query("SELECT salaire FROM EMPLOYEE");

    // Process the query result
    while (query.next()) {
        int salaire = query.value(0).toInt();

        // Increment the respective counter based on salary range
        if (salaire < 2000) {
            lowSalaryCount++;
        } else if (salaire <= 5000) {
            midSalaryCount++;
        } else {
            highSalaryCount++;
        }
    }

    // Create a bar set for salary ranges
    QBarSet *salaireSet = new QBarSet("Nombre d'employés");

    // Set the values for each category
    *salaireSet << lowSalaryCount << midSalaryCount << highSalaryCount;

    // Create a bar series and add the set to it
    QBarSeries *series = new QBarSeries();//représenter des séries de données sous forme de diagrammes
    series->append(salaireSet);

    // Create a chart and add the series to it
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Distribution des Salaires des Employés");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Set up categories for the x-axis
    QStringList categories;
    categories << "Moins de 2000" << "2000-5000" << "Plus de 5000";

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Create a value axis for the y-axis
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre d'employés");
    axisY->setRange(0, std::max({lowSalaryCount, midSalaryCount, highSalaryCount}));
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Create a chart view and return it
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}
void Employe::exportDataToPDF()
{
    QSqlQuery query;

    // Open a file dialog to get the file name for saving the PDF
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) {
        qDebug() << "No file selected. Aborting PDF generation.";
        return; // Exit if no file is selected
    }

    // Prepare query to retrieve all employees' data
    query.prepare("SELECT ID_E, NOME, PRENOM, SALAIRE, NUMERO, DATENAISSANCEE FROM EMPLOYEE");

    // Set up the printer for PDF output
    QPrinter printer(QPrinter::PrinterResolution);//qualite imprimante
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    // Start painting with QPainter
    QPainter painter; //pour dessiner des graphiques, du texte, des images
    if (!painter.begin(&printer)) { //diriger toutes les actions de peinture vers l'imprimante
        qDebug() << "Failed to begin painting on printer.";
        return; // Exit if painter fails to start
    }

    // Create the HTML structure for the PDF
    QString html = "<html><head><style>"
                   "body { font-family: Arial, sans-serif; margin: 20px; }"
                   "h1 { text-align: center; }"
                   "table { width: 100%; border-collapse: collapse; margin-top: 20px; }"
                   "th, td { border: 1px solid black; padding: 8px; text-align: center; }"
                   "th { background-color: #f2f2f2; }"
                   "</style></head><body>"
                   "<h1>Informations des Employés</h1>"
                   "<table>"
                   "<tr><th>ID</th><th>Nom</th><th>Prénom</th><th>Salaire</th><th>Numéro</th><th>Date de Naissance</th></tr>";

    // Execute the query
    if (query.exec()) {
        while (query.next()) {
            html += QString("<tr><td>%1</td><td>%2</td><td>%3</td><td>%4</td><td>%5</td><td>%6</td></tr>")
            .arg(query.value("ID_E").toString())
                .arg(query.value("NOME").toString())
                .arg(query.value("PRENOM").toString())
                .arg(query.value("SALAIRE").toInt())
                .arg(query.value("NUMERO").toInt())
                .arg(query.value("DATENAISSANCEE").toString());
        }
    } else {
        qDebug() << "Error retrieving data for EMPLOYEE table:" << query.lastError().text();
    }

    html += "</table></body></html>"; // Close the HTML structure

    // Create a QTextDocument to render the HTML content
    QTextDocument document;
    document.setHtml(html);

    // Render the document to the painter
    document.drawContents(&painter);
    painter.end(); // End the painting

    qDebug() << "PDF generated successfully!";
}
QSqlQueryModel* Employe::trier(const QString& sortColumn) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryStr;

    // Map valid sort columns
    QMap<QString, QString> validColumns;//lister les colonne pour etre accessible pour trier
    validColumns["id"] = "ID_E";
    validColumns["nom"] = "NOME";
    validColumns["prenom"] = "PRENOM";
    validColumns["salaire"] = "SALAIRE";
    validColumns["numero"] = "NUMERO";
    validColumns["date_naissance"] = "DATENAISSANCEE";

    // Validate sortColumn, default to "ID_E" if invalid
    QString columnName = validColumns.contains(sortColumn) ? validColumns[sortColumn] : "ID_E";

    // Construct the SQL query dynamically
    queryStr = QString("SELECT ID_E, NOME, PRENOM, SALAIRE, NUMERO, DATENAISSANCEE "
                       "FROM EMPLOYEE ORDER BY %1").arg(columnName);

    // Use QSqlQuery to execute the query separately
    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qDebug() << "Erreur lors de l'exécution de la requête de tri:" << query.lastError().text();
        return model; // Return empty model on failure
    }

    // Set the query to the model
    model->setQuery(query);

    // Check for errors in setting the query
    if (model->lastError().isValid()) {
        qDebug() << "Erreur dans le modèle de requête:" << model->lastError().text();
    }

    // Set headers for the model
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Salaire"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numéro"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de Naissance"));

    return model;
}
QSqlQueryModel* Employe::rechercher(const QString& searchType, const QString& value) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Map valid search types to database columns
    QMap<QString, QString> validColumns;
    validColumns["id"] = "ID_E";
    validColumns["nom"] = "NOME";
    validColumns["prenom"] = "PRENOM";
    validColumns["salaire"] = "SALAIRE";
    validColumns["numero"] = "NUMERO";
    validColumns["date_naissance"] = "DATENAISSANCEE";

    // Validate searchType and get the corresponding column name
    if (!validColumns.contains(searchType)) {
        qDebug() << "Invalid search type provided.";
        return model; // Return an empty model if the search type is invalid
    }
    QString columnName = validColumns[searchType];

    // Prepare the query dynamically based on the search column
    query.prepare(QString("SELECT ID_E, NOME, PRENOM, SALAIRE, NUMERO, DATENAISSANCEE "
                          "FROM EMPLOYEE WHERE %1 LIKE :value").arg(columnName));
    query.bindValue(":value", "%" + value + "%");

    // Execute the query
    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Salaire"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numéro"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de Naissance"));
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête de recherche:" << query.lastError().text();
    }

    return model;
}

