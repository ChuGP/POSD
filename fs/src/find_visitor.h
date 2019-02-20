#ifndef FIND_VISITOR_H
#define FIND_VISITOR_H
#include "node_visitor.h"
#include <string>
using namespace std ;
class FindVisitor:public NodeVisitor
{
  public:
    FindVisitor(string temp):find(temp){} // FindVisitor    
    void visitFile(File * file );
    void visitFolder(Folder * folder );
    void visitLink(Link *link);
    void setpath( string temp) ;  
    void clean() ;
    string findResult()
    {
      if ( result != "" )
        return result ;
      for ( int i = 0; i < findPath.size() ; i++ )
      { 
        string temp = "." + findPath[i].substr(path.length(), findPath[i].length() );
        result += temp ;
        if ( i != ( findPath.size() - 1  )  ) 
          result += "\n";
        // cout << result << endl ;
      } // for   
      
      return result ;
    } // findResult

  private:
    string path = "", find = "", result = "" ;
    vector<string> findPath ;
};
#endif