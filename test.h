template <typename F>
struct test_case;

template <typename F>
struct result;

template <class F>
class Test{
  public:
    Test(std::string, const F&);
    void run();
  private:
    test_case<F> test_case;
};
