#ifndef RPGGAME_LEVEL_H
#define RPGGAME_LEVEL_H

#include <vector>
#include <string>
#include <SFML/System/Vector2.hpp>
#include "Terrain.h"
#include "TileMap.h"
#include "Portal.h"

class Level : public sf::Drawable, sf::Transformable {
public:
    Level();

    void LoadLevel(char* lev);

    std::vector<bool> getSolidObjectsList();

    std::vector<Portal> getPortals();

    sf::Vector2f getPlayerPosition();

    sf::Vector2f getSize();

    void drawOver(sf::RenderWindow &target);

    void updateView(sf::View view);

private:
    float width, height;
    char* level;

    std::vector<bool> solidObjects;
    sf::Vector2f playerPos;

    Terrain terrain;
    std::vector<TileMap> underPlayer;
    std::vector<TileMap> overPlayer;
    std::vector<Portal> portals;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //RPGGAME_LEVEL_H
