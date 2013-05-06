#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include <QVBoxLayout>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QStackedLayout>
#include <QHBoxLayout>
#include "background.h"
#include "player.h"
#include "mainview.h"
#include "obstacle.h"
#include "mylist.h"
#include "jigglypuff.h"
#include "pokeball.h"
#include "starmie.h"
#include "startscreen.h"
#include <QLineEdit>
#include <QLabel>
#include "pause.h"
#include "restart.h"
#include "quit.h"
#include <string>
#include "username.h"
#include "chansey.h"
#include "maxlist.h"

#define WINDOW_MAX_X 800
#define WINDOW_MAX_Y 500

class MaxList;
class Username;
class Quit;
class Restart;
class Pause;
class StartScreen;
class MainView;

struct Score {
    int num;
    string name;
};
  

/** This class represents the main window that the user sees when playing the game.
 *  Inherits from the QWidget class.
 *  @author Janet Kim */
class MainWindow : public QWidget {
  Q_OBJECT
public:
  /** Constructor
   *  @param a_ The QApplication that is passed into from the main function */
  explicit MainWindow(QApplication *a_);
  
  /** Destructor */
  ~MainWindow();
  
  /** The show function is called in the main function and displays
   *  the GUI. */
  void show();
  
  /** Called by the MainView's keyPressEvent(). If the key pressed is the up key,
   *  it calls the player's rise() function.
   *  @param event A pointer to the QKeyEvent that can specify which
   *  key was pressed */
  void keyPressEvent(QKeyEvent *event);
  
  /** Called by the MainView's keyReleaseEvent(). If the key released is the up key,
   *  it calls the player's fall() function.
   *  @param event A pointer to the QKeyEvent that can specify which
   *  key was pressed */
  void keyReleaseEvent(QKeyEvent *event);
  
  /** Starts the timers and sets the current Widget to the MainView for the gameplay */
  void gameStart();
  
  /** Restarts the game */
  void restartGame();
//  QPushButton* getQuit();

  
//  void SpeedUp();
  
  /** Pauses the game and all the timers. */
  void pauseGame();
  
  /** Continues the game if the game was paused */
  void continueGame();
  
  /** Controls what is displayed when the user loses all of his/her lives */
  void lastLife();
  
  /** Sets the name of the user */
  void setName(std::string name_);
  
  /** Sets the visible widget to one that prompts the user to enter a username */
  void goToUsername();
  
  /** Write score to file */
  void writeScore();
  
  
private:
  
  
  
  /** A pointer to the QApplication that was passed in from the int main function */
  QApplication *a;
  
  /** The main widget which all other layouts
   *  and widgets are added to */
  QWidget *window;
  
  /** This layout has all the various screens (start screen, user name screen, etc.) */
  QStackedLayout *tabs;
  
  /** The start screen that displays the start and quit button */
  StartScreen *start_screen;
  
  /** The screen that prompts the user to enter a name */
  Username *name_screen;
  
//  /** High Score */
//  int high;
//  
//  /** The user with the highest score */
//  string high_name;
  
  
  MaxList *scores;
   
//  QVBoxLayout *layout;

  /** The rectangle that limits the size of the main scene*/
  QGraphicsRectItem *grid;
  
  /** Timer that controls how all the Things move.*/
  QTimer *timer;
  
  /** Timer that controls how the user moves */
  QTimer *timer_user;
  
  /** Timer that controls how the user dies */
  QTimer *timer_die;
  
//  /** Timer that controls how enemies are generated */
//  QTimer *timer_enemy;
//  QTimer *timer_jump;
  
  /** Controls how the user flies */
  QTimer *timer_rise;
  
  /** Controls how the user falls */
  QTimer *timer_fall;
  
  /** Controls how pokeballs are generated */
  QTimer *timer_pokeball;
  
  /** Controls how often the game speeds up */
  QTimer *speedUp;
  
  /** The main scene to which all the enemies and Things are added to */
  QGraphicsScene *scene;
//  QGraphicsView *view;

  /** The main view that holds the main scene */
  MainView *view;
  
  /** First Background Item */
  Background *bg_1;
  
  /** Second Background Item */
  Background *bg_2;
  
  /** The background image */
  QPixmap* bgPic;
  
  /** The main player */
  Player *user;
  
  /** The Pidget that flies with the main Player */
  Pidgey *bird;
  
  /** Standing image */
  QPixmap *stand;
  
  /** Left running image */
  QPixmap *left;
  
  /** Right running image */
  QPixmap *right;
  
  /** Open wings image */
  QPixmap *open;
  
  /** Closed wings image */
  QPixmap *closed;
  
  /** Starmie image */
  QPixmap *starmie;
  
  /** The image for lives left */
  QPixmap *icon;
  
  /** The pause button clicked image */
  QPixmap *pause_c;
  
  /** The pause unclicked button image */
  QPixmap *pause_u;
  
  /** The restart button image */
  QPixmap *restart;
  
  /** The quit button image */
  QPixmap *quit;
  
  /** The game over image */
  QPixmap *gameOver;
//  QPixmap *jigglypuff;

  /** Jigglypuff image 0 deg */
  QPixmap *jigglypuff;
  
  /** Jigglypuff image 45 deg */
  QPixmap *r1;
  
  /** Jigglypuff image 90 deg */
  QPixmap *r2;
  
  /** Jigglypuff image 135 deg */
  QPixmap *r3;
 
  /** Jigglypuff image 180 deg */
  QPixmap *r4;
 
  /** Jigglypuff image 225 deg */
  QPixmap *r5;
  
  /** Jigglypuff image 270 deg */
  QPixmap *r6;
 
  /** Jigglypuff image 315 deg */
  QPixmap *r7;
  
  /** The pokeball image */
  QPixmap *pokeball;
  
  /** The hyper beam image */
  QPixmap *beam;
  
  /** Standing Chansey image */
  QPixmap *chansey_stand;
  
  /** Moving left Chansey image */
  QPixmap *chansey_left;
  
  /** Moving right Chansey image */
  QPixmap *chansey_right;
  
  /** List that holds all the enemies */
  MyList<Thing*> badThings;
  
  /** List that holds all the good Things */
  MyList<Thing*> goodThings;
  
  /** List that holds all the timers */
  MyList<QTimer*> timers;
  
  /** List that holds all the timers that need to be restarted
   *  after the game is paused */
  MyList<int> timersToStart;
  
//  /** Things that are deleted */
//  MyList<Thing*> thingsToDelete;
  
  /** Image of the boulder */
  QPixmap *obstacle;
  
  /** The text box that displays the score */
  QLineEdit *score;
  
  /** The label that states "Score" */
  QLabel *scoreLabel;
  
  /** The label that states the user's name */
  QLabel *user_name;
  
  /** The label that states the current level */
  QLabel *level;
  
  /** The label that states the high score */
  QLabel *high_score;
  
  /** The layout that will hold the score, scorelabel, level, and user name */
  QVBoxLayout *toplayout;
  
  /** The layout that holds the score, the scoreLabel and the level */
  QHBoxLayout *scorelayout;
  
  /** The widget which sets the layout to scoreLayout */
  QWidget *scoreWidget;
  
  /** Indicates whether the user has died */
  bool dead;
  
  /** Indicates whether a pattern has already started being generated for pokeballs */
  bool pokeball_start;
  
  /** Indicates whether it's the first time the game is starting */
  bool first;
  
  /** Indicates whether the game is paused */
  bool paused;
  
  /** A counter to control how many boulders are created */
  int obst;
  
  /** A counter to control how many starmies are created */
  int star;
  
  /** A counter to control how many jigglypuffs are created */
  int puff;
  
  /** A counter for how many pokeballs are created */
  int generating;
  
  /** The random pattern for which the pokeballs should be created */
  int what;
  
  /** The random y position for which the pokeballs should be created */
  int initialy;
  
  /** The time interval to which the timers are set */
  double time;
  
  /** The velocity at which the items are all moving horizontally */
  double vx;
  
  /** The user name of the player */
  std::string name;
  
  /** The last life icon */
  QGraphicsPixmapItem *lastIcon;
//  QApplication *a;
//  QList<QGraphicsItem*> collisions;
  
//  QApplication *app;
  
public slots:
  /** Moves all of the items within the scene. Also tests for any collisions. */
  void handleTimer();
  
  /** Moves the user as he walks on the floor  */
  void handleTimer_user();
//  void handleTimer_jump();

  /** Generates enemies like jigglypuffs, boulders, etc. */
  void generateEnemy();
  
  /** Moves the player when he dies until he moves off the screen. Then it calls restartGame */
  void handleTimer_die();
  
  /** Moves the player as he flies */
  void handleTimer_rise();
  
  /** Moves the player as he falls */
  void handleTimer_fall();
  
  /** Generates pokeballs in various patterns */
  void generatePokeballs();
  
  /** Speeds up the game by making the timer intervals shorter. */
  void handle_speedUp();
  
  /** Calls the quit function from the QApplication that was passed into the
   *  constructor. */
  void callQuit();
  
//  void debug();

  
};

#endif
