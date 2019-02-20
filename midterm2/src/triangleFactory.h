#ifndef TRIANGLEFACTORY_H
#define TRIANGLEFACTORY_H
#include "triangle.h"
#include "factory.h"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
class TriangleFactory:public Factory
{
public:
  TriangleFactory()
  {
  } // triangle
  
  Shape * create(int a,int b,int c)
  {
    Shape * temp ;
    try
    {
      temp = new Triangle(a,b,c) ;
    }
    catch (string e)
    {
      return nullptr ;
    }
    
    return temp ;
  } // create

};
#endif