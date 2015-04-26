#include "Player.h"
#include <iostream>

using namespace std;

void Player::init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation) {
    actor.init(pos, size, texture.getTexture(texLocation));
    actor.addAnimationDown(7, 0);
    actor.addAnimationDown(6, 0);
    actor.addAnimationDown(7, 0);
    actor.addAnimationDown(8, 0);
    actor.addAnimationLeft(7, 1);
    actor.addAnimationLeft(6, 1);
    actor.addAnimationLeft(7, 1);
    actor.addAnimationLeft(8, 1);
    actor.addAnimationRight(7, 2);
    actor.addAnimationRight(6, 2);
    actor.addAnimationRight(7, 2);
    actor.addAnimationRight(8, 2);
    actor.addAnimationUp(7, 3);
    actor.addAnimationUp(6, 3);
    actor.addAnimationUp(7, 3);
    actor.addAnimationUp(8, 3);
}

void Player::update(sf::Time frameTime) {
    actor.update(frameTime);
}

void Player::execute() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        actor.moveDown();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        actor.moveUp();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        actor.moveLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        actor.moveRight();
    }
}

void Player::movement() {
    actor.movement();
}

void Player::undoMovement() {
    actor.undoMovement();
}

void Player::stop() {
    actor.stop();
}

bool Player::isMoving() {
    return actor.isMoving();
}

sf::Vector2f Player::getPosition() {
    return actor.getPosition();
}

sf::Vector2f Player::getPixelPosition() {
    return actor.getPixelPosition();
}

sf::Vector2f Player::getSize() {
    return actor.getSize();
}

sf::FloatRect Player::getGlobalBounds() {
    return actor.getGlobalBounds();
}

sf::Vector2f Player::getDestination() {
    return actor.getDestination();
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(actor);
}
