#include<iostream>
#include<cassert>

using namespace std;

int factorial(int x)
{
    assert(x >= 0);
    if(x == 0)    return 1;
    return(factorial(x - 1) * x); // 5 * 4* 3* 2 * 1
}
int factorial2(int x)
{
    assert(x >= 0);
    int result = 1;
    for ( int i = 1; i <= x; i++ ) {
        result *= i;
    }
    return result; // 5 * 4* 3* 2 * 1
}

int main(int args, char **argc)
{
    int temp = 5;
    cout << "Factorials" << endl;
    cout << "Chapter 3: Recursion" << endl << endl;
    cout << "The Recursion factorial of " << temp << ": ";
    cout << factorial(temp);
    cout << "for loop factorial of " << temp << ": ";
    cout << factorial2(temp);
    return 1;
}