#include <iostream>

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
    std::cout << " base 5, exp 3 = " << power (5,3) << std::endl;
    return 0;
}