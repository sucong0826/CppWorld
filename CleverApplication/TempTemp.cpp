#include <cstddef>
#include <iostream>

using namespace std;

template<class T>
class Array
{
	enum { INIT = 10 };
	T* data;
	size_t capacity;
	size_t count;

public:
	Array()
	{
		count = 0;
		data = new T[capacity = INIT];
	}

	~Array() { delete[] data; }

	void push_back(const T& t)
	{
		if (capacity == count)
		{
			// to enlarge the array capacity with 2-times
			size_t new_cap = capacity * 2;
			T* new_data = new T[new_cap];
			for (int i = 0; i < count; ++i)
			{
				new_data[i] = data[i];
			}

			// release origin array
			delete[] data;
			data = new_data;
			capacity = new_cap;
		}
		data[count++] = t;
	}

	void pop_back()
	{
		if (count > 0) count--;
	}

	T* begin() { return data; }
	T* end() { return data + count; }
};

template<class T, template<class> class Seq> 
class Container
{
	Seq<T> seq;

public:
	void append(const T& t) { seq.push_back(t); }
	T* begin() { return seq.begin(); }
	T* end() { return seq.end(); }	
	// std::string get_des() { return seq.get_des(); }
};

template<typename T> 
class Temp
{
public:
	template<class X> Temp(const Temp<X>&);
	template<class X> Temp(const Temp<T>&);
};

//int main()
//{
//	Container<int, Array> container;
//	container.append(1);
//	container.append(2);
//
//	int* p = container.begin();
//	while (p != container.end())
//	{
//		cout << *p++ << endl;
//	}
//
//	// container.get_des(); // no compile error but have runtime error
//}