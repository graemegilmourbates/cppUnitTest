Author: Graeme Bates
Unit Testing framework for C++

Goals:
  Include Helper Files for Evaluation(Checking results) evals.cpp
  Create Test Class that can manage test packages test.cpp
    Will register tests
  Create logger so tests can be logged rather than iostreamed logger.cpp

Errors:
  Test_Suite class gets templated to specific lambda function, will not accept new case
  as can be seen in main.cpp line 39
  
  produces:
    error: no viable conversion from '(lambda at main.cpp:39:5)' to 'const (lambda at main.cpp:28:5)'
