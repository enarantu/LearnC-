#include <iostream>
#include <cassert>
#include <algorithm>
#include "linkedlist.h"

using namespace std;

void massert(bool b, const char *c);
void basic_test();
void iterator_test();
void big_3_test();
void search_test();
void tryout();
void search_insert_delete_test();
void sort_test(int type);

int main(){
	basic_test();
	iterator_test();
	big_3_test();
	sort_test(0);
	sort_test(1);
	sort_test(2);
	sort_test(3);
	sort_test(4);
	cout << "\tPASSED ALL TESTS" << endl;
	return 0;
}
void tryout(){
	Linkedlist l;
	for(int i = 9 ; i >= 0 ; i--){
		l.push_back(i);
	}
	for(auto i : l){
		cout << i << " ";
	}
	cout << endl;
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

void search_insert_delete_test(){
	cout << "search insert delete test start" << endl;
	Linkedlist l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	auto it = l.search(2);
	massert(*it == 2,"searching 2; [1,2,3]");
	it = l.search(5);
	massert(it == l.end(), "searchin 5; [1,2,3]");
	it = l.search(1);
	massert(*it == 1, "searching 1; [1,2,3]");
	l.insert(it,5);
	it = l.search(5);
	massert(*it == 5, "searching 5; [1,5,2,3]");
	it = l.search(3);
	massert(*it == 3, "searching 3; [1,5,2,3]");
	l.insert(it,6);
	it = l.search(6);
	massert(*it == 6, "searching 6; [1,5,2,3,6]");
	l.insert(it,4);
	it = l.search(4);
	massert(*it == 4, "searching 4; [1,5,2,3,6,4]");
	
	auto it1 = it;
	while ( it1 != l.begin()){
		--it1;
	}
	massert(*it1 == *l.begin(), "it1 should point to first");

	int count = 0;
	for(auto i : l){
		cout << i << ' ';
		count ++;
	}
	cout << endl;
	massert(count == 6,"total 6 elements should be in the list");

	it = l.search(6);
	massert(*it == 6, "searching 6; [1,5,2,3,6,4]");
	
	for ( auto i : l){
		cout << i << " ";
	}
	cout << endl;

	l.erase(it);

	for(auto i : l){
		cout << i << " ";
	}
	cout << endl;

	it = l.search (4);
	massert(*it == 4, "searching 4, [1,5,2,3,4]");
	it1 = it;
	while ( it1 != l.begin()){
		--it1;
	}
	massert(*it1 == *l.begin(), "it1 should point to first");

	it = l.search(4);
	l.erase(it);

	count = 0;
	for( auto i : l){
		cout << i << " ";
		count ++;
	}
	cout << endl;
	massert(count == 4, "count == 4, [1,5,2,3]");
	
	it = l.begin();
	l.erase(it);

	count = 0;
	for( auto i : l){
		cout << i << " ";
		count ++;
	}
	cout << endl;
	massert(count == 3, "count == 3, [5,2,3]");
	
	it = l.search(3);
	massert(*it == 3, "searching 3 , [5,2,3]");

	it1 = it;
	while(it1 != l.begin()){
		--it1;
	}
	massert(*it1 == *l.begin(), "it1 should point to first");


	cout << "SEARCH INSERT DELETE TEST PASS!!" << endl;
}

void sort_test(int type){
	Linkedlist bad1;
	bad1.push_back(2);
	bad1.push_back(7);
	bad1.push_back(1);
	bad1.push_back(12);
	bad1.push_back(8);
	bad1.push_back(9);
	bad1.push_back(10);
	bad1.push_back(5);
	bad1.push_back(14);
	bad1.push_back(4);
	bad1.push_back(6);
	bad1.push_back(11);
	bad1.push_back(13);
	bad1.push_back(3);
	bad1.push_back(15);
	
	Linkedlist bad2;
	bad2.push_back(15);
	bad2.push_back(14);
	bad2.push_back(13);
	bad2.push_back(12);
	bad2.push_back(11);
	bad2.push_back(10);
	bad2.push_back(9);
	bad2.push_back(8);
	bad2.push_back(7);
	bad2.push_back(6);
	bad2.push_back(5);
	bad2.push_back(4);
	bad2.push_back(3);
	bad2.push_back(2);
	bad2.push_back(1);

	Linkedlist bad3;
	bad3.push_back(2);
	bad3.push_back(9);
	bad3.push_back(7);
	bad3.push_back(8);
	bad3.push_back(1);
	bad3.push_back(5);
	bad3.push_back(3);
	bad3.push_back(14);
	bad3.push_back(10);
	bad3.push_back(12);
	bad3.push_back(13);
	bad3.push_back(15);
	bad3.push_back(4);
	bad3.push_back(6);
	bad3.push_back(11);
	cout << "before sort : " << endl;
	for(auto i : bad1){
		cout << i << " ";
	}
	cout << endl;

	for(auto i : bad2){
		cout << i << " ";
	}
	cout << endl;


	for(auto i : bad3){
		cout << i << " ";
	}
	cout << endl;


	switch(type){
		case 0:{
			cout << "bubble sort" << endl;
			bubbleSort(bad1.begin(),bad1.end());
			bubbleSort(bad2.begin(),bad2.end());
			bubbleSort(bad3.begin(),bad3.end());
			break;
		}
		case 1:{
			cout << "selection sort" << endl;
			selectionSort(bad1.begin(),bad1.end());
			selectionSort(bad2.begin(),bad2.end());
			selectionSort(bad3.begin(),bad3.end());
			break;
		}
		case 2:{
			cout << "insertion sort" << endl;
			insertionSort(bad1.begin(),bad1.end());
			insertionSort(bad2.begin(),bad2.end());
			insertionSort(bad3.begin(),bad3.end());
			break;
		}
		case 3:{
			cout << "merge sort" << endl;
			mergeSort(bad1.begin(),bad1.end());
			mergeSort(bad2.begin(),bad2.end());
			mergeSort(bad3.begin(),bad3.end());
			break;
		}
		case 4:{
			cout << "quick sort" << endl;
			quickSort(bad1.begin(),bad1.end());
			quickSort(bad2.begin(),bad2.end());
			quickSort(bad3.begin(),bad3.end());
			break;
		}
	}


	
	cout << "after sort : " << endl;
	for(auto i : bad1){
		cout << i << " ";
	}
	cout << endl;

	for(auto i : bad2){
		cout << i << " ";
	}
	cout << endl;


	for(auto i : bad3){
		cout << i << " ";
	}
	cout << endl;

}
