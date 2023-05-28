#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    QObject::connect(&w, &MainWindow::closeGameSignal, &app, &QCoreApplication::quit, Qt::QueuedConnection);
    w.show();
    return app.exec();
}
