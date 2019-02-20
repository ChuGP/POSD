#ifndef SHAPE_H
#define SHAPE_H
#include<algorithm>

class Shape
{
public:
  Shape(){}
  virtual bool isTriangle()
  {
    return false ; // default false 需要的再override
  }
  
  virtual bool isOther()
  {
    return false ;
  }
};


#endif