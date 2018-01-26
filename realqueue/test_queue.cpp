#include <iostream>
#include <cassert>
#include "queue.h"


#define ASSERT_WITH_MESSAGE(condition, message) \
		if (!(condition)) { printf((message)); } \
		assert ((condition)); 

using namespace std;

void test_basic();

int main(){

	return 0;
}

void test_basic(){
	ASSERT_WITH_MESSAGE(1==1,"true");
}