#include <iostream>
using namespace std;

template <class F>
Test_Suite<F>::Test_Suite(
    string suite_description,
    string test_description,
    const F& test
  ){
  description=suite_description;
  tests.push_back(Test(test_description, test));
}
template <class F>
void Test_Suite<F>::run(){
  int i=1;
  int number_of_test=tests.size();
  cout << description << endl;
  for(Test test : tests){
    cout << "Running test " << i << " out of " << number_of_test << endl;
    test.run();
    i++;
  }
}
