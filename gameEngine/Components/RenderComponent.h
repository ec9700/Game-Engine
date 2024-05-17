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
    /**
     * Renders bound @ref Entity using @ref ::shaderCollection and @ref vertices
     */
    void update(Entity &parent, double& deltaTime) override;
    void reset(Entity& parent) override;

    /**
     * Sets the @ref ::shaderCollection this @ref RenderComponent uses for rendering
     * @param shaderCollection @ref ShaderCollection
     * @see RenderManager
     */
    void setShaderCollection(ShaderCollection &shaderCollection);
    /**
     * Sets the @ref ::verticies this @ref RenderComponent uses for rendering
     * @param vertices @ref std::vector<float>
     * @see RenderManager
     */
    void setVertices(std::vector<float> &vertices);
    friend Entity;

};


#endif //GAMELIB_RENDERCOMPONENT_H
