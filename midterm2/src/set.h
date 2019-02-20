#ifndef SET_H
#define SET_H
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
class Set
{
public:
  Set(){}
  
  void add(string subset)
  {
    ans.push_back(subset);
  } // add

  void parser(const char * pathName,vector<string> &parser_pure_string)
  { 
    string temp ;
    for ( int i = 0; i < strlen(pathName); i++ )
    {   
        if ( pathName[i] == '0' || pathName[i] == '1'|| pathName[i] == '2' || pathName[i] == '3'||
             pathName[i] == '4' || pathName[i] == '5' || pathName[i] == '6'||pathName[i] == '7' || 
             pathName[i] == '8'||pathName[i] == '9')
        {
            temp+= pathName[i];
            if ( i == strlen(pathName)-1)
            {
              parser_pure_string.push_back(temp);
              temp = "";
            }
        } // if
        else if ( ( pathName[i] == ',' || pathName[i] == '}') && temp.length() != 0 )
        {
            parser_pure_string.push_back(temp);
            temp = "";
        }
        else
        {
            temp = "";
        } // else
    } // for

  } // parser

  string toString() const
  {
    string temp = "{";
    for (int i = 0; i < ans.size(); i++)
    {
      temp += ans[i] ;
      if ( i != ans.size()-1 )
        temp+=",";
    } // for

    temp += "}" ;

    return temp ;
  }

  Set * flattenedSet(Set * temp)
  {
    vector<string> pass = temp->getans();
    vector<string> ans ;
    for (int i = 0; i < pass.size(); i++)
    {
      char * pathName = new char[sizeof(pass[i])];
      strcpy(pathName,pass[i].c_str());
      parser(pathName,ans) ; // 存一份parser好的 
    } // for
    setans(ans) ;
    return temp ;
  } // flattenedSet()
  
  vector<string> getans()
  {
    return ans ;
  }

  void setans(vector<string> parser_pure_string)
  {
    ans = parser_pure_string ;
  }
private:
  vector<string> ans ;
};


#endif
