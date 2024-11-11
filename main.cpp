#include <QApplication>
#include "mainwindow.h"
#include "connection.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Establish database connection
    Connection connection;
    if (!connection.createConnection()) {
        QMessageBox::critical(nullptr, "Database Connection", "Failed to connect to the database.");
        return -1;
    }

    // Show the main window
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
