#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include "mainwindow.h"
#include <QPalette>
#include <QGraphicsView>
#include <QGraphicsScene>


class MainWindow;


/** This class is the view for the start screen
 *  @author Janet Kim */
class StartScreen : public QGraphicsView
{
  Q_OBJECT
public:
  /** The constructor for the class. It calls the QGraphicsView
   *  constructor.
   *  @param parent The parent QWidget
   *  @param bg_ The Pixmap for the background picture of the QGraphicsView
   *  @param m A pointer to the MainWindow so we can call its functions */
  StartScreen(QWidget *parent, QPixmap *bg_, MainWindow *m);

  
private:
  /** The start button */
  QPushButton *start;
  
  /** The quit button */
  QPushButton *quit;
//  Start *start;
//  Quit *quit;

  /** A pointer to the MainWindow */
  MainWindow *main;
//  QPixmap* newGame;

  /** The scene for this QGraphicsView */
  QGraphicsScene* scene;
  
  /** The background picture */
  QPixmap *bg;
  
  /** The background item */
  QGraphicsPixmapItem* background;
  
  /** The rectangle that limits the size of the scene */
  QGraphicsRectItem* grid;
  
  /** The horizontal layout that the start and quit button are within */
  QHBoxLayout *layout;
//  QPaintEvent *p;

  /** The widget which includes the layout with the start and quit buttons */
  QWidget *buttons;
//  QApplication *a;
  
  
public slots:
  /** This function is called when the start button is clicked. It 
   *  calls the goToUsername() function in MainWindow */
  void handleStart();
//  void handleQuit();
 
  
};

#endif
