#ifndef RPGGAME_COLLISION_H
#define RPGGAME_COLLISION_H


#include <SFML/Graphics/Rect.hpp>

class Collision {
public:
    Collision();
    bool isPlayerColliding(sf::Vector2f playerPos, sf::Vector2f leveDimensions, std::vector<bool> solidObjects, sf::Vector2f destination);
};


#endif //RPGGAME_COLLISION_H
