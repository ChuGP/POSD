#ifndef Find_Link_VISITO_H
#define Find_Link_VISITO_H
#include "node.h"
#include "node_visitor.h"
class FindLinkVisitor:public NodeVisitor
{
    public:
        FindLinkVisitor(){};
        void visitFolder(Folder * folder);
        void visitFile(File * file);
        void visitLink(Link * link);
        void clean();
        vector<Node*>  getLinks()
        {
          return AllLink ;
        }//return the Link objects.
        
    private:
      vector<Node*> AllLink;
            
};
#endif