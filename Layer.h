#ifndef RPGGAME_LAYER_H
#define RPGGAME_LAYER_H

#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class Layer : public sf::Drawable, sf::Transformable {
public:
    Layer();

    Layer(std::string texLoc);

    void setView(sf::View view);

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    std::vector<sf::Vertex> vertices;
    std::string texLocation;
    TextureManager *texture;
};


#endif
