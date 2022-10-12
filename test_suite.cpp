#include <iostream>
using namespace std;

template <class F>
Test_Suite<F>::Test_Suite(string desc, const F& test){
  description=desc;
  tests.push_back(test);
}
template <class F>
void Test_Suite<F>::run(){
  cout << description << endl;
  cout << tests.size() << endl;
  cout << typeid(tests).name() << endl;
}
