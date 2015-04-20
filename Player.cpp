#include "Player.h"
#include <iostream>

using namespace std;

void Player::init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation) {

    walkingAnimationDown.setSpriteSheet(texture.getTexture(texLocation));
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, size.x, size.y));
    walkingAnimationDown.addFrame(sf::IntRect(64, 0, size.x, size.y));
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, size.x, size.y));
    walkingAnimationDown.addFrame(sf::IntRect(0, 0, size.x, size.y));
    walkingAnimationLeft.setSpriteSheet(texture.getTexture(texLocation));
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, size.x, size.y));
    walkingAnimationLeft.addFrame(sf::IntRect(64, 32, size.x, size.y));
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, size.x, size.y));
    walkingAnimationLeft.addFrame(sf::IntRect(0, 32, size.x, size.y));
    walkingAnimationRight.setSpriteSheet(texture.getTexture(texLocation));
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, size.x, size.y));
    walkingAnimationRight.addFrame(sf::IntRect(64, 64, size.x, size.y));
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, size.x, size.y));
    walkingAnimationRight.addFrame(sf::IntRect(0, 64, size.x, size.y));
    walkingAnimationUp.setSpriteSheet(texture.getTexture(texLocation));
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, size.x, size.y));
    walkingAnimationUp.addFrame(sf::IntRect(64, 96, size.x, size.y));
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, size.x, size.y));
    walkingAnimationUp.addFrame(sf::IntRect(0, 96, size.x, size.y));

    AnimatedSprite initAnimatedSprite(sf::seconds(0.2), true, false);
    animatedSprite = initAnimatedSprite;
    animatedSprite.setPosition(pos);
    animatedSprite.setAnimation(*currentAnimation);
    animatedSprite.setLooped(true);
    move = null;
    direction.x = 0;
    direction.y = 0;
}

void Player::update(sf::Time frameTime) {
    this->frameTime = frameTime;
    animatedSprite.update(this->frameTime);
}

void Player::execute() {
    if (move == null) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            move = down;
            currentAnimation = &walkingAnimationDown;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            move = up;
            currentAnimation = &walkingAnimationUp;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            move = left;
            currentAnimation = &walkingAnimationLeft;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            move = right;
            currentAnimation = &walkingAnimationRight;
        }
        initPos = getPixelPosition();
    }
    animatedSprite.play(*currentAnimation);
}

void Player::movement() {
    switch (move) {
        case up:
            direction = sf::Vector2f(0, -1);
            destination = getPosition() + direction;
            move = isMoving;
            break;
        case down:
            direction = sf::Vector2f(0, 1);
            destination = getPosition() + direction;
            move = isMoving;
            break;
        case left:
            direction = sf::Vector2f(-1, 0);
            destination = getPosition() + direction;
            move = isMoving;
            break;
        case right:
            direction = sf::Vector2f(1, 0);
            destination = getPosition() + direction;
            move = isMoving;
            break;
        case isMoving:
            animatedSprite.move(direction * speed * frameTime.asSeconds());
            if (direction.x == -1 or direction.y == -1) {
                if (getPixelPosition().x < destination.x * 32 or getPixelPosition().y < destination.y * 32) {
                    animatedSprite.setPosition(destination.x * 32, destination.y * 32);
                    move = null;
                }
            }
            else if (getPixelPosition().x > destination.x * 32 or getPixelPosition().y > destination.y * 32) {
                animatedSprite.setPosition(destination.x * 32, destination.y * 32);
                move = null;
            }
            break;
    }
}


void Player::undoMovement() {
    animatedSprite.setPosition(initPos);
    destination = getPosition();
    direction = sf::Vector2f(0, 0);
    move = null;
}

void Player::stop() {
    if (move == null) {
        animatedSprite.stop();
    }
}

sf::Vector2f Player::getPosition() {
    return sf::Vector2f(animatedSprite.getPosition().x / getSize().x, animatedSprite.getPosition().y / getSize().y);
}

sf::Vector2f Player::getPixelPosition() {
    return animatedSprite.getPosition();
}

sf::Vector2f Player::getSize() {
    return sf::Vector2f(animatedSprite.getGlobalBounds().height, animatedSprite.getGlobalBounds().width);
}

sf::FloatRect Player::getGlobalBounds() {
    return animatedSprite.getGlobalBounds();
}

sf::Vector2f Player::getDestination() {
    return destination;
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(animatedSprite);
}

