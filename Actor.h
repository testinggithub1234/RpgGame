#ifndef RPGGAME_ACTOR_H
#define RPGGAME_ACTOR_H

#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include "AnimatedSprite.h"

class Actor : public sf::Drawable {
public:
    Actor();

    void init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation);

    void addAnimationUp(int x, int y);

    void addAnimationDown(int x, int y);

    void addAnimationLeft(int x, int y);

    void addAnimationRight(int x, int y);

    void update(sf::Time frameTime);

    void movement();

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    void undoMovement();

    void stop();

    sf::Vector2f getPosition();

    sf::Vector2f getPixelPosition();

    sf::Vector2f getSize();

    sf::Vector2f getDestination();

    sf::FloatRect getGlobalBounds();

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::Vector2f size;

    float speed = 70.f;

    enum Movement {
        UP, DOWN, RIGHT, LEFT, _NULL, ISMOVING
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


#endif //RPGGAME_ACTOR_H
