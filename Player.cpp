#include "Player.h"

void Player::Init(sf::Vector2f pos) {
    sprite.setSize(sf::Vector2f(32, 32));
    sprite.setFillColor(sf::Color::Blue);
    sprite.setPosition(pos);
}

void Player::Update() {
    boundingBox = sprite.getGlobalBounds();
}

void Player::Execute(sf::Keyboard::Key key) {
    if (clock.getElapsedTime().asMilliseconds() >= 100) {
        if (key == sf::Keyboard::Down) {
            sprite.move(0, 32);
        }
        else if (key == sf::Keyboard::Up) {
            sprite.move(0, -32);
        }
        else if (key == sf::Keyboard::Left) {
            sprite.move(-32, 0);
        }
        else if (key == sf::Keyboard::Right) {
            sprite.move(32, 0);
        }
        clock.restart();
    }
}

sf::Vector2f Player::getPosition() {
    return sprite.getPosition();
}

sf::Vector2f Player::getSize() {
    return sprite.getSize();
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}
