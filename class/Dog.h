
#include "Animal.h"

class Dog : public Animal {
public :
    Dog () {
    }
    virtual void Display() {
        std::cout << "[Dog] : " << name <<" has " << foot << " feet"<< std::endl;
    }
};
