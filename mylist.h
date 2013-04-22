#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include <stdexcept>
using namespace std;

/** MyList is a dynamically allocated array
 *  that acts as a list. Should operate the same as the
 *  vector class.
 *  @author Janet Kim
 */

//Using template for class definition of MyList
template <typename T>
class MyList {
private:
  /** The list*/
  T *list_;
  
  /** The size of the list */
  int size_;
  
  /** How much the list can hold */
  int capacity_;
public:
  /** Default Constructor.
   *  Dynamically allocates a list of size 1, capacity 1. */
  MyList() {
    list_ = new T[1];
    capacity_ = 1;
    size_ = 0;
  }
  
  /** Constructor that takes in the capacity of the list.
   * @param capacity Indicates the size of the dynamically allocated array.
   *    But size_ variable is initialized to 0.
   */
  MyList(int capacity) {
    list_ = new T[capacity];
    capacity_ = capacity;
    size_ = 0;
  }
  
  /** Destructor
   *  Frees up memory that was dynamically allocated for list_ */
  ~MyList() {
    delete [] list_;
    list_ = 0;
  }
  
  
  //Mutator Functions
  
  void push_back(T);
  bool remove(T);
  T pop(int);
  void clear();
  
  //Accessor Functions
  
  /** Returns the size of the array
   *  @return The size of the array*/
  int size() const {
    return size_;
  }
  
  /** Returns true if the array is empty.
   * @return True if the array is empty. */
  bool empty() const {
    if (size_ == 0)
      return true;
    else
      return false;
  }
  T& at(int loc) const;
  T& operator[](int loc) const;

};

/** Adds an element to the back of the list.
 *  @param val The value being add to the list */
template <typename T>
void MyList<T>::push_back(T val) {
    if (size_ == capacity_)
    {
      if (capacity_ == 0)
       { capacity_ = 1;}
      else
       { capacity_ *= 2;}
       
      T *temp = new T[capacity_];
      for (int index = 0; index < size_; index++)
        temp[index] = list_[index];
      delete [] list_; //deleting the small array
      list_ = temp; //assigning to the enlarged array
      temp = 0; //making it point to NULL
    }
    
    list_[size_++] = val;
}

/** Gives the value at the location specified by the user
 *  @param loc The location in the list/array 
 *  @return A reference to the value in the specified location */
template <typename T>
T& MyList<T>::at(int loc) const {
    if (loc >= size_ || loc < 0) {
      throw loc;
      }
      //throw invalid_argument("Location is not valid.");
    else
       return list_[loc];  
}

/** Uses an overloaded operator to do the same thing as the .at() function.
 *  Gives the value at the specified location.
 *  @param loc The location in the list
 *  @return A reference to the value at the location */
template <typename T>
T& MyList<T>::operator[](int loc) const {
  if (loc >= size_ || loc < 0)
      throw loc;
    else
       return list_[loc];
}

/** Removes the specified value and returns a bool to indicate
 *  if the operation was successful. 
 *  @param val The value to be removed from the list 
 *  @return A bool that is true if the value was successfully removed
 *  and false if it wasn't */
template <typename T>
bool MyList<T>::remove(T val) {
  bool flag = false;
  int index = 0;
  
  while (!flag && index < size_)
  {
    if (list_[index] == val)
    {
       flag = true;
       break;
    }
    index++;
  }
  
  if (flag)
  {
    for (int i = index; i < (size_ - 1); i++)
       list_[i] = list_[i+1];
    size_--;
  }
  
  return flag;

}

/** Removes value at a specified location from the list 
 *  @param loc The location in the list
 *  @return A copy of the value at the specified location */
template <typename T>
T MyList<T>::pop(int loc) {
   if (loc >= size_ || loc < 0)
      throw loc;
   else {
     T temp = list_[loc];
     
     if (loc < size_ - 1) {
       for (int i = loc; i < (size_ - 1); i++) {
          list_[i] = list_[i+1]; }
       }
     size_--;
     return temp;
   }
}
/** Checks whether any elements are currently in the list */
template <typename T>
void MyList<T>::clear()
{
  size_ = 0;
}



#endif
