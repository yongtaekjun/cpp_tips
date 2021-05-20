#include <iostream>

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

int main() {
    for_test(15);
    // nested_for_test(10);
    return 0;
}