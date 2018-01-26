CXX = g++
CXXFLAGS = -std=c++14 -Wconversion -Wall -Werror -Wextra -pedantic -O3
OBJECTS = stack.o stack_test.o correct.o

all : clean test run

testcorrect : queue_test.o 				## compile provided correct implementation "make testcorrect"
	$(CXX) $(CXXFLAGS) -o testcorrect queue_test.o correct.o
test : queue_test.o queue.o 				## compile your implementation "make test"
	$(CXX) $(CXXFLAGS) -o test queue_test.o	queue.o
queue.o : 
	$(CXX) $(CXXFLAGS) -c queue.cpp
queue_test.o :
	$(CXX) $(CXXFLAGS) -c queue_test.cpp
run: test 					## AUTOMATICALLY CLEANS COMPILES AND RUNS YOUR CODE "make run"
	valgrind ./test
help:
	@fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##//'
clean :						## cleans directory "make clean"
	rm -f test testcorrect queue_test.o queue.o
