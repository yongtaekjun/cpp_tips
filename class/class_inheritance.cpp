#pragma once

#include <vector>
#include <iostream>
#include <iomanip>
#include <memory>
#include "Dog.h"
#include "Cat.h"

void dog_test() {
    Dog tom;
    tom.name = "Tom";
    tom.foot = 4;
    tom.Display();

}
void cat_test() {
    Cat nayong;
    nayong.name = "Nayong";
    nayong.foot = 3;
    // nayong.age = 1;

    nayong.Display();
}
void animal_test() {
    Animal mal;
    mal.name = "Mal";
    mal.SetAge(5);
    mal.Display();
}

int main() {

    cat_test();
    // dog_test();
    // animal_test();

    return 0;
}