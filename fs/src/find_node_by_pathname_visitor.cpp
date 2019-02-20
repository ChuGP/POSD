#include "file.h"
#include "folder.h"
#include "link.h"
#include "node.h"
#include <iostream>
#include "find_node_by_pathname_visitor.h"
using namespace std;
  void FindNodeByPathnameVisitor::visitFolder(Folder * folder)
  {
    if ( _pathnames->size() != 0 &&  folder->name() == _pathnames->at(temp))
    {
      if ( temp == _pathnames->size()-1 ) 
        ans = folder ;
      else
      {
        temp++ ;
        NodeIterator * it = folder->createIterator();
        for (it->first(); it->isDone() == false ; it->next() )
        {
          if ( it->currentItem()->name() == _pathnames->at(temp))
            it->currentItem()->acceptjump(this);
        } // for
      } // else
    } // if
  } // visitFolder

  void FindNodeByPathnameVisitor::visitFile(File * file)
  {
    if (_pathnames->size() != 0 && file->name() == _pathnames->at(temp) )
      ans = file ;
  } // visitFile

  void FindNodeByPathnameVisitor::visitLink(Link * link)
  {
    if (_pathnames->size() != 0 && link->name() == _pathnames->at(temp))
      ans = link ;
  } // visitLink
  
  void FindNodeByPathnameVisitor::clean()
  {
    ans = nullptr;
    temp = 0 ;
  } // clean()