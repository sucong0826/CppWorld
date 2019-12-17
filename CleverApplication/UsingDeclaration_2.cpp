#include "UsingDeclaration.h"

namespace Q
{
	// using U::f;
	// using V::g;

	// if here we define V::f and U::f, but call f() in m(), IDE will report an error.
	// because f() has been defined multiple times.
	// using V::f;
}

void m()
{
	using namespace Q;
	// f();
	// g();
}