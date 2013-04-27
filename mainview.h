#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "mainwindow.h"

class MainWindow;

/** My own derived class from QGraphicsView that holds the main Scene.
 *  Allows me to register keyPressEvents.
 *  @author Janet Kim */
class MainView: public QGraphicsView {
public:
  /** Default Constructor */
  MainView() {}
  
  /** Constructor
   *  @param scene The main scene for the gameplay 
   *  @param w_ A pointer to the MainWindow 
   *  @param parent The parent QWidget */
  MainView(QGraphicsScene *scene, MainWindow* w_, QWidget* parent);
protected:
  /** Called when a key is pressed. Calls the keyPressEvent() of MainWindow.
   *  @param keyEvent A pointer to the QKeyEvent that can specify which
   *  key was pressed  */
  void keyPressEvent(QKeyEvent* keyEvent);
  
  /** Called when a key is released. Calls the keyReleaseEvent() of MainWindow.
   *  @param keyEvent A pointer to the QKeyEvent that can specify which key
   *  was pressed */
  void keyReleaseEvent(QKeyEvent* keyEvent);
private:
  /** A pointer to the MainWindow */
  MainWindow* w;
  
};

#endif
