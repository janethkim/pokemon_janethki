#include "username.h"

Username::Username(QWidget *parent, QPixmap *bg_, MainWindow *m)
 : QGraphicsView(parent), main(m), bg(bg_)
{
  scene = new QGraphicsScene;
  setScene(scene);
  background = new QGraphicsPixmapItem( *bg );
  scene->addItem(background);
  enter = new QPushButton("Enter Username");
  name = new QLineEdit;
  overall = new QWidget(this);
  
  layout = new QVBoxLayout;
  overall->setLayout(layout);
  layout->addWidget(name);
  layout->addWidget(enter);
  
  overall->setGeometry(QRect(250,150, 300, 200));
  
  grid = new QGraphicsRectItem(0, 0, 800, 500);
  scene->setSceneRect(grid->rect());
  
  setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
  setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
  
  connect(enter, SIGNAL(clicked()), this, SLOT(handleEnter()));  
}

void Username::handleEnter()
{
  if (name->text().isEmpty())
  {
    name->setText("Enter a username.");
    return;
  }
  
  main->setName(name->text().toStdString());
  main->gameStart();
}
