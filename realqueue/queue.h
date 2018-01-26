class Queue{

	struct Node{
		int data;
		Node* next;
	};

	Node* head;
	Node* tail;
public:
	Queue();
	void push(int n);
	void pop();
	bool empty();
	int top();
};