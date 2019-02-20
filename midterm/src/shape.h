#ifndef SHAPE_H
#define SHAPE_H
#include "find_area_visitor.h"
#include <iostream>
using namespace std;
class Shape
{
public:
  friend class FindAreaVisitor ; 
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual void accept(FindAreaVisitor *fav)
  {
    return ;
  }
  virtual void acceptool(FindAreaVisitor *fav)
  {
    return ;
  }
  virtual Shape * getChild(int index)
  {
    cout << "error" ;
  } 
  virtual int numberOfChild()
  {
    return 0;
  }
  virtual bool isComplex()
  {
    return false ;
  } // isDir
private:
  
};
#endif