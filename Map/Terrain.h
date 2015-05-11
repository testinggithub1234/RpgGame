#ifndef RPGGAME_LAYER_H
#define RPGGAME_LAYER_H

#include <SFML/Graphics.hpp>
#include "../Manager/TextureManager.h"

class Terrain : public sf::Drawable, sf::Transformable {
public:
    Terrain();

    Terrain(std::string texLoc);

    void setView(sf::View view);

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    std::vector<sf::Vertex> vertices;
    std::string texLocation;
    TextureManager *texture;
};


#endif
