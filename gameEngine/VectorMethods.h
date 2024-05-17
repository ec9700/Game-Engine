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
    /**
     * Gets the index of @p object of type @p T in @p vector
     * @tparam T Type of @p object
     * @param vector @ref std::vector to check in
     * @param object @p T Object to get index of
     * @return @ref int Index of @p object, returning -1 on failure
     */
    template<typename T>
    static int getIndexOf(std::vector<T> vector,T object);

    /**
     * Removes an @p object of type @p T from @p vector
     * @tparam T Type of @p object
     * @param vector @ref std::vector to remove object in
     * @param object @p T Object to remove from @p vector
     */
    template<typename T>
    static void removeObject(std::vector<T> &vector, T object);

    /**
     * Removes an object at @p index
     * @tparam T type of @p vector
     * @param vector @ref std::vector Vector to remove object in
     * @param index @ref int Index of object to remove
     */
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
