#include "file.h"
#include "folder.h"
#include "node.h"
#include "link.h"
#include <vector>
#include "find_visitor.h"
#include <string>
using namespace std ;
    
  void FindVisitor::visitFile(File * file )
  {
    if ( file->name() == find )
    {
      result = find ;
    } // if
  } // visit_file
  
  void FindVisitor::visitLink(Link * link )
  {
    if ( link->getSource()->name() == find )
    {
      result = find ;
    } // if
  } // visit_file

  void FindVisitor::visitFolder(Folder * folder )
    {
      NodeIterator * it = folder->createIterator();
      for (it->first(); it->isDone() == false ; it->next() )
      {
        if ( it->currentItem()->name() == find )
        {
          findPath.push_back(it->currentItem()->path());
        } // if
        if ( S_ISDIR(it->currentItem()->getStat().st_mode) == true )
          it->currentItem()->acceptjump(this);
      } // for
    } // visit_folder


  void FindVisitor::setpath( string temp)
    {
      if ( path == "")
        path = temp ;
    } // setpath

    void FindVisitor::clean()
    {
      path = "", result = "" ;
      findPath.clear();
    } // clean