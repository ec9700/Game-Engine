//
// Created by subto on 5/17/2024.
//

#ifndef GAMELIB_HITBOXCOMPONENT_H
#define GAMELIB_HITBOXCOMPONENT_H


#include "../Entity.h"
#include "../Component.h"
#include "../HitboxData.h"

class HitboxComponent : Component {
private:
    void initial(Entity& parent) override;
    /**
     * Checks if a area check in @ref ::hitboxAreaCheckMap (represented by @ref HitboxData) is overlapping with @ref ::data. Calls @ref HitboxData::onHit() when an overlap is detected.
     */
    void update(Entity &parent, double& deltaTime) override;
    void reset(Entity& parent) override;

    /**
     * A @ref std::unordered_map storing layerNames and @ref HitboxData. Each @ref HitboxComponent checks @ref ::hitboxAreaCheckMap every frame to check for overlap
     */
    static std::unordered_map<std::string,std::vector<HitboxData*>> hitboxAreaCheckMap;
    HitboxData data;

    friend Entity;
    friend GameManager;
};


#endif //GAMELIB_HITBOXCOMPONENT_H
