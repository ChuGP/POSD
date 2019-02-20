#ifndef MOCK_TREE_SIZE_H
#define MOCK_TREE_SIZE_H
#include "tree_frame.h"
#include "observer.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "node_iterator.h"

class MockTreeSize : public Observer {
public:
  MockTreeSize(TreeFrame * treeFrame) : _treeFrame(treeFrame) {
    _treeFrame->attach(this);
  }
  void update(Node * start){
    fstream test;
    test.open(start->path(),ios::out); 
    test << _treeFrame->GetCtrl()->GetValue() ;
    test.close();

  }

private:
  TreeFrame * _treeFrame;
};

#endif