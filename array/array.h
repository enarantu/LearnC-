#include<iterator>

class cArray{
public:
	cArray(int size);
	~cArray();
	cArray(cArray& in_arr);
	int & operator[](int index);
	int & front();
	int & back();
	int size();
private:
	int * arr;
	int sz;
public:
	class Iterator : public std::iterator<std::random_access_iterator_tag,int>{
	public:
		using difference_type = typename std::iterator<std::random_access_iterator_tag, int>::difference_type;
		//makes iterator to nullptr
		Iterator();
		Iterator & operator++();
		Iterator & operator--();
		Iterator & operator=(Iterator it);
		Iterator operator+(difference_type n);
		Iterator operator-(difference_type n);
		difference_type operator-(Iterator it);
		bool operator<(Iterator it);
		bool operator>(Iterator it);
		bool operator>=(Iterator it);
		bool operator<=(Iterator it);
		bool operator==(Iterator it);
		bool operator!=(Iterator it);
		int & operator*();
	private:
		int* ptr;
		friend class cArray;
		Iterator(int * in_ptr);
	};
	Iterator begin();
	Iterator end();
};

void mergesort(cArray::Iterator s, cArray::Iterator e);
void quicksort(cArray::Iterator s, cArray::Iterator e);