#include <string>

template <class F>
class Test_Suite{
  public:
    Test_Suite(std::string, std::string, const F&);
    std::string description;
    void run();
  private:
    vector<Test<F>> tests;
};
