#include <iostream>
#include <cassert>
#include "linkedlist.h"

using namespace std;

void massert(bool b, const char *c);
void basic_test();
void iterator_test();
void big_3_test();
int main(){
	basic_test();
	iterator_test();
	big_3_test();
	cout << "\tPASSED ALL TESTS" << endl;
	return 0;
}
void massert(bool b, const char *c){
	if(!b){
		cout << c << endl;
		assert(b);
	}
}
void basic_test(){
	cout << "Start basic test" << endl;
	Linkedlist l;
	l.push_back(1);
	massert(l.front() == 1, "front = 1; [1]");
	massert(l.back() == 1, "back = 1;[1]");
	l.back() = 2;
	massert(l.front() == 2, "front = 2; [2]");
	massert(l.back() == 2, "back = 2;[2]");
	l.front() = 3;
	massert(l.front() == 3, "front = 3; [3]");
	massert(l.back() == 3, "back = 3;[3]");
	massert(l.size() == 1, "size = 1;[3]");

	l.push_front(5);
	massert(l.front() == 5, "front = 2;[5,3]");
	massert(l.back() == 3, "back = 3; [5,3]");
	massert(l.size() == 2, "size = 2;[5,3]");

	cout << "BASIC TEST PASS" << endl;
}

void iterator_test(){
	cout << "iterater test start" << endl;
	Linkedlist l;
	for(int i = 0; i < 10; i++){
		l.push_back(i);
	}
	
	int j = 0;
	for(auto i : l){
		assert(i == j);
		j++;
	}

	auto it = l.begin();
	int count = 0;
	massert(*it == count, "[0,1,2,3,4,5,6,7,8,9]; *it == 0");
	++it;
	++count;
	massert(*it == 1, "[0,1,2,3,4,5,6,7,8,9]; *it == 1");

	Linkedlist::Iterator it1, it2;

	it2 = it1 = it;

	massert(*it1 == count, "*it1 == 1");

	while(it2 != l.end()){
		massert(*it2 == count, "*it2 == count");
		++count;
		++it2;
	}
	massert(count == 10, "count == 10");

	*it = 100;
	massert(*it == 100, "*it == 100");
	massert(*it1 == 100, "*it1 == 100");

	for(auto &i : l){
		i = 0;
	}

	for(auto i : l){
		massert( i == 0 , "list should be all zeros");
	}

	massert(*it == 0, "*it == 0");
	massert(*it1 == 0 , "*it1 == 0");

	cout << "ITERATOR TEST PASS" << endl;
}
void big_3_test(){
	cout << "big 3 test start"<< endl;
	Linkedlist l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	massert(l.size() == 3, "l's size should be 3");
	Linkedlist r, m;
	r = m = l;
	massert(m.size() == 3, "m's size should be 3");
	massert(r.size() == 3, "r's size should be 3");
	l.push_back(4);
	massert(l.size() == 4, "l.size() = 4, l = [1,2,3,4]");
	massert(m.size() == 3, "m.size() = 3, m = [1,2,3]");
	massert(r.size() == 3, "r.size() = 3, r = [1,2,3]");

	Linkedlist k(r);
	massert(k.size() == 3, "k.size() = 3, k = [1,2,3]");
	massert(k.front() == 1, "k.front() = 1, k = [1,2,3]");
	massert(k.back() == 3, "k.back() = 3, k = [1,2,3]");

	k.push_back(4);
	massert(k.size() == 4, "k.size() = 4, k = [1,2,3,4]");
	massert(r.size() == 3, "r.size() = 3, r = [1,2,3]");
	cout << "BIG 3 TEST PASS!!" << endl;
}

