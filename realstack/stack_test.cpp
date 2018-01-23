#include <iostream>
#include <cassert>
#include "stack.h"

using namespace std;

void basic_tests();
int main(){
    basic_tests();
    return 0;
}
void basic_tests(){
    cout << "BASIC TESTS" << endl;
    Stack s;
    s.push(1);
    assert(s.top() == 1);
    s.push(2);
    assert(s.top() == 2);
    assert(!s.empty());
    s.pop();
    assert(s.top() == 1);
    assert(!s.empty());
    s.pop();
    assert(s.empty());
    for(int i = 1 ; i < 10 ; i++){
        s.push(i);
        assert(s.top() == i);
    }
    for(int i = 1 ; i < 10 ; i++){
        assert(!s.empty());
        assert(s.top() == 10 - i);
        s.pop();
    }
    assert(s.empty());

    cout << "PASSED ALL BASIC TESTS" << endl;
}