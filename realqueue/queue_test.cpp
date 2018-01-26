#include <iostream>
#include <cassert>
#include "queue.h"


using namespace std;

void massert(bool b, const char *c);
void test_basic();
void big_test();

int main(){
	test_basic();
	big_test();
	return 0;
}
void massert(bool b, const char *c){
	cout << c << endl;
	assert(b);
}
void test_basic(){
	cout << "basic test start" << endl;
	Queue q;
	q.push(1);
	massert(q.top() == 1, "top == 1 ; [1]");
	q.push(2);
	massert(q.top() == 1, "top == 1 ; [1,2]");
	q.push(3);
	massert(q.top() == 1, "top == 1 ; [1,2,3]");
	massert(!q.empty(), "not empty ; [1,2,3]");
	q.pop();
	massert(q.top() == 2, "top == 1 ; [2,3]");
	q.pop();
	massert(q.top() == 3,"top == 3; [3]" );
	massert(!q.empty(), "not empty ; [3]");
	q.pop();
	massert(q.empty(), "empty; []");
	q.push(2);
	massert(q.top() == 2 , "top == 2; [2]");
	massert(!q.empty(), "not empty ; [2]");
	q.pop();
	massert(q.empty(), "empty");
	cout << "basic test PASS!!" << endl;
}

void big_test(){
	cout << "big test" << endl;
	Queue q;
	for(int i = 1; i < 1000 ; i++){
		q.push(i);
	}
	for(int i = 1 ; i < 1000; i++){
		massert(q.top() == i, "top == i");
		q.pop();
	}
	massert(q.empty(),"empty");
	cout << "big test PASS!!" << endl;
}