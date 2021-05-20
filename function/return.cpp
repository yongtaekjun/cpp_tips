#include <iostream>

int return_test ( int a, int b) {
    return a+b;
}

void for_test(int age) {
    for ( int i=0; i < age; i++) {
        // std::cout << "age is " << i << std::endl;
        std::cout << "age is " << i;
    }
}
void nested_for_test(int age) {
    for ( int i=0; i < age; i++) {
        // std::cout << "age is " << i << std::endl;
        std::cout << "age is " << i;
        for (int j=0; j < 10; j++) {
            std::cout << "repeat! " << i;
        }
        int k = 10;
        while ( k > 0 ) {
            std::cout << "while! ";
            k--;
        }

        std::cout << std::endl;
    }
}
void do_test(int age) {
    do  {
        std::cout << "age is " << age << std::endl;
        age = age -1; // age -=; age--;
    } while ( age >= 0);
}
void if_test(int age, bool glass) {
    if ( age > 18 ) {
        std::cout << "You are adult!" << std::endl;
        if (glass) {
            std::cout << "You wear glasses!" << std::endl;
        }
        else {
            std::cout << "You do not wear glasses!" << std::endl;
        }
        
    }
    else {
        std::cout << "You are not adult!" << std::endl;
    }
}
// logic error
void date_test(double dob) {
    if ( ( 2021/05/05 - dob) < 10) {
        std::cout << "You have a gift!" << std::endl;
    }
    else {
        std::cout << "You have no any gifts!" << std::endl;
    }
}

double power(double base, int exp ) {
    double result = 1;
    for ( int i = 0; i < exp; i++ ) {
        result = result * base;
    }

    double result2 = base; // if base 5, exp 3, 1st result2 = 5
    for ( int i = 0; i < exp-1; i++ ) {
        result2 = result2 * base;
    }
    
    return result2;
}



int main() {
    // for_test(15);
    // do_test(15);
    // if_test(15,true);
    // nested_for_test(10);
    // int a = 10, b = 33;
    // std::cout << a << " + " << b << " = " << return_test(a, b) << std::endl;
    // date_test(2000/01/21);
    // date_test(1964/10/22);
    // date_test(1992/11/04);
    std::cout << " base 5, exp 3 = " << power (5,3) << std::endl;

    return 0;
}