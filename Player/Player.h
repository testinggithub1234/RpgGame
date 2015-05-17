#ifndef RPGGAME_PLAYER_H
#define RPGGAME_PLAYER_H

#include <SFML/Graphics.hpp>
#include "../Manager/TextureManager.h"
#include "../Actor/Actor.h"

class Player : public sf::Drawable {
public:
    Player() { }

    void init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation);

    void execute();

    void movement();

    void undoMovement();

    void update(sf::Time frameTime);

    void stop();

    bool isMoving();

    void setPosition(sf::Vector2f pos);

    sf::Vector2f getPosition();

    sf::Vector2f getPixelPosition();

    sf::Vector2f getSize();

    sf::Vector2f getDestination();

    sf::FloatRect getGlobalBounds();

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    Actor actor;
    TextureManager texture;
};


#endif //RPGGAME_PLAYER_H
