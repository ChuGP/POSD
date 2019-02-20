#ifndef circle_h
#define circle_h
#include "shape.h"
#include <math.h>
using namespace std; 
class Circle:public Shape
{
public:
  Circle(double r):_r(r)
  {
  } // Circle

  double area() const
  {
    
    return M_PI * _r * _r;
    
  } // area

  double perimeter() const
  {
    return 2 * M_PI * _r;  // test
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
  double _r;
};

#endif