// test_buffer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
// it read console data until meet new line
// but it is slow
void test_getline() {
	string s;
	getline(cin, s);
}
// much faster than getline()
void test_gets() {
	char buffer[1024];
	fgets(buffer, 1024, stdin);
	string line(buffer);
}

void test_tolower() {

	std::string data = "Abc";
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	cout << data << endl;
}
int main()
{
	test_tolower();
    return 0;
}

