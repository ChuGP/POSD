#ifndef triangle_h
#define triangle_h
#include<algorithm>
#include "shape.h"

class Triangle:public Shape
{
public:
  Triangle(double x1,double y1,double x2,double y2,double x3,double y3):_x1(x1),_x2(x2),_x3(x3),_y1(y1),_y2(y2),_y3(y3)
  {
    edge_a = 0;
    edge_b = 0;
    edge_c = 0;
     edge_a = sqrt( pow( abs(_x1-_x2), 2 ) + pow( abs(_y1-_y2), 2 ) ); 
     edge_b = sqrt( pow( abs(_x1-_x3), 2 ) + pow( abs(_y1-_y3), 2 ) );
     edge_c = sqrt( pow( abs(_x2-_x3), 2 ) + pow( abs(_y2-_y3), 2 ) ) ;
     edge[0] = edge_a;
     edge[1] = edge_b;
     edge[2] = edge_c;
     std::sort( edge, edge+3 );
     if ( isTriangle() == false )
     {
       throw  std::string ("Not a triangle.")  ;
     } // if
  } // triangle
  
  bool isTriangle(){

    if ( (edge[0] + edge[1] ) > edge[2] ){
      return true ;
    } // if
    else {
      return false ;
    } // else
  } // isTriangle()

  double area() const
  {
    double temp =  ( edge_a + edge_b + edge_c) / 2;
    return  sqrt( temp *(temp -edge_a ) * (temp -edge_b ) * (temp - edge_c ) ) ;
  } // area

  double perimeter() const
  {
    return edge_a + edge_b + edge_c ;
  
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
  double _x1,_x2,_x3;
  double _y1,_y2,_y3;
  double edge_a,edge_b,edge_c;
  double edge[3];
};


#endif