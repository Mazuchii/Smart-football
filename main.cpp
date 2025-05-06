// main.cpp
#include "mainwindow.h" // Your main application window
#include "dialog.h"     // Your login dialog
#include "connection.h" // Your database connection class

#include <QApplication>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 1. Setup Database Connection
    Connexion dbConnection; // Create connection handler instance
    bool dbOk = dbConnection.ouvrirConnexion();

    if (!dbOk) {
        // Critical error: cannot connect to DB, so application cannot run.
        QMessageBox::critical(nullptr,
                              QObject::tr("Database Connection Error"),
                              QObject::tr("Failed to connect to the database.\n"
                                          "The application will now exit."),
                              QMessageBox::Ok);
        qCritical() << "Application exiting due to database connection failure at startup.";
        return 1; // Indicate an error exit status
    }
    qInfo() << "Database connection successfully established in main.";


    // 2. Show Login Dialog
    Dialog loginDialog;
    // loginDialog.setWindowTitle("User Login"); // Optional: Set a title

    int loginResult = loginDialog.exec(); // Show the dialog modally and wait for it to close

    MainWindow mainWindow; // Declare here, show only if login is successful

    if (loginResult == QDialog::Accepted) {
        // Login was successful (dialog called accept())
        qInfo() << "Login successful. Opening main application window.";
        mainWindow.show(); // Show the main application window
    } else {
        // Login failed or dialog was cancelled/closed
        qInfo() << "Login failed or dialog was cancelled. Application will exit.";
        dbConnection.fermerConnexion(); // Close DB connection before exiting
        return 0; // Normal exit, but didn't proceed to main app
    }

    // 3. Run Application Event Loop (if login was successful)
    int appExitCode = a.exec();

    // 4. Clean up: Close database connection when application is truly finishing
    qInfo() << "Application event loop finished. Closing database connection.";
    dbConnection.fermerConnexion();

    return appExitCode;
}
