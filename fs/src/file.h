#ifndef FILE_H
#define FILE_H

#include "node.h"
#include "node_visitor.h"
#include "null_iterator.h"
class File: public Node{

public:
  File(char * path): Node(path)
  {
    if(S_ISREG(getStat().st_mode) == false)
      throw string("It is not File!") ;
  }

  void accept(NodeVisitor * inv )
  {
    inv->clean();
    inv->setpath(Node::path()) ;
    acceptjump(inv) ;
  } // accept

  void acceptjump(NodeVisitor * inv)
  {  
    inv->visitFile(this) ;
  } // acceptjump

  NodeIterator * createIterator()
  {
    return new NullIterator();
  } // createIterator
};

#endif
