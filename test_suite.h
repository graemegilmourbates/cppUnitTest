#include <string>

template <class F>
class Test_Suite{
  public:
    Test_Suite(std::string, std::string, const F&);
    std::string description;
    void add_test(std::string, const F&);
    void run();
  private:
    vector<Test<F>> tests;
};
