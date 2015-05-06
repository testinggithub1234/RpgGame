#ifndef RPGGAME_LEVEL_H
#define RPGGAME_LEVEL_H

#include <vector>
#include <string>
#include <SFML/System/Vector2.hpp>
#include "Terrain.h"
#include "TileMap.h"

class Level : public sf::Drawable, sf::Transformable {
public:
    Level();

    void LoadLevel(char* lev);

    std::vector<bool> getSolidObjectsList();

    sf::Vector2f getPlayerPosition();

    sf::Vector2f getSize();

    void updateView(sf::View view);

private:
    std::vector<bool> solidObjects;
    sf::Vector2f playerPos;
    ///Players starting position
    float width, height;

    Terrain terrain;
    std::vector<TileMap> underPlayer;
    std::vector<TileMap> overPlayer;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //RPGGAME_LEVEL_H
