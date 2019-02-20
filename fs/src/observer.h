#ifndef OBSERVER_H
#define OBSERVER_H
#include "node.h"
class Observer {
public:
  virtual void update(Node * start) = 0;

};

#endif
