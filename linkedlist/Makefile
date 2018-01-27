CXX = g++
CXXFLAGS = -std=c++14 -Wconversion -Wall -Werror -Wextra -pedantic -O3


TESTOBJECT = linkedlist_test.o
OBJECT = linkedlist.o
CORRECTOBJ = correct.o



CORRECTEXE = correct
EXECUTABLE = linkedlist

all: clean run

correct: clean runcorrect

buildcorrect: $(TESTOBJECT)## compile provided correct implementation "make buildcorrect"
	$(CXX) $(CXXFLAGS) -o $(CORRECTEXE) $(TESTOBJECT) $(CORRECTOBJ)

build : $(TESTOBJECT) $(OBJECT)## compile your implementation "make build"
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(TESTOBJECT) $(OBJECT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp

run: build## AUTOMATICALLY CLEANS COMPILES AND RUNS YOUR CODE "make run"
	valgrind ./$(EXECUTABLE)

runcorrect: buildcorrect
	valgrind ./$(CORRECTEXE)

help:
	@fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##//'

clean :## cleans directory "make clean"
	rm -f $(CORRECTEXE) $(EXECUTABLE) $(OBJECT) $(TESTOBJECT) 

.PHONY: runcorrect correct all run buildcorrect build help