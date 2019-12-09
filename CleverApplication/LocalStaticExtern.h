#pragma once
#include <iostream>

class LocalStaticExtern
{
};

// an extern method can be accessed in another transfering unit.
// that is, can be called in other files when header file is included
extern void outer_test_func();

// an static method can't be accessed in another transtering unit.
// that is, can't be called in other files when header file is included
static void inner_test_func();

