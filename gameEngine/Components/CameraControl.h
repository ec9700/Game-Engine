//
// Created by subto on 4/8/2024.
//

#ifndef GAMELIB_CAMERACONTROL_H
#define GAMELIB_CAMERACONTROL_H


#include "../Component.h"

class CameraControl : public Component {
    void initial(Entity parent) override;
    void update(Entity &parent, double deltaTime) override;
    void dispose(Entity parent) override;
};


#endif //GAMELIB_CAMERACONTROL_H
