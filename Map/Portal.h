#ifndef RPGGAME_PORTAL_H
#define RPGGAME_PORTAL_H


#include <SFML/System/Vector2.hpp>
#include <string>
#include <SFML/Graphics/Rect.hpp>

class Portal {
public:
    Portal();

    void init(sf::Vector2f portalPos, sf::Vector2f size, std::string target, sf::Vector2f playerPos);
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPlayerPosition();
    std::string getLevel();

private:
    sf::FloatRect portal;
    sf::Vector2f playerPos;
    std::string level;
};


#endif //RPGGAME_PORTAL_H
