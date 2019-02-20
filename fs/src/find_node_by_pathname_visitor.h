#ifndef FIND_NODE_BY_PATHNAME_VISITOR_H
#define FIND_NODE_BY_PATHNAME_VISITOR_H
#include "node.h"
#include "node_visitor.h"
#include <vector>
#include <iostream>
using namespace std;
class FindNodeByPathnameVisitor:public NodeVisitor{
  public:
    FindNodeByPathnameVisitor(std::vector<string>* pathnames):_pathnames(pathnames)
    {
    }
    void visitFolder(Folder * folder);
    void visitFile(File * file);
    void visitLink(Link * link);
    void clean();
    Node * getNode() const
    {
      return ans ;
    } //return the Node object if the path indicate the node in the file system, and if not, return nullptr.
  private:
    Node * ans = nullptr;
    int temp = 0 ;
    std::vector<string>* _pathnames ;
};

#endif