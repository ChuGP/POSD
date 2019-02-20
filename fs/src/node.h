#ifndef NODE_H
#define NODE_H
#include <sys/stat.h>
#include<vector>
#include <string>
#include <cstring>
#include "null_iterator.h"
class NodeIterator;
class NodeVisitor;
using namespace std;
class Node
{
public:
  Node(char * path): _path(path)
  {
    if ( lstat(_path, &_st) != 0 )
      throw string("lstat failed!") ;
    name() ;
  }
  virtual void accept(NodeVisitor * inv ) = 0;
  virtual void acceptjump(NodeVisitor * inv ) {};
  int size() const
  {
    return _st.st_size;
  } // size
  
  string path()
  {
    string gp(_path) ;
    return gp ;
  } // getpath

  string Parser()
  {
    int want = 0;
    // cout << _path << endl ;
    // cout << _path[strlen(_path)-1]<<endl ;
    for ( int i = strlen(_path)-1; i >= 0; i-- )
    {
      if ( _path[i] == '/')
      {
        want = i+1 ;
        break;
      } // if     
    } // for

    string gp(_path);
    return gp.substr(want) ;
  } // Parser

  virtual void add(Node *node)
  {
    throw std::string("unable to add");
  } // add

  virtual int numberOfChildren() const
  {
    return 0;
  } // numberOfChildren

  virtual string name()
  {
    nodeName = Parser() ; // tool.h的func
    return nodeName;  
  } // name
  
  virtual NodeIterator * createIterator()
  {
    return new NullIterator();
  } // createIterator

  struct stat getStat()
  {
    return _st;
  } // getStat()

  Node * getParent() const{
    return _parent ;
  } // getParent()

  void setParent (Node * p){
    _parent = p ;
  } // setParent()
  
  void setPath(char * temp)
  {
    _path = temp ;
  }
private:
  char * _path;
  struct stat _st;
  Node * _parent = nullptr ;
  string nodeName ;
};
#endif
