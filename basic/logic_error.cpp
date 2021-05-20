#include <iostream>

// logic error ^^ what's wrong?
// ther are no any syntax error... but..
void date_test(double dob) {
    if ( ( 2021/05/05 - dob) < 10) {
        std::cout << "You have a gift!" << std::endl;
    }
    else {
        std::cout << "You have no any gifts!" << std::endl;
    }
}

int main() {
    date_test(2000/01/21);
    date_test(1964/12/22);
    date_test(1992/11/04);
    return 0;
}