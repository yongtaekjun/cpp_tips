// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>
#include "Dog.h"
#include "Cat.h"
  
using namespace std;
  
int main()
{
    vector<Cat> cats;
  
    for (int i = 1; i <= 10; i++) {
        Cat a_cat;
        a_cat.name = "Cat" + std::to_string(i);
        cats.push_back(a_cat);
    }
  
    cout << "Output of begin and end: ";
    for (auto i = cats.begin(); i != cats.end(); ++i)
        cout << i->GetInfo() << " ";
  
    // cout << "\nOutput of cbegin and cend: ";
    // for (auto i = cats.cbegin(); i != cats.cend(); ++i)
    //     cout << i-> << " ";
  
    // cout << "\nOutput of rbegin and rend: ";
    // for (auto ir = cats.rbegin(); ir != cats.rend(); ++ir)
    //     cout << *ir << " ";
  
    // cout << "\nOutput of crbegin and crend : ";
    // for (auto ir = cats.crbegin(); ir != cats.crend(); ++ir)
    //     cout << *ir << " ";
  
    cout << std::endl << cats.size() << " ";
  
    return 0;
}