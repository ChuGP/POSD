#ifndef triangle_h
#define triangle_h
#include<algorithm>
#include "shape.h"
class Triangle: public Shape
{
public:
  Triangle(int a,int b,int c):edge_a(a),edge_b(b),edge_c(c)
  {
     edge[0] = edge_a;
     edge[1] = edge_b;
     edge[2] = edge_c;
     std::sort( edge, edge+3 );
     if ( isTriangle() == false )
     {
       throw  std::string ("illegal triangle")  ;
     } // if
  } // triangle
  
  bool isTriangle(){
    
    if ( (edge[0] < 0) || (edge[1] < 0) || (edge[2] < 0))
      return false ;

    if ( (edge[0] + edge[1] ) > edge[2] ){
      return true ;
    } // if
    else {
      return false ;
    } // else
  } // isTriangle()
  

private:
  int edge_a,edge_b,edge_c;
  int edge[3];
};


#endif