#ifndef FACTORY_H
#define FACTORY_H
#include "shape.h"
class Factory
{
public:
  Factory()
  {
  
  } // triangle
  
  virtual Shape * create() {}; // 繼承他的自行決定實作
  
};
#endif