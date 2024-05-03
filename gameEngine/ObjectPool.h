//
// Created by subto on 4/22/2024.
//

#ifndef GAMELIB_OBJECTPOOL_H
#define GAMELIB_OBJECTPOOL_H

#include <vector>
#include <iostream>
#include "VectorMethods.h"

template<typename T, size_t L=0>
class ObjectPool {
private:
    std::vector<T*> pooledObjects;
    std::vector<T*> usedObjects;

    void disposeContents(std::vector<T*> vector, int amount=L) {
        for(int i=0; i<amount; i++) {
            T* object = vector[0];
            VectorMethods::removeObjectAt(vector,0);
            delete object;
        }
    }

public:
    ~ObjectPool() {
        disposePooledContents();
        disposeContents(usedObjects);
    }

    bool canGetFromPool() {
        return L<=0 || usedObjects.size()<L;
    }

    bool isPoolFull() {
        return L>0 && usedObjects.size()+pooledObjects.size()<L;
    }

    T* get() {
        if(!canGetFromPool()) throw;
        if(pooledObjects.empty()) pooledObjects.push_back(new T);
        T* object = pooledObjects[0];
        VectorMethods::removeObjectAt(pooledObjects,0);
        usedObjects.push_back(object);
        return object;
    };

    bool put(T* object) {
        int index = VectorMethods::getIndexOf(usedObjects,object);
        if(index == -1) return false;
        VectorMethods::removeObjectAt(usedObjects,index);
        pooledObjects.push_back(object);
        return true;
    }

    void disposePooledContents(int amount=L) {
        disposeContents(pooledObjects,amount);
    }

    int fillPoolWithContents(int amount=L) {
        int i;
        for(i=0; i<amount; i++) {
            if(isPoolFull()) break;
            pooledObjects.push_back(new T);
        }
        return i;
    }

};


/*T get() {
        if(!pooledObjects.empty()) {
            T object = pooledObjects[0];
            VectorMethods::removeObjectAt(pooledObjects,0);
            usedObjects.push_back(object);
            return &object;
        }
        //Fails ^^^
        if(canGetFromPool()) return NULL;
        T object = new T;
        usedObjects.push_back(object);
        return &object;
    }*/

#endif //GAMELIB_OBJECTPOOL_H
