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
/**
 * Deletes @p amount contents in @p vector
 * @param vector @ref std::vector Vector of objects
 * @param amount @ref int Amount to remove
 */
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

    /**
     * @return @ref bool True if @code L@endcode limit isn't hit or there is no limit (L==0), otherwise false
     */
    bool canGetFromPool() {
        return L<=0 || usedObjects.size()<L;
    }
    /**
     * @return @ref bool If the @code L@endcode limit is set (L!=0) and is hit, returns true, otherwise false
     */
    bool isPoolFull() { //fixme Is this the same as !canGetFromPool?
        return L>0 && usedObjects.size()+pooledObjects.size()<L;
    }

    /**
     * Gets a object of type @code T@endcode from @ref ::pooledObjects. If there are no objects to pool, creates a new @code T@endcode. Throws error if pool is full.
     * @return @code T@endcode Pooled or new
     */
    T* get() {
        if(!canGetFromPool()) throw;
        if(pooledObjects.empty()) pooledObjects.push_back(new T);
        T* object = pooledObjects[0];
        VectorMethods::removeObjectAt(pooledObjects,0);
        usedObjects.push_back(object);
        return object;
    };

    /**
     * Puts an object of type @code T@endcode back into @ref ::pooledObjects to returned by @ref ::get() and reused
     * @param object @code T@endcode Object to return to pool
     * @return @ref bool True if successful, otherwise false
     */
    bool put(T *object) {
        int index = VectorMethods::getIndexOf(usedObjects,object);
        if(index == -1) return false;
        VectorMethods::removeObjectAt(usedObjects,index);
        pooledObjects.push_back(object);
        return true;
    }

    /**
     * Uses @ref ::disposeContents on @ref ::pooledObjects
     * @param amount @ref int Amount of items to delete
     * @see ::disposeContents
     */
    void disposePooledContents(int amount=L) {
        disposeContents(pooledObjects,amount);
    }

    /**
     * Fills @ref ::pooledObjects with new objects of type @code T@endcode, stops when @code L@endcode limit is hit
     * @param amount @ref int Amount of new objects to create
     * @return @ref int Amount of objects created (limited by @code L@endcode limit)
     */
    int fillPoolWithContents(int amount=L) {
        int i;
        for(i=0; i<amount; i++) {
            if(isPoolFull()) break;
            pooledObjects.push_back(new T);
        }
        return i;
    }

};

#endif //GAMELIB_OBJECTPOOL_H
