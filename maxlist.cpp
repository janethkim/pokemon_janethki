#include "maxlist.h"

MaxList::MaxList() : slist_()
{
}

MaxList::~MaxList()
{
  std::list<Score*>::iterator it;
  for (it = slist_.begin(); it != slist_.end(); ++it)
  {
    delete *it;
  }
}


void MaxList::push(Score* newscore)
{
  //---- Add your implementation to iterate through the list
  //---- to find the correct location to insert pm and then
  //---- use the insert() method of std::List to insert it
  //---- See http://www.cplusplus.com/reference/list/list/insert/
  
  std::list<Score*>::iterator it;
  bool notEnd = false; 
    
  for (it = slist_.begin(); it != slist_.end(); ++it)
  {
      if (newscore->num >= (*it)->num) 
      {
        notEnd = true; 
        slist_.insert(it, newscore); //inserts it into the position before the iterator's position
        break;
      }
  }
    
  if (!notEnd) //if it belongs at the end
    {  slist_.push_back(newscore);  }
  
}

// Pops off the first item in the list
void MaxList::pop()
{
  slist_.pop_front();
}

void MaxList::pop_back()
{
  slist_.pop_back();
}

Score* MaxList::bottom()
{
  return slist_.back();
}

Score* MaxList::top()
{
  return slist_.front();
}

Score* MaxList::at(int pos)
{
//  Score* temp;
  int count = 0;
  std::list<Score*>::iterator it;
  it = slist_.begin();
  
  while (it != slist_.end())
  {
    if (count == pos)
      return *it;
    else
    {
      count++;
      ++it;
    }
  }
  return NULL;
}

void MaxList::clear()
{
  std::list<Score*>::iterator it;
  
  for (it = slist_.begin(); it != slist_.end(); ++it)
  {
    delete *it;
  }
  slist_.clear();
}

