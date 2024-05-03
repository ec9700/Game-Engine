//
// Created by subto on 4/16/2024.
//

#ifndef GAMELIB_VECTORMETHODS_H
#define GAMELIB_VECTORMETHODS_H


#include <vector>
#include "algorithm"

class VectorMethods {
private:
    VectorMethods();
public:
    template<typename T>
    static int getIndexOf(std::vector<T> vector,T object);

    template<typename T>
    static void removeObject(std::vector<T> &vector, T object);

    template<typename T>
    static void removeObjectAt(std::vector<T>& vector, int index);
};

template<typename T>
void VectorMethods::removeObjectAt(std::vector<T>& vector, int index) {
    vector.erase(vector.begin()+index);
}

template<typename T>
int VectorMethods::getIndexOf(std::vector<T> vector, T object) {
    //Replace auto with actual class type
    auto iterator = std::find(vector.begin(),vector.end(),object);
    if(iterator >= vector.end()) return -1;
    return iterator-vector.begin();
}

template<typename T>
void VectorMethods::removeObject(std::vector<T>& vector, T object) {
    return removeObjectAt(vector,getIndexOf(vector, object));
}




#endif //GAMELIB_VECTORMETHODS_H
