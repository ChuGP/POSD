#ifndef EDIT_NODE_H
#define EDIT_NODE_H
#include <wx/treebase.h>

#include "node.h"
class EditNode: public wxTreeItemData{

public:
  EditNode(Node * add): temp(add)
  {

  }

  Node * GetNode()
  {
    return temp ;
  }
private:
  Node * temp ;
};
#endif