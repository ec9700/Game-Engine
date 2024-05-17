//
// Created by subto on 5/17/2024.
//

#include "HitboxData.h"

bool HitboxData::isOverlapping(HitboxData hitboxData) {
    return (abs((position.x + size.x/2) - (hitboxData.position.x + hitboxData.size.x/2)) * 2 < (size.x + hitboxData.size.x)) &&
           (abs((position.y + size.y/2) - (hitboxData.position.y + hitboxData.size.y/2)) * 2 < (size.y + hitboxData.size.y)) &&
           (abs((position.z + size.z/2) - (hitboxData.position.z + hitboxData.size.z/2)) * 2 < (size.z + hitboxData.size.z));
}
