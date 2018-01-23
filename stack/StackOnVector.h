#include <vector>

class StackOnVector{
private:
    std::vector<int> st;
public:
    StackOnVector();
    StackOnVector(std::vector<int> v);
    bool empty();
    int top();
    void pop();
    void push(int x);
};