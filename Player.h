#ifndef RPGGAME_PLAYER_H
#define RPGGAME_PLAYER_H

#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Npc.h"
#include "AnimatedSprite.h"
#include "TextureManager.h"

class Player : public sf::Drawable {
public:
    Player() { }

    void init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation);

    void execute();

    void movement();

    void undoMovement();

    void update(sf::Time frameTime);

    void stop();

    sf::Vector2f getPosition();

    sf::Vector2f getPixelPosition();

    sf::Vector2f getSize();

    sf::Vector2f getDestination();

    sf::FloatRect getGlobalBounds();

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    float speed = 70.f;

    enum Movement {
        up, down, right, left, null, isMoving
    };
    Movement move;

    sf::Vector2f destination;

    sf::Vector2f direction;

    sf::Vector2f initPos;

    sf::Time frameTime;

    TextureManager texture;

    Animation walkingAnimationDown;
    Animation walkingAnimationUp;
    Animation walkingAnimationLeft;
    Animation walkingAnimationRight;
    Animation *currentAnimation = &walkingAnimationDown;
    AnimatedSprite animatedSprite;
};


#endif //RPGGAME_PLAYER_H
