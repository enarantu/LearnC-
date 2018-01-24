README
    Steps:
        0) install valgrind first using this command : sudo apt install valgrind
        1) create stack.cpp file (do not create/modify any file except stack.cpp)
        2) add the starter code:
        3) "make help" will display useful info
    Requirements:
    It is not possible to implement this without the use of heap. You can try though.
    The "new" key word allocates memory on the heap. Make sure you deallocate the allocated
    space using "delete" keyword. For example,
        int * a = new int; will allocate an integer on the heap
        you can access it through pointer "a".
        delete a; will deallocate the memory on heap.
        if you don't do it, that would be a memory leak.
    If you allocate a memory on heap with "new", you are responsible for its deallocation.
    OS will deallocate it after you program finished executing, but during the execution everything except you can deallocate.
    If you allocate memory on stack, you don't have to deallocate it. When the variable run out of scope, it will be automatically
    deallocated.
        for example, int a = 5; will allocate memory on stack and put 5 in it.
        It will be deallocated automatically when it goes out of scope.
    "valgrind" checks if the program has a memory leak. Memory leak is a fancy
    way of saying that when your program finishes executing there is unallocated
    memory on the heap. 
    
Stack::Stack(){
    //IMPLEMENT
}
bool Stack::empty(){
    //IMPLEMENT
}
int Stack::top(){
    //IMPLEMENT
}
void Stack::pop(){
    //IMPLEMENT
}
void Stack::push(int x){
    //IMPLEMENT
}
       
