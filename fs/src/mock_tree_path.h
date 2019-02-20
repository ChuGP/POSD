#ifndef MOCK_TREE_VIEW_H
#define MOCK_TREE_VIEW_H
#include "tree_frame.h"
#include "observer.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "node_iterator.h"

class MockTreePath : public Observer {
public:
  MockTreePath(TreeFrame * treeFrame) : _treeFrame(treeFrame) {
    _treeFrame->attach(this);
  }
  void update(Node * start){
    NodeIterator * it = start->createIterator();
      for (it->first(); it->isDone() == false ; it->next() )
      {
        char * newName = new char[( it->currentItem()->getParent()->path()+"/"+ it->currentItem()->name()).length() ];
        strcpy(newName,it->currentItem()->getParent()->path().c_str());
        strcat(newName,"/");
        strcat(newName,(it->currentItem()->name().c_str() ));
        it->currentItem()->setPath(newName) ;
        update(it->currentItem());
      } // for
  }

private:
  TreeFrame * _treeFrame;
};

#endif
