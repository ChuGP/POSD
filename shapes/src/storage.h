#ifndef storage_h
#define storage_h
#include <fstream>
#include <string>
#include <iostream>
#include<vector>
using namespace std; 
class Storage{
  public:
    Storage()
    {
    } // Storage

    void reset(){
      shape_name = "";
      num.clear();
    } // reset

    string shape_name ;
    vector<double> num ;
  
};





#endif