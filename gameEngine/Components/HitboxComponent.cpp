//
// Created by subto on 5/17/2024.
//



#include "HitboxComponent.h"


std::unordered_map<std::string,std::vector<HitboxData*>> HitboxComponent::hitboxAreaCheckMap;

void HitboxComponent::initial(Entity &parent) {

}

void HitboxComponent::update(Entity &parent, double &deltaTime) {
    for(HitboxData* hitboxData : hitboxAreaCheckMap[this->data.layerName]) {
        if(data.isOverlapping(*hitboxData)) hitboxData->onHit(&parent);

    }
}

void HitboxComponent::reset(Entity &parent) {

}

