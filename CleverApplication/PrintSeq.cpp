#include <iostream>
#include <list>
#include <memory>
#include <vector>

using namespace std;

template<class T, template<class U, class = allocator<U> > class Seq>
void printSeq(Seq<T>& seq)
{
	for (typename Seq<T>::iterator b = seq.begin(); b != seq.end();)
	{
		cout << *b++ << endl;
	}
}