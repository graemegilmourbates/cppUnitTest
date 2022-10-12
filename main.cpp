#include "test.h"
#include <iostream>

int sum(int a, int b){
  return a+b;
}

const void test_negative_inputs(test_result& r){
  if(sum(1,-2)==-1){
    r.passed=true;
  } else {
    r.log="Expected: -1 Got: "+std::to_string(sum(1,-2));
    r.passed=false;
  }
}

const void will_fail(test_result& r){
  r.log="Intentional fail";
  r.passed=false;
}

int main(){
  Test tester=Test("Sum function tests");
  tester.add_test("Negative Number Test", test_negative_inputs);
  tester.add_test("Will fail test", will_fail);
  tester.add_test("Negative Number Test", test_negative_inputs);
  tester.run();
  return 0;
}
