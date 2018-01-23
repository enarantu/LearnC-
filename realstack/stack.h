#include <vector>
//DO NOT MODIFY THIS FILE
class Stack{
    struct  Node{
        int data;
        Node * next;
    };
    Node * head;
public:
    Stack();
    bool empty();
    int top();
    void pop();
    void push(int x);
};