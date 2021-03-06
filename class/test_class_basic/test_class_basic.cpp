// test_class_basic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


class animal {
private: 
	std::string type = "";
	std::string name = "";
	short	length;
	short	leg;

public:
	animal();
	animal(string st_type, string st_name, short n_length = 0, short n_leg = 0);
	std::string get_type() { return type; };
	std::string get_name() { return name; };
	short get_length() { return length; };
	short get_leg() { return leg; };

	void set_type(string st_type) { type = st_type; };
	void set_name(string st_name) { name = st_name; };
	void set_length(short n_length) { length = n_length; };
	void set_leg(short n_leg) { leg = n_leg; };
	void speak() { cout << "Animal Speaks"; };
	void show() { std::cout << endl << "type: " + type << ", name: " << name << ", length: " << length << ", leg: " << leg << endl; };
private:
};
animal::animal() {
	type = "animal";
	name = "name";
	length = 0;
	leg = 0;
}
//animal::animal(string st_type, string st_name, short n_length = 0, short n_leg = 0) {
//	type = st_type;
//	name = st_name;
//	length = n_length;
//	leg = n_leg;
//}
class dog : public animal {
public:
	dog();
	void	speak() { cout << get_name() << " speaks Wal-Wal-Wal" << endl; };
	void	run() { cout << "dog run"; };
//	void	show()
};
dog::dog() {
	//animal("dog", "", 3, 4);
	set_type("dog");
	set_length(3);
	set_leg(4);
};
class cat : public animal {
public:
	cat();
	void	speak() { cout << get_name() << " speaks Yaoooooooong-yaong" << endl << endl; };
	void	run() { cout << "cat run"; };
	//	void	show()
};
cat::cat() {
//	animal("cat", "", 3, 4);
		set_type("cat");
		set_length(3);
		set_leg(4);
};

int main()
{
	dog	husky;
	husky.set_name("Jack");
	husky.set_length(3);
	husky.set_leg(4);
	husky.show();
	husky.speak();

	cat savina;
	savina.set_name ("Suzi");
	savina.set_length (1);
	savina.set_leg(4);
	savina.show();
	savina.speak();

	return 0;
}


