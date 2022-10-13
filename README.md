# CPP Unit Test Framework


### All test functions must share a signature
Function signature is void type with a single reference to a test_result parameter
### Can be either defined functions or lambdas
```
void test_function(test_result& r){
	r.passed=true; //woo it passed
}

[](test_result& r)->void{
	r.passed=false; //ah man, it failed lets log it
	r.log="Test failed because...";
}
```


### Features:
- Generate Test Suite
- Log Test Data
- Store Test Data to a File
- More To come soon!

## Useage Example
```
int sum(int a, int b){
  return a+b;
}

void test_negative_inputs(test_result& r){
  if(sum(1,-2)==-1){
    r.passed=true;
  } else {
    r.log="Expected: -1 Got: "+std::to_string(sum(1,-2));
    r.passed=false;
  }
}

void will_fail(test_result& r){
  r.log="Intentional fail";
  r.passed=false;
}

int main(){
  Test tester=Test("Sum function tests");
  tester.add_test("Negative Number Test", test_negative_inputs);
  tester.add_test("Will fail test", will_fail);
  tester.add_test("Negative Number Test", test_negative_inputs);
  tester.run();
  return 0;
}
```

## Outputs
```
Running Test Suite: Sum function tests
	#### Running test 1 out of 2
	#### Running test 2 out of 2
	#### Intentional fail: Will fail test
Passed 1 out of 2
```
