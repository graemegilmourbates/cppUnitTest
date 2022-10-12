#include <iostream>
#include <vector>

const std::string buff="#### ";

template <typename F>
struct test_case{
  F test;
  std::string description;
};

struct test_result{
  std::string description;
  bool passed;
  std::string line;
  std::string log;
};

template <class F>
class Test{
  public:
    Test(std::string, std::string, F);
    void add_test(std::string, F);
    std::vector<test_result> run();
    std::string description;
  private:
    std::vector<test_case<F>> tests;
};

template <class F>
Test<F>::Test(
    std::string suite_description,
    std::string test_description,
    F test
  ){
    test_case<F> blah;
    description=suite_description;
    blah.description=test_description;
    blah.test=test;
    tests.push_back(blah);
}

template <class F>
void Test<F>::add_test(std::string test_description, F test){
  test_case<F> blah;
  blah.description=test_description;
  blah.test=test;
  tests.push_back(blah);
}

template <class F>
std::vector<test_result> Test<F>::run(){
  int i=1;
  int passed=0;
  int total=tests.size();
  std::vector<test_result> results;
  std::cout << "Running Test Suite: " << description << std::endl;
  for(auto foo : tests){
    std::cout << "\t" << buff;
    std::cout << "Running test " << i << " out of " << total << std::endl;
    test_result r;
    r.description=foo.description;
    foo.test(r);
    if(r.passed){
      passed++;
    } else {
      std::cout << "\t" << buff << r.log << ": " << r.description << std::endl;
    }
    i++;
  }
  std::cout << "Passed " << passed << " out of " << total << std::endl;
  return results;
}
