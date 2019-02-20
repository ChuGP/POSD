#ifndef LINK_H
#define LINK_H
#include "node.h"
#include "null_iterator.h"
#include "node_visitor.h"
class Link : public Node{
public:
  Link(char * path, Node * node = nullptr) : Node(path)
  {
    if( S_ISLNK(getStat().st_mode) == false)
      throw string("It is not Link!") ;
    this->addLink(node);
  }

  void accept(NodeVisitor * inv )
  {
    inv->clean();
    acceptjump(inv) ;
  } // accept

  void acceptjump(NodeVisitor * inv)
  {  
    inv->visitLink(this) ;
  } // acceptjump

  NodeIterator * createIterator()
  {
    return new NullIterator();
  } // createIterator

  void addLink(Node * node)
  {
    _source = node;
  } // addLink

  Node * getSource() {
    return _source;
  } // getSource
private:
  Node * _source;
};

#endif
