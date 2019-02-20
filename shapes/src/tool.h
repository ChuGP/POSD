#ifndef tool_h
#define tool_h
#include <fstream>
#include <sstream>
#include <iostream>
#include<vector>
#include "../src/shape.h"
#include "../src/sort.h"
#include "../src/circle.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"
#include "../src/storage.h"

using namespace std;
Storage shap_info ; // storage物件
vector<Shape*>* all_shape = new vector<Shape*> ;
void New_Shape_And_Save() ;

void ReadData(char *argv[]){
  vector<char> temp ;
  fstream file ;
  string gp;
  char ch ;
  file.open( argv[1], ios::in) ;
  if ( !file )
    cerr << "檔案無法開啟" << endl; 
  else {
    int i = 0;
    while ( file.get(ch) ){
      
      temp.push_back(ch);
      // cout << temp[i];
      // i++;
    } // while
    
    i = 0;
    while ( i < temp.size()  )
    {
      
      if ( temp[i] == '0' || temp[i] == '1' || temp[i] =='2' || temp[i] =='3'
           || temp[i] == '4' || temp[i] == '5'|| temp[i] == '6' || temp[i] == '7' 
           || temp[i] == '8' || temp[i] == '9'|| temp[i] =='.')
      {
             gp += temp[i] ;
             
      } // if
      else if ( ( temp[i] > 'A' && temp[i] < 'Z' ) || ( temp[i] > 'a' && temp[i] < 'z' )  )
      {
        gp += temp[i] ;

      } // else if
      else if ( temp[i] == ' ') {
        shap_info.shape_name = gp;
        gp = "" ;
      } // else if
      else if ( temp[i] == ',' )
      { 
        double num = 0.0;
        stringstream(gp) >> num;
        shap_info.num.push_back(num) ;
        gp = "" ;
        int end = shap_info.num.size() - 1;
      } // else if
      else if ( temp[i] == ')' )
      {
        double num = 0.0;
        stringstream(gp) >> num;
        shap_info.num.push_back(num) ;
        
        int end = shap_info.num.size() - 1;
        New_Shape_And_Save() ;
        shap_info.reset();
        gp = "" ;
      }

      i++ ;
      
    } // while
    
    file.close();
    
  } // else
  
} // ReadData


void New_Shape_And_Save()
{
  if (shap_info.shape_name == "Circle")
  {
    
    Shape * a = new Circle(shap_info.num[0]);    
    all_shape->push_back(a);
    
  } // if
  else if (shap_info.shape_name == "Rectngle")
  {
    
    Shape * b = new Rectangle(shap_info.num[0],shap_info.num[1]);
    all_shape->push_back(b);

  } // if
  else if (shap_info.shape_name == "Tringle")
  {
    
    Shape * c = new Triangle(shap_info.num[0], shap_info.num[1], shap_info.num[2], shap_info.num[3], shap_info.num[4], shap_info.num[5] ) ;
    all_shape->push_back(c);
    

  } // if

} // New_Shape_And_Save()


void Sort_input( char *argv[]  )
{
  if ( strcmp(argv[3], "area") == 0 )
  {
    if ( strcmp( argv[4],"inc" ) == 0 )
    {
      Sort gp(all_shape);
      gp.sortArea([](Shape*a,Shape*b){ return a->area() < b->area() ; });
    } // if
    else if ( strcmp( argv[4],"dec" ) == 0 )
    {
      Sort gp(all_shape);
      gp.sortArea([](Shape*a,Shape*b){ return a->area() > b->area() ; });
    } // else if
  } // if
  else if ( strcmp(argv[3], "perimeter") == 0  )
  {
    if ( strcmp( argv[4],"inc" ) == 0  )
    {
      Sort gp(all_shape);
      gp.sortPerimeter([](Shape*a,Shape*b){ return a->perimeter() < b->perimeter() ; });
    } // if
    else if ( strcmp( argv[4],"dec" ) == 0 )
    {
      Sort gp(all_shape);
      gp.sortPerimeter([](Shape*a,Shape*b){ return a->perimeter() > b->perimeter() ; });
    } // else if

  } // else if
  
} // Sort()


void WriteData( char *argv[] )
{
  fstream file;

  file.open(argv[2], ios::out);      //開啟檔案
  if(!file)     //檢查檔案是否成功開啟
  {
      cerr << "檔案無法開啟" << endl; 
  } // if
  else 
  {
    file << '[';
    for(int i = 0; i < all_shape->size() ; i++)    
    {
      if ( strcmp(argv[3], "area") == 0 ) 
      {
        file << all_shape->at(i)->area() ;
        if ( i != all_shape->size() -1 ) {
          file << ',';
        } // if
      } // if
      else if ( strcmp(argv[3], "perimeter") == 0 ) 
      {
        file << all_shape->at(i)->perimeter() ;
        if ( i != all_shape->size() -1 ) {
          file << ',';
        } // if
      } // if

    } // for
    file << ']';

  } // else

} // WriteData



#endif