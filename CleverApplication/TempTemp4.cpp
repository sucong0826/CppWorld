#include <iostream>
#include <list>
#include <memory>
#include <vector>

using namespace std;

template<class T, template<class U, class = allocator<U> > class Seq>
class Container
{
	Seq<T> seq;

public:
	void push_back(const T& t) { seq.push_back(t); }
	typename Seq<T>::iterator begin() { return seq.begin(); }
	typename Seq<T>::iterator end() { return seq.end(); }
};

//int main()
//{
//	// Use a vector
//	Container<int, vector> vContainer;
//	vContainer.push_back(1);
//	vContainer.push_back(2);
//
//	for (vector<int>::iterator p = vContainer.begin(); p != vContainer.end(); ++p)
//	{
//		cout << *p << endl;
//	}
//
//	// Use a list
//	Container<int, list> lContainer;
//	lContainer.push_back(3);
//	lContainer.push_back(4);
//
//	for (list<int>::iterator p2 = lContainer.begin(); p2 != lContainer.end(); ++p2)
//	{
//		cout << *p2 << endl;
//	}
//}