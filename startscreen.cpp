#include "startscreen.h"

StartScreen::StartScreen(QWidget *parent, MainWindow *m) : QWidget(parent), main(m)
{
  start = new QPushButton("START");
  start->setFixedSize(70, 30);
  quit = new QPushButton("QUIT");
  quit->setFixedSize(70,30);
  layout = new QHBoxLayout;
  layout->addWidget(start);
  layout->addWidget(quit);
  setLayout(layout);
  
  connect(start, SIGNAL(clicked()), this, SLOT(handleStart()));
}

void StartScreen::handleStart()
{
  main->gameStart();
}

QPushButton* StartScreen::getQuit()
{
  return quit;
}
