#include "test.h"
#include <iostream>

int sum(int a, int b){
  return a+b;
}

void test_negative_inputs(test_result& r){
  if(sum(1,-2)==-1){
    r.passed=true;
  } else {
    r.log="Expected: -1 Got: "+std::to_string(sum(1,-2));
    r.passed=false;
  }
}

void will_fail(test_result& r){
  r.log="Intentional fail";
  r.passed=false;
}

void test_random_cases(test_result& r){
  int a = rand();
  int b = rand();
  int result=sum(a,b);
  int expected=a+b;
  if(result==expected){
    r.passed=true;
  } else {
    r.passed=false;
  }
}

int main(){
  srand((unsigned) time(NULL));
  Test tester=Test("Sum function tests");
  tester.add_test("Negative Number Test", test_negative_inputs);
  tester.add_test("Will fail test", will_fail);
  tester.add_test("Random inputs", test_random_cases, 10);
  tester.run();
  return 0;
}
