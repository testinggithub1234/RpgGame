#ifndef RPGGAME_PORTAL_H
#define RPGGAME_PORTAL_H


#include <SFML/System/Vector2.hpp>
#include <string>

class Portal {
public:
    Portal();
    void init(sf::Vector2f portalPos, std::string target, sf::Vector2f playerPos);
private:
    sf::Vector2f playerPos;
    std::string targetLevel;
};


#endif //RPGGAME_PORTAL_H
