#include <iostream>
using namespace std;

template <typename F>
struct test_case{
  string description;
  F func;
};

template <typename F>
struct result{
  bool passed;
  F result;
  F expected;
};

template <class F>
Test<F>::Test(string description, const F& function){
  test_case.description=description;
  test_case.func=function;
}

template <class F>
void Test<F>::run(){
  cout << "Running: " << test_case.description << endl;
  auto r=test_case.func();
  if(r.passed){
    cout << "Test pass" << endl;
  } else {
    cout << "Test fails" << endl;
    cout << "Expected: " << r.expected << " Got: " << r.result << endl;
  }
}
