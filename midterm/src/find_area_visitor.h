#ifndef FIND_AREA_VISITOR_H
#define FIND_AREA_VISITOR_H
#include<vector>
#include<iostream>
class Shape;
using namespace std; 
class FindAreaVisitor {
public:
    FindAreaVisitor(double min, double max);
    void visit(Shape * shape) ;
    std::vector<Shape*> findResult(){
      vector<Shape*> temp = ans ;
      return temp ;
    }
    void reset()
    {
      ans.clear();
    }
private:
    double _min,_max ;
    vector<Shape*> ans ;
};
#endif