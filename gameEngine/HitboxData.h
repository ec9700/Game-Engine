//
// Created by subto on 5/17/2024.
//

#ifndef GAMELIB_HITBOXDATA_H
#define GAMELIB_HITBOXDATA_H


#include <string>
#include "glm/vec3.hpp"
#include "Entity.h"

class Entity;

class HitboxData {
public:
    glm::vec3 position;
    glm::vec3 size;
    std::string layerName;
    void (*onHit)(Entity*);

    /**
     * Checks if @p hitboxData is overlapping with this @ref HitboxData
     * @param hitboxData @ref HitboxData to check for overlap with
     * @return @ref bool True if overlapping, otherwise false
     */
    bool isOverlapping(HitboxData hitboxData);

};


#endif //GAMELIB_HITBOXDATA_H
