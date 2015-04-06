#ifndef RPGGAME_LEVEL_H
#define RPGGAME_LEVEL_H

#include <vector>
#include <string>
#include <SFML/System/Vector2.hpp>

class Level {
public:
    std::vector<int> map;
    std::vector<bool> solidObjects;

    sf::Vector2f playerPos;
    unsigned int width, height;

    void LoadLevel(std::string lev);
};


#endif //RPGGAME_LEVEL_H
