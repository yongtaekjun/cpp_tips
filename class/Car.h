
#include <iostream>
#include <string> 

class Car {
public :
    // Car (std::string maker, std::string model, std::string year, uint32_t price) :
    //     _maker (maker), _model (model), _year(year), _price(price)
    Car (std::string maker, std::string model, std::string year, uint32_t price) 
    {
        _maker = maker;
        _model = model;
        _year = year;
        _price = price;
    }
    virtual void Display() {
        std::cout << _maker << "\t" << _model <<"\t" << _year <<"\t$" << _price<< std::endl;
    }
    std::string GetMaker() { return _maker; }
    std::string GetModel() { return _model; }
    std::string GetYear() { return _year; }
    uint32_t GetPrice() { return _price; }

private :
    std::string _maker = "";
    std::string _model = "";
    std::string _year = "";
    uint32_t _price = 0;
    // for explan the linked list.
    Car* next = nullptr;
    Car* prev = nullptr;
};

