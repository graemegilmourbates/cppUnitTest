#include <iostream>
#include <vector>
#include <functional>

const std::string BUFF="#### ";
const std::string FAILURE="** ";

struct test_result{
  std::string description;
  bool passed;
  std::string line;
  std::string log;
};

struct test_case{
  std::function<void(test_result&)> test;//
  std::string description;
  test_case(){
    test=NULL;
    description="";
  }
};

class Test{
  public:
    Test(std::string);
    void add_test(std::string, const std::function<void(test_result&)>);
    std::vector<test_result> run();
    std::string description;
  private:
    std::vector<test_case*> tests;
};

Test::Test(std::string test_suite_description){
  description=test_suite_description;
}

void Test::add_test(std::string test_description, const std::function<void(test_result&)> test){
  test_case *blah=new test_case;
  blah->description=test_description;
  blah->test=test;
  tests.push_back(blah);
}

std::vector<test_result> Test::run(){
  int i=1;
  int passed=0;
  int total=tests.size();
  std::vector<test_result> results;
  std::cout << "Running: " << description << std::endl;
  for(auto foo : tests){
    std::cout << "\t" << BUFF;
    std::cout << "Running test " << i << " out of " << total << std::endl;
    test_result r;
    r.description=foo->description;
    foo->test(r);
    if(r.passed){
      passed++;
    } else {
      std::cout << "\t\t" << FAILURE << r.log << ": " << r.description << std::endl;
    }
    i++;
  }
  std::cout << "Passed " << passed << " out of " << total << std::endl;
  return results;
}
