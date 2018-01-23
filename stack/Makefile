CXX = g++
CXXFLAGS = -std=c++14 -Wconversion -Wall -Werror -Wextra -pedantic -O3
OBJECTS = StackOnVector.o StackOnVector_test.o correct.o

testcorrect : StackOnVector_test.o
	$(CXX) $(CXXFLAGS) -o testcorrect StackOnVector_test.o correct.o
test : StackOnVector_test.o	StackOnVector.o
	$(CXX) $(CXXFLAGS) -o test StackOnVector_test.o	StackOnVector.o
StackOnVector.o :
	$(CXX) $(CXXFLAGS) -c StackOnVector.cpp
StackOnVector_test.o :
	$(CXX) $(CXXFLAGS) -c StackOnVector_test.cpp
clean :
	rm test testcorrect StackOnVector_test.o StackOnVector.o
