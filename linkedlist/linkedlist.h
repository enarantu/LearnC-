#include <cassert>
#include <cstdlib>

class Linkedlist{
public:
	//Initializes an empty linked list
	Linkedlist();

	//Initializes  a linked list as a copy of an existing list
	Linkedlist(Linkedlist& l);

	//Assignment operator
	Linkedlist& operator=(Linkedlist& l);

	//runs when linked list runs out of scope
	~Linkedlist();

	//push element to back
	void push_back(int data);

	//push element to front
	void push_front(int data);

	//pop element from back
	void pop_back();

	//pop element from front
	void pop_front();

	//gives the front element
	int & front();

	//gives the back element
	int & back();

	//gives the size
	size_t size() const;

	//return true if empty
	bool empty() const;

private:

	struct Node{
		int data;
		Node * next;
		Node * prev;
	};

	Node *first;
	Node *last;
	size_t size_count;

public:

	class Iterator{
	public:
		//makes iterator to nullptr
		Iterator();
		//moves the iterator toward the end by one
		Iterator & operator++();
		//moves the iterator toward the back by one
		Iterator & operator--();
		//sets the iterator to given iterator
		Iterator & operator=(Iterator it);
		//returns true if 2 iterators are pointing to same Node
		bool operator==(Iterator it);
		//returns true if 2 iterators are pointing to differnt Node
		bool operator!=(Iterator it);
		//returns data of the node iterator is pointing to
		int & operator*() const;
	private:
		//the node iterator is pointing to
		Node* ptr;
		//class linked list can access private members of class Iterator
		friend class Linkedlist;
		//constructs iterator from a Node pointer
		Iterator(Node * in_ptr);
	};
	//return an iterator pointing to first node with data = x, if it doesn't exist return past the end iterator
	Iterator search(int x);
	//inserts a node with data x after the node iterator is pointing to
	//iterator is moved to the inserted node
	void insert(Iterator &it, int x);
	//removes a node iterator is pointing to
	//iterator is moved to next node
	void erase(Iterator &it);
	//returns iterator pointing to front
	Iterator begin() const;
	//returns iterator pointing past the end
	Iterator end() const;
};

void bubbleSort(Linkedlist::Iterator s, Linkedlist::Iterator e);

void insertionSort(Linkedlist::Iterator s, Linkedlist::Iterator e);

void selectionSort(Linkedlist::Iterator s, Linkedlist::Iterator e);

void mergeSort(Linkedlist::Iterator s, Linkedlist::Iterator e);

void quickSort(Linkedlist::Iterator s, Linkedlist::Iterator e);

