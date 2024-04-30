//
// Created by subto on 4/8/2024.
//

#ifndef GAMELIB_RENDERCOMPONENT_H
#define GAMELIB_RENDERCOMPONENT_H


#include "../Component.h"
#include "../ShaderCollection.h"

class RenderComponent : public Component {
private:
    ShaderCollection* shaderCollection;
    //float* vertices;
    std::vector<float>* vertices;
public:
    //std::vector<float> *vertices;
    void initial(Entity& parent) override;
    void update(Entity &parent, double& deltaTime) override;
    void reset(Entity& parent) override;
    void setShaderCollection(ShaderCollection &shaderCollection);
    void setVertices(std::vector<float> &vertices);

};


#endif //GAMELIB_RENDERCOMPONENT_H
