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
  cout << "\tRunning: " << test_case.description << endl;
  auto r=test_case.func();
  if(r.passed){
    cout << "\tTest pass" << endl;
  } else {
    cout << "\tTest fails" << endl;
    cout << "\tExpected: " << r.expected << " Got: " << r.result << endl;
  }
}
