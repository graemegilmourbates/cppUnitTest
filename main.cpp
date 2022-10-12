#include <vector>
#include <iostream>
#include "test.h"
#include "test.cpp"
#include "evals.h"
#include "evals.cpp"
#include "logger.h"
#include "test_suite.h"
#include "test_suite.cpp"

using namespace std;

int sum(int a, int b){
  int i=0;
  int out=a;
  while(i<b){
    out+=1;
    i++;
  }
  return out;
}

int main(){
  srand((unsigned) time(NULL));
  Test_Suite test=Test_Suite(
    "Test for sum function",
    "Test Against Built in:",
    []()->auto{
      int a=rand();
      int b=rand();
      result<int> r;
      r.result=sum(a,b);
      r.expected=a+b;
      r.passed=ASSERT(r.result, r.expected);
      return r;
  });
  test.add_test(
    "Test Wrong Answers",
    []()->auto{
      int a=0;
      int b=0;
      result<int> r;
      r.result=sum(a,b);
      r.expected=5;
      r.passed=ASSERT(r.result, r.expected);
      return r;
    }
  );
  test.run();
  return 0;
}