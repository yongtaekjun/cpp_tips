// test_binaryfile.cpp : Defines the entry point for the console application.

// namming convention rule
// prifix  'n_' for all number .... example: int n_score, n_average except number for temperary or index ex: int i = 0;
// prifix  'fr_' for file for read  .... example: ifstream fr_phonebook, fr_score
// prifix  'fw_' for file for write .... example: ofstream fw_phonebook, fw_score


// postfix 's'  for every pulural noun .... example: vector<int> n_scores(10), n_averages(4)

#include "stdafx.h"

#include "stdio.h"

#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <algorithm>
#include <locale>

template <typename T> char * as_bytes (T& i) {
	return reinterpret_cast<char *> (&i);
}

using namespace std;
void test();
void test_split();
void split(string& _text, string& _separators, list<string>& _words);
void test_tolower();

int main()
{
	test_split();
    return 0;
}
/**
 * @param _text: it have string collections like mixed with number and words with seperators: blanc , tab, new line 
 * @param _separators: it seperate word to word
 * @param _words: It contains word each in list or vector container 
 * @examle: if _text has "We all love piece, and freedom."
 *         _words[0] has 'We'
 *         _words[1] has 'all'
 *         _words[2] has 'love' ...

*/
void split(string& _text, string& _separators, list<string>& _words)
{
	int n = _text.length();
	int start, stop;

	start = _text.find_first_not_of(_separators);
	while ((start >= 0) && (start < n)) {
		stop = _text.find_first_of(_separators, start);
		if ((stop < 0) || (stop > n)) stop = n;
		_words.push_back(_text.substr(start, stop - start));
		start = _text.find_first_not_of(_separators, stop + 1);
	}
}

// Bad Locale Exception throwed .... not ready.
void test_tolower() {
	// #include <locale>
	std::locale::global(std::locale("en_US.utf8")); // Bad Locale Exception throwed
	std::wcout.imbue(std::locale());
	std::wcout << "In US English UTF-8 locale:\n";
	auto& f = std::use_facet<std::ctype<wchar_t>>(std::locale());
	std::wstring str = L"HELLo, wORLD!";
	std::wcout << "Lowercase form of the string '" << str << "' is ";
	f.tolower(&str[0], &str[0] + str.size());
	std::wcout << "'" << str << "'\n";
}
void test_split()
{
	string text;
	string seperators = " -\n\t,";
	list<string> words;

	getline( cin , text); // read data from console by line.
	split( text, seperators, words);
	cout << text << endl;
	
	// for test
	for (string word : words) cout << word << ", ";
	cout << endl;

	// for test
	bool b_name_found = false;
	bool b_is_found = false;
	for (string word : words) {
		if ( b_name_found && b_is_found ) {
			cout << "name is " << word;
			break;
		}
		if ((word) == ("name")) {
			b_name_found = true;
			continue;
		}
		if ( word == "is") {
			b_is_found = true;
		}
	} 
	cout << endl;

	// for test by reverse order
	for (list<string>::reverse_iterator i = words.rbegin(); i != words.rend(); i++) cout << *i << ",    ";
	cout << endl;
}

void test()
{
	vector<int> v1 = { 1,2,3,5,66,77,88,99,111,112,113,114 };
	vector<int> v2;
	std::string st_origin_filename = "origin_num.txt";
	std::string st_reverse_filename = "reverse_num.txt";

	ofstream fw_int;
	// for write vector numbers to file in original order
	fw_int.open (st_origin_filename, ios_base::binary); // stream mode is binary
	for (int i : v1) // write bytes to binary file
		fw_int.write ( as_bytes(i), sizeof(i));
	fw_int.close();

	// for write vector numbers to file in reverse order
	fw_int.open(st_reverse_filename, ios_base::binary); // stream mode is binary
	for ( auto i = v1.rbegin(); i != v1.rend() ; i++) // read bytes from binary file
		fw_int.write(as_bytes( *i ), sizeof(*i));
	fw_int.close();

	ifstream fr_int;

	// for read numbers from original file to vector numbers and display
	fr_int.open (st_origin_filename, ios_base::binary); 
	for (int i; fr_int.read(as_bytes(i), sizeof(i));) 
		v2.emplace_back(i);
	fr_int.close();

	// Display vectors 
	for (unsigned int i = 0; i < v2.size(); i++)
		std::cout << v2[i] << ( (i < (v2.size() -1)? ", ":""));

	std::cout << endl << "Display Reverse file " << endl;
	v2.clear();
	// for read numbers from revered file to vector numbers and display
	fr_int.open(st_reverse_filename, ios_base::binary);
	for (int i; fr_int.read(as_bytes(i), sizeof(i));) 
		v2.emplace_back(i);
	fr_int.close();

	for (unsigned int i = 0; i < v2.size(); i++) // read bytes from binary file
		std::cout << v2[i] << ((i < (v2.size() - 1) ? ", " : ""));
	std::cout << endl << "Program terminated ....... " << endl;

}
