#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include "array.h"

using namespace std;

void basic_test();
void sort_test();
int main(){
	basic_test();
	sort_test();
	return 0;
}

void basic_test(){
	cout << "BASIC TEST START" << endl;
	cArray a(20);
	for(int i = 0 ; i < 20 ; i++){
		a[19-i] = i;
	}

	sort(a.begin(),a.end());

	for(int i = 0 ; i < 20 ; i++){
		assert(a[i] == i);
	}

	int num = 19;
	for(auto it = a.end() - 1; it >= a.begin() ; --it){
		assert(num-- == *it);
	}

	cout << "BASIC TEST END" << endl;
}
void sort_test(){
	cout << "SORT TEST START" << endl;
	for(int j = 0 ; j < 100; j++){
		cArray a(25);
		for(int i = 0 ; i < 25 ; i++){
			a[i] = rand() % 25;
		}
		cArray merge(a);
		cArray quick(a);

		mergesort(merge.begin(),merge.end());
		quicksort(quick.begin(),quick.end());
		sort(a.begin(),a.end());

		for(int i = 0 ; i < 25 ; i++){
			assert(a[i] == merge[i]);
			assert(a[i] == quick[i]);
		}

	}
	cout << "SORT TEST PASS" << endl;
}