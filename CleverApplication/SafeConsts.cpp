#include "SafeConsts.h"
#include <iostream>

using namespace std;

const int i = 100;
const int j = i + 10;
long address = (long) &j;
char buf[j + 10];

int inner_main()
{
	cout << "type a character & CR:";
	const char c = cin.get();
	const char c2 = c + 'a';
	cout << c2;

	return 0;
}