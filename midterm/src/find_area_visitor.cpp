#include "find_area_visitor.h"
#include "shape.h"
FindAreaVisitor::FindAreaVisitor(double min, double max):_min(min),_max(max)
{

}

void FindAreaVisitor::visit(Shape * temp)
{
  for (int i = 0; i < temp->numberOfChild(); i++)
  {
    if ( temp->getChild(i)->area() <= _max && temp->getChild(i)->area() >= _min )
      {
        ans.push_back(temp->getChild(i));
      } // if
      if ( temp->getChild(i)->isComplex() == true )
        temp->getChild(i)->acceptool(this);     
  } // for
}