

#include <iostream>
#include <string> 

class Animal {
public:
    int foot;
    std::string name;
public:    
    Animal () {
        foot = 2;
        name = "Animal";
    }
    virtual ~Animal () {
        
    }
public :    
    void Eat() {
        std::cout << "[Animal] : Eat" << std::endl;
    }
    void Move() {
        std::cout << "[Animal] : Move" << std::endl;
    }
    virtual void Display() {
        std::cout << "[Animal] : " << name <<" has " << foot << " feet"<< std::endl;
    }
    std::string GetInfo() {
        return "[Animal] : " + name + " has " + std::to_string(foot) + " feet\n";
    }
    int GetAge() {
        return _age;
    }
    void SetAge(int age) {
        _age = age;
    }
private:
    int _age;
};