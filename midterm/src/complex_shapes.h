#ifndef COMPLEX_SHAPES_H
#define COMPLEX_SHAPES_H
#include<vector>
#include "shape.h"

using namespace std;
class ComplexShapes:public Shape
{
public:
    friend class FindAreaVisitor ; 
    ComplexShapes(vector<Shape*> *shapes)
    {
      _shapes = shapes;
    } // ComplexShapes
    void add(Shape *s);
    double area() const ;
    double perimeter() const;
    Shape * getChild(int index)
    {
      return _shapes->at(index) ;
    } // getChild
    
    void accept(FindAreaVisitor *fav)
    {
      fav->reset();
      acceptool(fav) ;
    } // accept

    void acceptool(FindAreaVisitor *fav)
    {
      fav->visit(this);
    }

    bool isComplex()
    {
      return true ;
    } // isDir
    int numberOfChild();
private:
    vector<Shape*> *_shapes ; 
};


#endif