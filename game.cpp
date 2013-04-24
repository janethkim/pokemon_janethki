#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
  
    w.show();
    
    QPushButton* quit = w.getQuit();
    if (quit)
      QObject::connect(quit, SIGNAL(clicked()), &a, SLOT(quit()));

    return a.exec();
}
