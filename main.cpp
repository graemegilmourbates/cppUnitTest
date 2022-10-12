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
  auto sumTest=[]()->auto{
    int a = rand();
    int b = rand();
    result<int> r;
    r.result=sum(a,b);
    r.expected=a+b;
    r.passed=ASSERT(r.result, r.expected);
    return r;
  };
  auto sumOff=[]()->auto{
    int a=rand();
    int b=rand();
    result<int> r;
    r.result=sum(a,b);
    r.expected=a-b;
    r.passed=ASSERT((r.result==r.expected), false);
    return r;
  };
  auto testFail=[]()->auto{
    int a=rand();
    int b=rand();
    result<int> r;
    r.result=sum(a,b);
    r.expected=a-b;
    r.passed=ASSERT(r.result, r.expected);
    return r;
  };
  Test sumPass=Test("Sum test: Correct", sumTest);
  Test sumFail=Test("Sum test: Incorrect", sumOff);
  Test sumTestFail=Test("Sum test: FAILS", testFail);
  //sumTestFail.run();
  Test_Suite test=Test_Suite("Test", sumPass);
  test.run();
  return 0;
}
