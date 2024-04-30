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
    std::unordered_map<std::type_info,ObjectPool<std::any>*> poolMap;
public:
    template<typename T>
    T* get() {
        //Make sure this can return null
        ObjectPool<T>* objectPool = std::any_cast<ObjectPool<T>*>(poolMap[typeid(T)]);
        if(objectPool == nullptr) objectPool = new ObjectPool<T>;
        return objectPool->get();
    }
    template<typename T>
    bool put(T& object) {
        return poolMap[typeid(T)]->put(object);
    }
};


#endif //GAMELIB_COMPLEXPOOL_H
