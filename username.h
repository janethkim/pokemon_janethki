#ifndef USERNAME_H
#define USERNAME_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLineEdit>

class MainWindow;

/** The Username class is the screen where the user will enter their name.
 *  @author Janet Kim */
class Username : public QGraphicsView
{
  Q_OBJECT
public:
  /** The constructor for Username. Calls the QGraphicsView constructor.
   *  @param parent The parent QWidget
   *  @param bg_ The picture of the background
   *  @param m A pointer to the MainWindow so it can call its functions*/
  Username(QWidget *parent, QPixmap *bg_, MainWindow *m);
private:
  /** The button to press after entering your username */
  QPushButton* enter;
  
  /** The text box where the player can enter his/her name */
  QLineEdit* name;
  
  /** The pointer to the MainWindow being displayed */
  MainWindow *main;
  
  /** The scene which this view will hold */
  QGraphicsScene* scene;
  
  /** A pointer to the pixMap of the background */
  QPixmap *bg;
  
  /** The item that holds the picture of the background */
  QGraphicsPixmapItem* background;
  
  /** A grid to regulate the size of the scene */
  QGraphicsRectItem* grid;
  
  /** The layout within the view that places the button and 
   *  text box in a vertical order */
  QVBoxLayout *layout;
//  QPaintEvent *p;
  QWidget *overall;
  
public slots:
  /** The handleEnter() slot that will proceed to the main gameplay
   *  if the input was valid. */
  void handleEnter();

};

#endif
