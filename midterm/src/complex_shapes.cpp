#include "complex_shapes.h"
#include "shape.h"
using namespace std;
void ComplexShapes::add(Shape *s)
{
   _shapes->push_back(s) ;
} // add

double ComplexShapes::area() const{
  double area = 0.0;
  for (int i = 0 ; i < _shapes->size() ; i++)
  {
    area += _shapes->at(i)->area() ;
  } // for
  return area ;
} // area

double ComplexShapes::perimeter() const{
  double perimeter = 0.0;
  for (int i = 0 ; i < _shapes->size() ; i++)
  {
    perimeter += _shapes->at(i)->perimeter() ;
  } // for
  return perimeter ;
} // perimeter

int ComplexShapes::numberOfChild()
{
  return _shapes->size();
} // numberOfChild