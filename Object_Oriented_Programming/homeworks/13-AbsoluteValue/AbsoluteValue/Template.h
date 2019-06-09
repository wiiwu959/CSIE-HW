#pragma once
#ifndef TEMPLATE_H_INCLUDED
#define TEMPLATE_H_INCLUDED
#include <cmath>
// use ifndef and pragma once to provide define more than one time.


// use template to process int, float and double situations.
template<class T>
T absoluteValue(T& v, T& u)
{
	return abs(v - u);
}

// special process for char.
int absoluteValue(char c1, char c2)
{
	return (int)abs(c1 - c2);
}
#endif