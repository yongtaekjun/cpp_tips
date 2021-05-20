
#include "Animal.h"

class Cat : public Animal {
public :
    Cat () {
    }
    virtual void Display() {
        std::cout << "[Cat] : " << name <<" has " << foot << " feet"<< std::endl;
    }
    std::string GetInfo() {
        return "[Cat] : " + name + " has " + std::to_string(foot) + " feet\n";
    }
};