// test_fileio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <array>
/*--------------------------------------------------------------------------------------
Naming Conven Rule by Yongtaek Jun, 2017-11-25
----------------------------------------------------------------------------------------
0. Follow the team's convention rule or
	0.1 add comments when the code readability is not enough or
	0.2 when you don't understand your code after one month/year
1. 
	1.1 use '_' as delimeter it improves readability when the project is big and complex.
		
		display_message_with_general_rule ();
		display_message_with_special_rule ();

	1.2	use Capital Character & '_' as delimeter it improve readability when the project is small
		
		Display_Message_With_General_Rule ();
		Display_Message_With_Special_Rule ();

	1.3 use Capital Character as delimeter it improve readability when the project is small

		DisplayMessageWithGeneralRule ();
		DisplayMessageWithSpecialRule ();

	which one is best? : answer 1.1 has better readablilty and best typing speed.
	A software maintenance cost is over 80%

2. use postfix '_' for parameter variable, prefix for member variable.
   eg: void display ( string msg_ ); // as a parameter
       display ( _msg ); // display for member variable 
	   display ( msg ); // display for local variable
	   
	   
3. use prefix '_' for class member variable

4. use Capital Word for constant variable

5. use hint prepix the data type only when you cannot guess the variable's type
   eg: n_abcdef  // variable type is number (int, short, unsigned )
       score     // removed "n_" because we can guess the score's type is number
	   s_score   // 's' means it is string type we couldn't expect it is string.
	   name      // we know it is string.
	   
6. use VERB first when declare function name
	eg: display_message ( string msg_ ); // It is good because it is order of English
		message_display ( string msg_ ); // It is not good

7. use 

*/

void test();
void test2();

template <typename T> char * as_bytes(T& i) {
	return reinterpret_cast<char *> (&i);
}

int main()
{
	test2();
    return 0;
}

// buffer for std::ostream implemented by std::array
template<  std::size_t tSIZE, class CharT = char >
class arrayed_stream_buffer : public std::basic_streambuf< CharT >
{
public:
	using base = std::basic_streambuf < CharT >;
	using char_type = typename base::char_type;
	// value-initialize _buffer to all zeroes
	arrayed_stream_buffer() : _buffer{} 
	{
		// put area pointers to work with '_buffer'
		// base::setp( _buffer.begin(), _buffer.end() ); // does not work in VS2017
		base::setp(&_buffer[0], &_buffer[_buffer.size() - 1]); // set std::basic_streambuf
	}

	void print_buffer() {
		for (const auto& i : _buffer) {
			if (i == 0) {
				std::cout << "N"; // null value to 'N'
				continue;
			}
			std::cout << i;
		}
		std::cout << "\n";
	}

//private:
	std::array<  char_type, tSIZE> _buffer;
};
class CMessage {
private:
	arrayed_stream_buffer< 512, char > _msg_streambuf;
	std::ostream _msg_stream{ &_msg_streambuf };
	unsigned int _body_size = 0;
	const unsigned int _head_size = sizeof(int);

public:
	CMessage() : _msg_stream{ &_msg_streambuf } {
		initialize();
	}
	CMessage(std::string& msg_ ) : _msg_stream{ &_msg_streambuf } {
		initialize();
		append( msg_ );
	}
	CMessage(char * msg_) : _msg_stream{ &_msg_streambuf } {
		initialize();
		append(msg_);
	}
	void initialize() {
		_body_size = 0;
		_msg_stream.clear();
	}
	// head has int value for body_length
	void encode_head() {
		char t[4]; // without null
		strncpy_s( t, reinterpret_cast<char *>(&_body_size), sizeof(_body_size));
		for (int i = 0; i < 4; i++ ) _msg_streambuf._buffer[i] = t[i];
//		_msg_streambuf.sputn(0, 4);

	}
	// read _msg_streambuf[0,4] which has int value for body_length
	unsigned int decode_head() {
		_body_size = (int)(_msg_streambuf.sgetn ( 0,4 ));
		return _body_size;
	}
	char * get_body() {
		return &(_msg_streambuf._buffer[ _head_size]);
	}
	std::ostream & operator << (char * msg_) {
		return append (msg_ );
	}
	std::ostream & operator << (std::string & msg_) {
		return append( msg_.c_str() );
	}
	std::ostream & operator = ( char * msg_) {
		initialize();
		return append(msg_);
	}
	std::ostream & operator = (std::string & msg_) {
		initialize();
		return append ( msg_.c_str() );
	}
	std::ostream & append(const char * msg_) {
		if (sizeof(msg_) + _body_size + _head_size > 512) {
			std::cout << "too big old size = " << _body_size << "\n";
			return _msg_stream;
		}
		_body_size += strnlen_s ( msg_,512);
		encode_head();
		return _msg_stream << msg_;
	}
	std::ostream & append ( std::string & msg_ ) {
		return append ( msg_.c_str() );
	}
	void show_property() {
		_msg_streambuf.print_buffer();
		//std::cout << "head size: " << _head_size << std::endl;
		//std::cout << "body size: " << _body_size << std::endl;
		//std::cout << "body : " << get_body() << std::endl;
	}
};


void test3()
{

	char str[1024];
	std::fgets(str, 1024, stdin);
	std::string line(str);
}

void test2()
{
	CMessage msg("001:1234567890");
	//msg.show_property();

	msg << "002:1234567890";
	//msg.show_property();

	msg << "003:1234567890";
	msg.show_property();

	msg.initialize();
	msg.show_property();

	msg << "004:1234567890";
	//msg.show_property();

	msg << "005:1234567890";
	//msg.show_property();

}

void test()
{
	std::ifstream tt;

	std::ifstream	ifs("source", std::ios_base::binary); // stream mode is binary
	std::ofstream	ofs("target", std::ios_base::binary); // stream mode is binary
	std::vector<int> v;
	for (int i; ifs.read(as_bytes(i), sizeof(i));) // read bytes from binary file
		v.push_back(i);
	// ... do something with v ...
	for (std::vector<int>::iterator j = v.begin(); j == v.end(); j++) // write bytes to binary file:
		ofs.write( as_bytes( *j ), sizeof( *j)); // why *i ? i is iterator (=point) not int
	
	// with C++14, VS 17 have not support this yet.
	//for ( auto j : v) // write bytes to binary file:
	//	ofs.write(as_bytes(*j), sizeof(*j)); // why *i ? i is iterator (=point) not int
}

