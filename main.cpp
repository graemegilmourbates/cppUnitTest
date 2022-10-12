#include "test.h"
#include <iostream>

int sum(int a, int b){
  return a+b;
}

void test_negative_inputs(test_result& r){
  if(sum(1,-2)==-1){
    r.passed = true;
  } else {
    r.log="Expected: -1 Got: "+std::to_string(sum(1,-2));
    r.passed = false;
  }
}

void bar(test_result& r){
  r.log="Intentional fail";
  r.passed=false;
}

int main(){
  Test tester=Test("Sum function tests", "Test Negatives", test_negative_inputs);
  tester.add_test("Bar", bar);
  tester.run();
  return 0;
}
