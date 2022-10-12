#include <string>

template <class F>
class Test_Suite{
  public:
    Test_Suite(std::string, std::string, function<F>*);
    std::string description;
    void add_test(std::string, function<F>*);
    void run();
  private:
    vector<Test<F>> tests;
};

template <class F>
Test_Suite<F>::Test_Suite(
    string suite_description,
    string test_description,
    function<F>* test
  ){
  description=suite_description;
  tests.push_back(Test(test_description, test));
}

template <class F>
void Test_Suite<F>::add_test(string description, function<F>* test){
  tests.push_back(Test(description, test));
}

template <class F>
void Test_Suite<F>::run(){
  int i=1;
  int number_of_test=tests.size();
  int passed=0;
  int failed=0;
  cout << description << endl;
  for(auto test : tests){
    cout << "Running test " << i << " out of " << number_of_test << endl;
    if(test.run()){ passed++; } else { failed++; }
    i++;
  }
  cout << "Passed " << passed << " out of " << number_of_test << endl;
}
