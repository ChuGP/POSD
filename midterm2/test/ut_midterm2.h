#ifndef UT_MIDTERM2_H
#define UT_MIDTERM2_H
#include "../src/triangle.h"
#include "../src/triangleFactory.h"
#include "../src/factory.h"
#include "../src/set.h"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
// 1
TEST (TriangleTest, NormalTriangle) {
  Triangle gp(3,4,5);
  ASSERT_EQ(true, gp.isTriangle());
}
// 2
TEST (TriangleTest, illegal_Triangle) 
{
  try
  {
    Triangle gp(1,2,3);
  }
  catch (string e)
  {
    ASSERT_EQ("illegal triangle",e) ;
  }

  try
  {
    Triangle gp(-1,-2,-3);
  }
  catch (string e)
  {
    ASSERT_EQ("illegal triangle",e) ;
  }
}


TEST (TriangleFactoryTest, NormalTriangle) 
{

  TriangleFactory * temp  = new TriangleFactory() ; 
  Shape * ans = temp->create(3,4,5) ;
  ASSERT_NE(nullptr,ans) ; // 正確創建會回傳非null pointer
}


TEST (TriangleFactoryTest, illegalTriangle) 
{

  TriangleFactory * temp  = new TriangleFactory() ;
  Shape * ans = temp->create(1,2,3) ;
  ASSERT_EQ(nullptr,ans) ;// 非正確創建會回傳null pointer
}

// 3
TEST (SetTest, add) 
{
  Set * ans = new Set();
  ans->add("1");
  ans->add("{2}");
  ans->add("{3,4,{5,{}}}");
}

//4
TEST (SetTest, Tostring) 
{
  Set * ans = new Set();
  ans->add("1");
  ans->add("{2}");
  ans->add("{3,4,{5,{}}}");
  ASSERT_EQ("{1,{2},{3,4,{5,{}}}}",ans->toString());
}

//5
TEST (SetTest, flattenedSet) 
{
  Set * ans = new Set();
  ans->add("1");
  ans->add("{2}");
  ans->add("{3,4,{5,{}}}");
  ASSERT_EQ("{1,{2},{3,4,{5,{}}}}",ans->toString());
  Set * gp = new Set();
  gp = ans->flattenedSet(ans) ;
  ASSERT_EQ("{1,2,3,4,5}",gp->toString());
}
#endif