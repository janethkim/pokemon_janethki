#ifndef MAXLIST_H
#define MAXLIST_H
#include <list>
#include "mainwindow.h"

class MainWindow;
struct Score;
/** MaxList implements a sorted list of Scores
 *  from largest to smallest
 *  @author Janet Kim
 */
class MaxList
{
 public:
  /** Default constructor. */
  MaxList();
  
  /** Default destructor. */
  ~MaxList();
  
  /** Gives the size of the list.
   * @return Returns the size of items in the list */
  int size() const { return slist_.size(); }
  
  /** Indicates whether list is empty or not.
   * @return Returns true if the list is empty */
  bool empty() const { return slist_.empty(); }
  
  /** Adds a puzzle move to the sorted list
   * @param new A pointer to the Score to be added */
  void push(Score* newscore);
  
  /** Removes the maximum scored (front) score */
  void pop();
  
  /** Removes the minimum scored (back) score */
  void pop_back();
  
  /** Returns Score at indicated position */
  Score* at(int pos);
  
  /** Returns the Score with the highest score
   * @return Returns the first item in the list */
  Score* top();
  
  /** Returns the Score with the lowest score
   *  @return Returns the last item in the list */
  Score* bottom();
  
  /** Clears the list */
  void clear();
  
 private:
  /** the sorted list */
  std::list<Score*> slist_;
};

#endif
