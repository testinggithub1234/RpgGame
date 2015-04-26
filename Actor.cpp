#include <iostream>
#include "Actor.h"

Actor::Actor() {
}

void Actor::init(sf::Vector2f pos, sf::Vector2f size, sf::Texture &texture) {
    walkingAnimationUp.setSpriteSheet(texture);
    walkingAnimationDown.setSpriteSheet(texture);
    walkingAnimationLeft.setSpriteSheet(texture);
    walkingAnimationRight.setSpriteSheet(texture);

    AnimatedSprite initAnimatedSprite(sf::seconds(0.2), true, true);
    animatedSprite = initAnimatedSprite;
    animatedSprite.setPosition(pos);
    move = _NULL;
    direction.x = 0;
    direction.y = 0;

    this->size = size;
    headSize = size.y - size.x;
}

void Actor::addAnimationUp(int x, int y) {
    walkingAnimationUp.addFrame(sf::IntRect(x * size.x, y * size.y, size.x, size.y));
    animatedSprite.setAnimation(*currentAnimation);
}

void Actor::addAnimationDown(int x, int y) {
    walkingAnimationDown.addFrame(sf::IntRect(x * size.x, y * size.y, size.x, size.y));
    animatedSprite.setAnimation(*currentAnimation);
}

void Actor::addAnimationLeft(int x, int y) {
    walkingAnimationLeft.addFrame(sf::IntRect(x * size.x, y * size.y, size.x, size.y));
    animatedSprite.setAnimation(*currentAnimation);
}

void Actor::addAnimationRight(int x, int y) {
    walkingAnimationRight.addFrame(sf::IntRect(x * size.x, y * size.y, size.x, size.y));
    animatedSprite.setAnimation(*currentAnimation);
}

void Actor::moveUp() {
    if (move == _NULL) {
        move = UP;
        currentAnimation = &walkingAnimationUp;
        initPos = getPixelPosition();
    }
    animatedSprite.play(*currentAnimation);
}

void Actor::moveDown() {
    if (move == _NULL) {
        move = DOWN;
        currentAnimation = &walkingAnimationDown;
        initPos = getPixelPosition();
    }
    animatedSprite.play(*currentAnimation);
}

void Actor::moveLeft() {
    if (move == _NULL) {
        move = LEFT;
        currentAnimation = &walkingAnimationLeft;
        initPos = getPixelPosition();

    }
    animatedSprite.play(*currentAnimation);
}

void Actor::moveRight() {
    if (move == _NULL) {
        move = RIGHT;
        currentAnimation = &walkingAnimationRight;
        initPos = getPixelPosition();
    }
    animatedSprite.play(*currentAnimation);
}

void Actor::movement() {
    switch (move) {
        case UP:
            direction = sf::Vector2f(0, -1);
            destination = getPosition() + direction;
            move = ISMOVING;
            break;
        case DOWN:
            direction = sf::Vector2f(0, 1);
            destination = getPosition() + direction;
            move = ISMOVING;
            break;
        case LEFT:
            direction = sf::Vector2f(-1, 0);
            destination = getPosition() + direction;
            move = ISMOVING;
            break;
        case RIGHT:
            direction = sf::Vector2f(1, 0);
            destination = getPosition() + direction;
            move = ISMOVING;
            break;
        case ISMOVING:
            animatedSprite.move(direction * speed * frameTime.asSeconds());
            if (direction.x == -1 or direction.y == -1) {
                if (getPixelPosition().x < destination.x * 32 or getPixelPosition().y < destination.y * 32) {
                    animatedSprite.setPosition(destination.x * 32, destination.y * 32 - headSize);
                    move = _NULL;
                }
            }
            else if (getPixelPosition().x > destination.x * 32 or getPixelPosition().y > destination.y * 32) {
                animatedSprite.setPosition(destination.x * 32, destination.y * 32 - headSize);
                move = _NULL;
            }
            break;
    }
}

void Actor::undoMovement() {
    animatedSprite.setPosition(initPos.x, initPos.y - headSize);
    destination = getPosition();
    direction = sf::Vector2f(0, 0);
    move = _NULL;
}

void Actor::update(sf::Time frameTime) {
    this->frameTime = frameTime;
    animatedSprite.update(this->frameTime);
}

void Actor::stop() {
    if (move == _NULL) {
        animatedSprite.stop();
    }
}

bool Actor::isMoving() {
    return move == ISMOVING;
}

sf::Vector2f Actor::getPosition() {
    return sf::Vector2f(animatedSprite.getPosition().x / getSize().x,
                        (animatedSprite.getPosition().y + headSize) / getSize().y);
}

sf::Vector2f Actor::getPixelPosition() {
    return sf::Vector2f(animatedSprite.getPosition().x, animatedSprite.getPosition().y + headSize);
}

sf::Vector2f Actor::getSize() {
    return sf::Vector2f(animatedSprite.getGlobalBounds().width, animatedSprite.getGlobalBounds().height - headSize);
}

sf::Vector2f Actor::getDestination() {
    return destination;
}

sf::FloatRect Actor::getGlobalBounds() {
    sf::FloatRect temp = animatedSprite.getGlobalBounds();
    temp.top += headSize;
    temp.height -= headSize;
    return temp;
}

void Actor::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(animatedSprite);
}

void Actor::draw(sf::RenderTarget &window) {
    window.draw(animatedSprite);
}
