#include <iostream>

void do_while_test(int age) {
    do  {
        std::cout << "age is " << age << std::endl;
        age--;
    } while ( age >= 0);
}

int main() {
    do_while_test(15);
    return 0;
}