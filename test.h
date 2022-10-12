template <typename F>
struct test_case{
  std::string description;
  std::function<F>* func;
};

template <typename F>
struct result{
  bool passed;
  F result;
  F expected;
};

template <class F>
class Test{
  public:
    Test(std::string, std::function<F>*);
    bool run();
  private:
    test_case<F> test_case;
};

template <class F>
Test<F>::Test(std::string description, std::function<F>* function){
  test_case.description=description;
  test_case.func=function;
}

template <class F>
bool Test<F>::run(){
  std::cout << "\tRunning: " << test_case.description << std::endl;
  auto r=test_case.func();
  if(r.passed){
    std::cout << "\tTest pass" << std::endl;
    std::cout << "\tExpected: " << r.expected << " Got: " << r.result << std::endl;
  } else {
    std::cout << "\tTest fails" << std::endl;
    std::cout << "\tExpected: " << r.expected << " Got: " << r.result << std::endl;
  }
  return r.passed;
}
