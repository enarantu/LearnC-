CXX = g++
CXXFLAGS = -std=c++14 -Wconversion -Wall -Werror -Wextra -pedantic -O3
OBJECTS = stack.o stack_test.o correct.o

testcorrect : stack_test.o 				## compile provided correct implementation "make testcorrect"
	$(CXX) $(CXXFLAGS) -o testcorrect stack_test.o correct.o
test : stack_test.o stack.o 				## compile your implementation "make test"
	$(CXX) $(CXXFLAGS) -o test stack_test.o	stack.o
stack.o : 
	$(CXX) $(CXXFLAGS) -c stack.cpp
stack_test.o :
	$(CXX) $(CXXFLAGS) -c stack_test.cpp
run: test 					## AUTOMATICALLY CLEANS COMPILES AND RUNS YOUR CODE "make run"
	./test
	valgrind ./test
help:
	@fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##//'
clean :						## cleans directory "make clean"
	rm -f test testcorrect stack_test.o stack.o
