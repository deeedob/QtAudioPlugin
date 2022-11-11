#include <QApplication>
#include "main_window.h"

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);
    MainWindow mainWin(nullptr);
    mainWin.resize(800, 400);
    mainWin.show();
    return app.exec();
}