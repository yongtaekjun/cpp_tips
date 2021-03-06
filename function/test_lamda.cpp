// test_lamda.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <list>
#include <array>

using namespace std;

int main()
{
	// f1 is lamda function
	auto f1 = [](int x, int y) {
		return x + y;
	};
	cout << "f1(20,30) is " << f1(20, 30) << endl;

	// f2 is variable ... it is not function
	auto f2 = [](int x, int y) {
		return x + y;
	} (30, 40);
	cout << "f2 is " << f2 << endl; // result will be 70;

	// it is good for find_if
	list<int> numbers = {3,4,55,67,89,20,112,3456,444 };
	const list<int>::const_iterator result =
		find_if(numbers.begin(), numbers.end(), [&](int x) {return (x % 5) == 0; });
	cout << "result is " << *result << endl;

	return 0;
}
