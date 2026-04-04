# cppUnitTest

A lightweight, single-header unit testing framework for C++. No dependencies, no installation — just drop `test.h` into your project and start writing tests.

## Installation

Copy `test.h` into your project. That's it.

```cpp
#include "test.h"
```

## Quick Start

```cpp
#include "test.h"

int sum(int a, int b) { return a + b; }

void test_negative_inputs(test_result& r) {
    if (sum(1, -2) == -1) {
        r.passed = true;
    } else {
        r.log = "Expected: -1, Got: " + std::to_string(sum(1, -2));
        r.passed = false;
    }
}

int main() {
    Test suite("Sum function tests");
    suite.add_test("Negative inputs", test_negative_inputs);
    suite.add_test("Intentional fail", [](test_result& r) {
        r.log = "Not implemented yet";
        r.passed = false;
    });
    suite.run();
    return 0;
}
```

Output:

```
Running: Sum function tests
    #### Test 1 : 2 PASS
    #### Test 2 : 2 FAILED
        Not implemented yet on Test: Intentional fail
Passed 1 out of 2
```

Pass/fail results are color-coded green and red in the terminal.

## Test Functions

All test functions share the same signature — `void` return, single `test_result&` parameter. They can be either named functions or lambdas:

```cpp
// Named function
void my_test(test_result& r) {
    r.passed = true;
}

// Lambda
auto my_lambda = [](test_result& r) -> void {
    r.passed = false;
    r.log = "Failed because...";
};
```

The `test_result` struct has three fields you care about:

| Field | Type | Purpose |
|---|---|---|
| `passed` | `bool` | Whether the test passed |
| `log` | `std::string` | Message printed on failure |
| `description` | `std::string` | Set automatically from `add_test()` |

## Repeating Tests

For randomized or stress tests, register a test with a repeat count. The suite runs it N times and reports how many passed:

```cpp
suite.add_test("Random input stress test", [](test_result& r) {
    int x = rand() % 100;
    r.passed = (x >= 0); // trivially true, but you get the idea
}, 100); // run 100 times
```

Output reports `Passed N out of 100` for the batch.

## Saving Results to a File

Pass a filename to `run()` to write results to disk instead of stdout:

```cpp
suite.run("results.txt");
```

## API Reference

```cpp
// Create a named test suite
Test suite("My Suite");

// Add a single test
suite.add_test("test name", test_function);

// Add a repeating test (runs N times, reports pass rate)
suite.add_test("test name", test_function, N);

// Run and print to stdout (color-coded)
suite.run();

// Run and write to file
suite.run("output.txt");
```

## License

MIT
