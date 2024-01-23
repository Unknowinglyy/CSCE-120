#ifndef CAR_H
#define CAR_H
#include <string>
class Car{
    std::string model;
    float range;
    bool IsElectric;
    public:
        Car::Car(std::string model, float range, bool IsElectric){
            model(model);
            range(range);
            IsElectric(IsElectric);
        }
        Car::getModel(){
            return model;
        }
        Car::getRange(){
            return range;
        }
        Car::getIsElectric(){
            return IsElectric;
        }
};
#endif