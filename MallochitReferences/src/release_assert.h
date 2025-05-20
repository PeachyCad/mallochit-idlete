#include <iostream>
using namespace std;

#pragma once
#define release_assert(condition) if(!(condition)) { \
cerr << "Assertion failed: " #condition ", file " <<  __FILE__ << ", line"  << __LINE__ << endl; \
abort(); \
}