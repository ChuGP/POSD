#include <gtest/gtest.h>
#include <stdio.h>
#include <iostream>
#include<algorithm>
#include <string>
#include <stdio.h>
#include "../src/storage.h"
#include "../src/tool.h"
#include "../src/shape.h"
#include "../src/sort.h"
#include "../src/circle.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"
#include "../src/sort.h"
#include<vector>



using namespace std;


int main(int argc, char *argv[]){
  testing::InitGoogleTest(&argc, argv);
  Storage temp ;
  ReadData(argv) ;
  Sort_input(argv) ;
  WriteData(argv);
  
}
