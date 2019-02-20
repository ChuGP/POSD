#ifndef INFO_VISITOR_H
#define INFO_VISITOR_H
#include "node_visitor.h"
#include <string>
class InfoContentVisitor:public NodeVisitor
{
  public:
    InfoContentVisitor(){} // FindVisitor
    void visitFile(File * file);
    void visitFolder(Folder * folder);
    void visitLink(Link *link);
    void clean();
    int getContentSize()
    {
      return _size;
    } // getContentSize
  private:
    int _size ;
};
#endif