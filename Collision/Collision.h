#ifndef RPGGAME_COLLISION_H
#define RPGGAME_COLLISION_H


#include <SFML/Graphics/Rect.hpp>

class Collision {
public:
    Collision();
    void loadData(sf::Vector2f leveDimensions, std::vector<bool> solidObjects);
    bool isPlayerColliding(sf::Vector2f destination,  sf::FloatRect playerBox, std::vector<sf::FloatRect> npcsBoxes);
private:
    std::vector<bool> solidObjects;
    sf::Vector2f levelDimensions;
};


#endif //RPGGAME_COLLISION_H
