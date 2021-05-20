#include "stdafx.h"

#include <set>
#include <iostream>
#include <sstream>
#include <iostream>
#include <iomanip>

//#include <stdio>
// Set: will not allow dupliacted value(key); if you want use multi_set
//      value is key; if you want key and value pair, use map
//      it insert the value by order. Thus, it is an ordered container.

void test_setw()
{
	std::set<int>	numbers;
	//	numbers.insert ( std::initialize_list { 3,5,17,7,7,7,8,9,10,1,2 });
	numbers.insert({ 3,5,17,7,7,7,8,9,10,1,2 });
	for (int i : numbers) {
		std::cout << std::setw(4) << i;
	}
	int input = 5678;
	std::cout << "Left: " << std::left << input << "\n";
	std::cout << "Right: " << std::right << input << "\n";
	std::cout << "Fill in space: " << std::setfill('*') << input << "\n";

}
