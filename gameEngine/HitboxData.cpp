//
// Created by subto on 5/17/2024.
//

#include "HitboxData.h"

bool HitboxData::isOverlapping(HitboxData hitboxData) {
    /*return (abs((position.x + size.x/2) - (hitboxData.position.x + hitboxData.size.x/2)) * 2 < (size.x + hitboxData.size.x)) &&
           (abs((position.y + size.y/2) - (hitboxData.position.y + hitboxData.size.y/2)) * 2 < (size.y + hitboxData.size.y)) &&
           (abs((position.z + size.z/2) - (hitboxData.position.z + hitboxData.size.z/2)) * 2 < (size.z + hitboxData.size.z));*/

    /*return (abs(position.x - hitboxData.position.x) * 2 < (size.x + hitboxData.size.x)) &&
           (abs(position.y - hitboxData.position.y) * 2 < (size.y + hitboxData.size.y)) &&
            (abs(position.z - hitboxData.position.z) * 2 < (size.z + hitboxData.size.z));*/
    //this.x+hitBoxOffset.x<x && this.x+hitBoxSizeX+hitBoxOffset.x>x && this.y+hitBoxOffset.y<y && this.y+hitBoxSizeY+hitBoxOffset.y>y;
    return position.x+size.x > hitboxData.position.x && position.x < hitboxData.position.x+hitboxData.size.x &&
           position.y+size.y > hitboxData.position.y && position.y < hitboxData.position.y+hitboxData.size.y &&
           position.z+size.z > hitboxData.position.z && position.z < hitboxData.position.z+hitboxData.size.z;
}

