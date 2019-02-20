#ifndef VISITOR_H
#define VISITOR_H
#include<vector>
#include<string>
using namespace std;
class File;
class Folder;
class Link;

class NodeVisitor
{
  public:
    NodeVisitor(){}
    virtual void visitFile(File * file) = 0 ;
    virtual void visitFolder(Folder * folder) = 0;
    virtual void visitLink(Link * link) =0;
    virtual void clean() = 0;
    virtual void setpath( string temp) {} // setpath
    virtual string findResult(){} // getFindPath()
    virtual int getSize()
    {
      return 0;
    } // getSize
};
#endif