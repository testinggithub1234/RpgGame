#include "Player.h"
#include <iostream>

using namespace std;

void Player::init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation) {
    actor.init(pos, size, texLocation);
    actor.addAnimationDown(1, 0);
    actor.addAnimationDown(0, 0);
    actor.addAnimationDown(1, 0);
    actor.addAnimationDown(2, 0);
    actor.addAnimationLeft(1, 1);
    actor.addAnimationLeft(0, 1);
    actor.addAnimationLeft(1, 1);
    actor.addAnimationLeft(2, 1);
    actor.addAnimationRight(1, 2);
    actor.addAnimationRight(0, 2);
    actor.addAnimationRight(1, 2);
    actor.addAnimationRight(2, 2);
    actor.addAnimationUp(1, 3);
    actor.addAnimationUp(0, 3);
    actor.addAnimationUp(1, 3);
    actor.addAnimationUp(2, 3);
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

