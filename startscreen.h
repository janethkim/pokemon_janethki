#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include "mainwindow.h"

class MainWindow;

class StartScreen : public QWidget
{
  Q_OBJECT
public:
  StartScreen(QWidget *parent, MainWindow *m);
  QPushButton* getQuit();
  
private:
  QPushButton *start, *quit;
  MainWindow *main;
  QHBoxLayout *layout;
public slots:
  void handleStart();
 
  
};

#endif
