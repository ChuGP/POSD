#ifndef rectangle_h
#define rectangle_h
#include "shape.h"
using namespace std; 
class Rectangle:public Shape
{
public:
  Rectangle(double l, double w):_l(l),_w(w)
  {
  } // Rectangle

  double area() const
  {
    return ( _l * _w) ;
  } // area

  double perimeter() const
  {
    return ( 2 * ( _l + _w) ) ;
  } // perimeter

 double compactness() const
  {
    double area_num = area();
    double perimeter_num = perimeter();
    if ( area_num == 0 ){
      throw std::string ("Division by zero")  ;
    } // if
    else {
      
      double temp = ( perimeter_num * perimeter_num )  / area_num;
      return temp;
    } // else
    
  } // compactness()

private:
  double _l,_w;

};

#endif