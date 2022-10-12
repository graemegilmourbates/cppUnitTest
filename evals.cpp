/*
  Author: Graeme Bates
  Unit Test Framework
*/
#include <iostream>
#include "evals.h"
using namespace std;

template <typename T>
bool ASSERT(T result, T expected){
  return result==expected;
}

//Check equal
template <typename T>
bool ASSERT_EQUAL(T result, T expected){
  return result==expected;
}
//Special case for string being almost equal
bool ASSERT_ALMOST_EQUAL(string result, string expected, int variance){
  int test_length=result.length();
  int actual_length=expected.length();
  if(abs(test_length-actual_length)>variance){ return false; }
  int i=0;
  int diff=0;
  if(test_length>actual_length){
    while(i<test_length){
      if(result[i]!=expected[i]){ diff++; }
      i++;
    }
  } else {
    while(i<actual_length){
      if(result[i]!=expected[i]){ diff++; }
      i++;
    }
  }
  return diff<variance;
}
//General case for numbers
template <typename T>
bool ASSERT_ALMOST_EQUAL(T result, T expected, T variance){
  T diff=abs(result-expected);
  return diff<variance;
}
