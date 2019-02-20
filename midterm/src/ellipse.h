#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <math.h>
using namespace std; 
class Ellipse:public Shape{
public:
    friend class FindAreaVisitor ; 
    Ellipse(double a, double b):_a(a),_b(b)
    {

    } // Ellipse
    double area() const
    {
      return M_PI * _a * _b;
    } // area
    double perimeter() const
    {
       return 2 * M_PI * sqrt( ( (_a * _a) + (_b*_b) ) / 2 ) ;
    } // perimeter
private:
    double _a,_b;
};

#endif