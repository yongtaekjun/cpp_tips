#include<iostream>

int main(int args, char **argc)
{
    const int familly_size = 5; // const = not be changed,size = 6;
    int familly_ages[familly_size] = { 21, 32, 56, 58, 82 };
    for ( int i = 0; i < familly_size; i++ ) {
        std::cout << familly_ages[i] << ", " ;
    }
    return 1;
}