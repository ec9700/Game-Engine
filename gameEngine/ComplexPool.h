//
// Created by subto on 4/22/2024.
//

#ifndef GAMELIB_COMPLEXPOOL_H
#define GAMELIB_COMPLEXPOOL_H
#include <unordered_map>
#include <any>
#include "ObjectPool.h"

class ComplexPool {
private:
    //std::unordered_map<std::string,ObjectPool<std::any,0>*> poolMap;
    std::unordered_map<std::string,std::any> poolMap;
public:
    /**
     * Gets an object from a @ref ObjectPool::pooledObjects of type @code T@endcode, creating a new one if none exist
     * @tparam T Type of object to get
     * @return Object of type @code T@endcode
     */
    template<typename T>
    T* get() {
        //Make sure this can return null
        std::string name = typeid(T).name();
        if (poolMap.find(name) == poolMap.end()) {
            //If not contains
            poolMap[name] = std::any(new ObjectPool<T>());
        }

        return std::any_cast<ObjectPool<T>*>(poolMap[name])->get();
        //NULL ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    }
    /**
     * Puts an object of type @code T@endcode into a @ref ObjectPool::pooledObjects to returned by @ref ObjectPool::get() and reused
     * @tparam T Type of object to put back
     * @param object Object of type @code T@endcode to put back
     * @return @ref bool True if successful, otherwise false
     * @see ObjectPool::get()
     */
    template<typename T>
    bool put(T* object) {
        //fixme Turns out types can only be assigned at compile time, making returning object with a type only known at runtime impossible
        std::string type = typeid(*object).name();
        std::any any = poolMap[type];

        ObjectPool<T>* temp = std::any_cast<ObjectPool<T>*>(any); //fixme <---- Can't get this without type
        return temp->put(object);
    }

};


#endif //GAMELIB_COMPLEXPOOL_H
