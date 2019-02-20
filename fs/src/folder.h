#ifndef FOLDER_H
#define FOLDER_H
#include "node.h"
#include "node_visitor.h"
#include "node_iterator.h"
#include <map>
using namespace std;

class Folder:public Node{
public:
  class FolderIterator : public NodeIterator
  {
    public:
    
    FolderIterator(Folder * folder):_folder(folder){}

    void first()
    {
      it = _folder->_children.begin();
    } // first

    Node* currentItem() 
    {
      if ( isDone() == true )
         throw string("no current item");
      return it->second ;
    } // currentItem()
    
    void next() 
    {
      if ( isDone() == true )
         throw string("moving past the end");
      it++;
    } // next

    bool isDone()
    {
      if (it == _folder->_children.end())
        return true ;
      else return false ;
    } // isDone


    private:
      Folder * _folder; 
      map<string,Node*>::iterator it ;

  };
  
  Folder(char* path):Node(path)
  {
    if(S_ISDIR(getStat().st_mode) == false)
      throw string("It is not Folder!") ;
  }

  void add(Node *node)
  {
    _children.insert(pair<string,Node*>(node->name(),node)) ;
    node->setParent(this) ;
  } // add
  
  int numberOfChildren() const
  {
    return _children.size(); 
  } // numberOfChildren
  
  void accept(NodeVisitor * inv )
  {
    inv->clean();
    inv->setpath(Node::path()) ;
    acceptjump(inv) ;
  } // accept

  void acceptjump(NodeVisitor * inv)
  {
    inv->visitFolder(this) ;
  } // acceptjump

  NodeIterator * createIterator()
  {
    return new FolderIterator(this);
  } // createIterator

private:
  map<string, Node *> _children;
};

#endif
