#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <memory>

#include "Car.h"

// 1. make car data struct or class.
// class Car {
    // string maker
    // string model
    // string year
    // uint32_t cost
// }
// 2. make car_list using vector.
// vector<Car> car_list;

// 3. insert several car objects to the car_list
// car_list.push_back(new Car("Hyundai","","", 23000));

// 4. display car_list.
// for ( int i = 0; i < car_list.size(); i++ ) {
//  cout << car_list[i].Display() << endl;
// }

// 5. display car list with condition
// - maker == "Ford".
// - year == "2021".

class Cars {
public:
    Cars() {
       make_sample_data(); 
    }
    void make_sample_data() {

        _car_list.emplace_back(Car("Hyundai","Elantra","2019",23000));
        _car_list.emplace_back(Car("Hyundai","Sonata","2020",28000));
        _car_list.emplace_back(Car("Honda","Civic","2019",22000));
        _car_list.emplace_back(Car("Honda","Accord","2019",32000));
        _car_list.emplace_back(Car("Toyota","Corolla","2019",21000));
        _car_list.emplace_back(Car("Toyota","RAV4","2019",25000));
    }
    void display_cars_by_maker(std::string maker) {

        // for ( int i = 0; i < _car_list.size(); i++ ) {
        // if ( car_list[i].GetMaker() == maker) {
        //         _car_list[i].Display();
        //     }
        // }

        for ( std::vector<Car>::iterator pCar = _car_list.begin(); pCar != _car_list.end(); pCar++ ) {
            if ( pCar->GetMaker() == maker) {
                pCar->Display();
            }
        }
    }
    void display_cars_greater_price(uint32_t price) {

        for ( int i = 0; i < _car_list.size(); i++ ) {
            if ( _car_list[i].GetPrice() >= price) {
                _car_list[i].Display();
            }
        }

        // OR
        // for ( std::vector<Car>::iterator pCar = _car_list.begin(); pCar != _car_list.end(); pCar++ ) {
        //     if ( pCar->GetPrice() >= price) {
        //         pCar->Display();
        //     }
        // }
    }
    void display_cars() {

        for ( int i = 0; i < _car_list.size(); i++ ) {
            _car_list[i].Display();
        }

        // or test below
        
        // for ( std::vector<Car>::iterator pCar = _car_list.begin(); pCar != _car_list.end(); pCar++ ) {
        //     pCar->Display();
        // }
    }
private :
    std::vector<Car> _car_list;
};
