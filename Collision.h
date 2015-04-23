#ifndef RPGGAME_COLLISION_H
#define RPGGAME_COLLISION_H


#include <SFML/Graphics/Rect.hpp>

class Collision {
public:
    Collision();

    bool isPlayerColliding(sf::Vector2f destination, sf::Vector2f leveDimensions,
                           std::vector<bool> solidObjects, sf::FloatRect playerBox, std::vector<sf::FloatRect> npcsBoxes);
};


#endif //RPGGAME_COLLISION_H
