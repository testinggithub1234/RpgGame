#ifndef RPGGAME_LEVEL_H
#define RPGGAME_LEVEL_H

#include <vector>
#include <string>
#include <SFML/System/Vector2.hpp>

class Level {
public:
    Level();

    void LoadLevel(std::string lev);
    std::vector<int> getTerrain();
    std::vector<bool> getSolidObjectsList();
    std::vector<int> getSecondLayer();
    sf::Vector2f getPlayerPosition();
    sf::Vector2f getSize();

private:
    std::vector<int> terrain;
    std::vector<int> secondLayer;
    std::vector<bool> solidObjects;
    sf::Vector2f playerPos;///Players starting position
    float width, height;
};

#endif //RPGGAME_LEVEL_H
