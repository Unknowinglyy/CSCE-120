#ifndef RENTALCOMPANY_H
#define RENTALCOMPANY_H
#include <string>
#include <vector>
#include "Car.h"
class RentalCompany{
    std::string name;
    std::vector<Car> Fleet;
    public:
        RentalCompany::RentalCompany(std::string name){
            name(name);
        }
        RentalCompany::getName(){
            return name;
        }
        RentalCompany::addCar(Car newCar){
            Fleet.push_back(newCar);
        }
};

#endif