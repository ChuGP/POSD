#include "file.h"
#include "folder.h"
#include "link.h"
#include "node.h"
#include <vector>
#include "find_link_visitor.h"

// void FindLinkVisitor::visitFolder(Folder * folder)
// {
//   NodeIterator * it = folder->createIterator();
//     for (it->first(); it->isDone() == false ; it->next() )
//     {
//       if ( S_ISLNK(it->currentItem()->getStat().st_mode) == true )
//       {
//         AllLink.push_back(it->currentItem());
//       } // if
//       if ( S_ISDIR(it->currentItem()->getStat().st_mode) == true )
//         it->currentItem()->acceptjump(this);
//     } // for
// } // visitFolder

void FindLinkVisitor::visitFolder(Folder * folder)
{
  NodeIterator * it = folder->createIterator();
    for (it->first(); it->isDone() == false ; it->next() )
    {
      it->currentItem()->acceptjump(this);
    } // for
} // visitFolder


void FindLinkVisitor::visitFile(File * file)
{
  return ;
} // visitFile

void FindLinkVisitor::visitLink(Link * link)
{
  AllLink.push_back(link);
} // visitLink

void FindLinkVisitor::clean()
{
  AllLink.clear();
} // clean
