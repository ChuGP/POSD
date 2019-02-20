#include "file.h"
#include "folder.h"
#include "link.h"
#include "info_content_visitor.h"
#include <iostream>
using namespace std;
  void InfoContentVisitor::visitFile(File * file)
  {
      _size += file->size() ;
  } // visit_file
  
  void InfoContentVisitor::visitLink(Link * link)
  {
    _size += link->getSource()->size() ;
  } // visit_file

  void InfoContentVisitor::visitFolder(Folder * folder)
  {
    NodeIterator * it = folder->createIterator();
    for (it->first(); it->isDone() == false ; it->next() )
    {
      it->currentItem()->acceptjump(this);
    } // for
  } // visit_folder

  void InfoContentVisitor::clean()
  {
    _size = 0 ;
  } //clean