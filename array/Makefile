CXX = g++
CXXFLAGS = -std=c++14 -Wconversion -Wall -Werror -Wextra -pedantic -O3


TESTOBJECT = array_test.o
OBJECT = array.o
CORRECTOBJ = correct.o
CUSTOMOBJ = custom_test.o


CORRECTEXE = correct
EXECUTABLE = array
CUSTOMEXE = custom

all: clean run

correct: clean runcorrect

custom: clean runcustom

buildcorrect: $(TESTOBJECT)## compile provided correct implementation "make buildcorrect"
	$(CXX) $(CXXFLAGS) -o $(CORRECTEXE) $(TESTOBJECT) $(CORRECTOBJ)

buildcustom: $(CUSTOMOBJ) $(OBJECT)
	$(CXX) $(CXXFLAGS) -o $(CUSTOMEXE) $(CUSTOMOBJ) $(OBJECT)

build : $(TESTOBJECT) $(OBJECT)## compile your implementation "make build"
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(TESTOBJECT) $(OBJECT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp

run: build## AUTOMATICALLY CLEANS COMPILES AND RUNS YOUR CODE "make run"
	valgrind ./$(EXECUTABLE)

runcorrect: buildcorrect
	valgrind ./$(CORRECTEXE)

runcustom: buildcustom
	valgrind ./$(CUSTOMEXE)

help:
	@fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##//'

clean :## cleans directory "make clean"
	rm -f $(CORRECTEXE) $(EXECUTABLE) $(OBJECT) $(TESTOBJECT) $(CUSTOMEXE) $(CUSTOMOBJ)

.PHONY: runcorrect correct all run buildcorrect build help
