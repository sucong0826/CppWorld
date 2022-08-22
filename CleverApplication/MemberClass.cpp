#include <iostream>
#include <typeinfo>

using namespace std;

template<class T> class Outer	// 外部 类模板
{
public:
	template<class R> class Inner // 类内的成员类模板
	{
	public:
		void f();
	};
};

template<class T> template<class R>
void Outer<T>::Inner<R>::f()
{
	cout << "Outer == " << typeid(T).name() << endl;
	cout << "Inner == " << typeid(R).name() << endl;
	cout << "Full Inner == " << typeid(*this).name() << endl;
}