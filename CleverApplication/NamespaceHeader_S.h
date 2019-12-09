#pragma once

namespace NamespaceHeader
{
	// if x is an extern var, must define it globally before using it.
	// otherwise, compiler will report an error.
	// for example:
	// define it in the 'CleverApplication.cpp'
	// <code>
	//		using namespace NamespaceHeader;
	//		(extern) int NamespaceHeader::x = 1;
	//		(extern) int NamespaceHeader::y = 2;
	// </code>
	// Then we can use NamespaceHeader::x in any funtions.
	extern int x;
	void f();
}