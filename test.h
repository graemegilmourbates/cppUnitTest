/*
  Author: Graeme Bates
*/
#include <iostream>
#include <vector>
#include <functional>
#include <fstream>

const std::string BUFF="#### ";
const std::string FAILURE="** ";
const std::string RED="\033[1;31m";
const std::string GREEN="\033[1;32m";
const std::string RESTORE="\033[0m";

struct test_result{
  std::string description;
  bool passed;
  std::string line;
  std::string log;
};

struct test_case{
  std::function<void(test_result&)> test;
  std::string description;
};

struct repeating_test{
  std::function<void(test_result&)> test;
  std::string description;
  int repeats;
};

class Test{
  public:
    Test(std::string);
    ~Test();
    void add_test(
      std::string,
      std::function<void(test_result&)>
    );
    void add_test(
      std::string,
      std::function<void(test_result&)>,
      int repeats
    );
    std::vector<test_result> run();
    std::vector<test_result> run(std::string);
    test_result run_repeating_test(repeating_test*);

    std::string description;
  private:
    std::vector<test_case*> tests;
    std::vector<repeating_test*> repeating_tests;
    test_result run_test(test_case*);
};

Test::Test(std::string test_suite_description){
  description=test_suite_description;
}

Test::~Test(){
  for(auto test : tests){
    delete test;
  }
}

void Test::add_test(
    std::string test_description,
    std::function<void(test_result&)> test
  ){
  test_case *tst=new test_case;
  tst->description=test_description;
  tst->test=test;
  tests.push_back(tst);
}

void Test::add_test(
  std::string test_description,
  std::function<void(test_result&)> test,
  int repeats
){
  repeating_test *tst=new repeating_test;
  tst->description=test_description;
  tst->test=test;
  tst->repeats=repeats;
  repeating_tests.push_back(tst);
}

test_result Test::run_repeating_test(repeating_test *test){
  int i=0;
  int passed=0;
  test_result batch_result;
  while(i<test->repeats){
    test_result r;
    test->test(r);
    if(r.passed){ passed++; }
    i++;
  }
  batch_result.description=test->description;
  batch_result.log="Passed ";
  batch_result.log+=std::to_string(passed);
  batch_result.log+=" out of " + std::to_string(test->repeats);
  if(passed==test->repeats){
    batch_result.passed=true;
  } else { batch_result.passed=false; }
  return batch_result;
}

test_result Test::run_test(test_case* tst){
  test_result r;
  r.description=tst->description;
  tst->test(r);
  return r;
}

std::vector<test_result> Test::run(){
  int i=1;
  int passed=0;
  int total=tests.size()+repeating_tests.size();
  std::vector<test_result> results;
  std::cout << "Running: " << description << std::endl;
  for(auto tst : tests){
    std::cout << "\t" << BUFF;
    std::cout << "Test " << i << " : " << total;
    test_result r=run_test(tst);
    if(r.passed){
      std::cout << GREEN <<" PASS" << RESTORE << std::endl;
      passed++;
    } else {
      std::cout << RED << " FAILED" << RESTORE << std::endl;
      std::cout << "\t\t";
      std::cout << RED << r.log << " ";
      std::cout << r.description << RESTORE << std::endl;
    }
    i++;
  }
  for(auto tst : repeating_tests){
    std::cout << "\t" << BUFF;
    std::cout << "Test " << i << " : " << total;
    auto r=run_repeating_test(tst);
    if(r.passed){
      std::cout << GREEN << " PASS" << RESTORE << std::endl;
      passed++;
    } else {
      std::cout << RED << " Fail" << RESTORE << std::endl;
      std::cout << "\t\t";
      std::cout << RED << r.log << " tests on: ";
      std::cout << r.description << RESTORE << std::endl;
    }
    i++;
  }
  std::cout << "Passed " << passed << " out of " << total << std::endl;
  return results;
}

std::vector<test_result> Test::run(std::string file){
  std::ofstream outFile;
  outFile.open(file);
  int i=1;
  int passed=0;
  int total=tests.size()+repeating_tests.size();
  std::vector<test_result> results;
  outFile << description << "\n";
  for(auto tst : tests){
    outFile << "\t" << BUFF;
    test_result r=run_test(tst);
    if(r.passed){
      outFile << " PASS ";
      outFile << tst->description << "\n";
      passed++;
    } else {
      outFile << " FAILED ";
      outFile << tst->description << "\n";
      outFile << "\t\t";
      outFile << r.log << " ";
      outFile << r.description << "\n";
    }
    i++;
  }
  for(auto tst : repeating_tests){
    outFile << "\t" << BUFF;
    auto r=run_repeating_test(tst);
    if(r.passed){
      outFile << " PASS ";
      outFile << tst->description << "\n";
      passed++;
    } else {
      outFile <<" Fail ";
      outFile << r.log << " tests on: ";
      outFile << r.description << "\n";
    }
    i++;
  }
  outFile << "Passed " << passed << " out of " << total << "\n";
  return results;
}
