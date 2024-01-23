#include <stdexcept>
void explode(unsigned int*& array, size_t& size){
    if(size == 0){
        throw std::invalid_argument("Array can't have size 0");
    }
    size_t newSize = size;
    for(unsigned int i = 0; i < size; i++){
        if(array[i] == 0){
            newSize--;
        }
        if(array[i] >= 1){
            newSize+= (array[i]-1);
        }
    }
    if(newSize == size){
        return;
    }
    unsigned int* newArray = new unsigned int[newSize];
    for(unsigned int i = 0; i < size; i++){
        if(array[i] != 0){
            if(array[i] == 1){
                newArray[i] = array[i];
            }
            else if(array[i] > 1){
                unsigned int index = i;
                for(unsigned int j = i; j < array[i]; j++){
                    newArray[j] = array[i];
                }
            }
        }
    }
    delete array;
    array = nullptr;
    array = newArray;
}