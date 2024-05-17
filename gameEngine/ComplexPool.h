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
    template<typename T>
    T* get() {
        //Make sure this can return null
        std::string name = typeid(T).name();
        if (poolMap.find(name) == poolMap.end()) {
            //If not contains
            poolMap[name] = std::any(new ObjectPool<T>());
        }
        //ObjectPool<T>* objectPool = std::any_cast<ObjectPool<T>>(poolMap[typeid(T).name()]);
        //if(objectPool == nullptr) objectPool = new ObjectPool<T>;
        //ObjectPool<T>* z =

        return std::any_cast<ObjectPool<T>*>(poolMap[name])->get();
        //NULL ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    }
    template<typename T>
    bool put(T* object) {
        //return poolMap[typeid(T).name()]->put(object);
        //<std::remove_pointer<std::remove_reference<decltype(*component)>::type>::type>
        std::string type = typeid(*object).name();
        std::any any = poolMap[type];

        //ObjectPool pool = std::any_cast<ObjectPool*>(any);

        ObjectPool<T>* temp = std::any_cast<ObjectPool<T>*>(any); //fixme <---- Can't get this without type
        return temp->put(object);
    }

    /*void dontCrash() {
>>>>>>> broken-component-system

    }*/
};


#endif //GAMELIB_COMPLEXPOOL_H
