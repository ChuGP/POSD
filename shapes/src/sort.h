#ifndef sort_h
#define sort_h
#include<vector>
#include <functional>
#include "shape.h"
#include<algorithm>


class Sort{
    public:
      
      Sort(std::vector<Shape*>* v): _v(v)
      {
        
        
      } // Sort

      // bool *pFunc(Shape*,Shape*)
      void sortArea( std::function <bool (Shape*,Shape*)> gp )
      {
        std::sort(_v->begin(),_v->end(),gp) ;
      } // sortArea()


      void sortPerimeter(std::function <bool (Shape*,Shape*)> gp){
        std::sort(_v->begin(),_v->end(),gp) ;
      } // sortPerimeter()

      
      void sortCompactness(std::function <bool (Shape*,Shape*)> gp){
        std::sort(_v->begin(),_v->end(),gp) ;
      } // sortCompactness


     
    private:
      std::vector<Shape*>* _v;
      //You should use those functions as parameter for Sort::sortPerimeter()
      
};


 bool perimeterDescendingComparison(Shape *a, Shape *b)
 {
    return a->perimeter() > b->perimeter() ; 
 } // perimeterDescendingComparison
 
 bool perimeterAscendingComparison(Shape *a, Shape *b)
 {
    return a->perimeter() < b->perimeter(); 
 }// perimeterAscendingComparison
 


//You should use those objects as parameter for Sort::sortCompactness()
class CompactnessAscendingComparison{
  public:
  
  bool operator() (Shape *a, Shape *b) { return a->compactness() < b->compactness();}
  
 
};

class CompactnessDescendingComparison{
  public:
  bool operator() (Shape *a, Shape *b) { return a->compactness() > b->compactness() ;}
};

#endif

