#include "Player.h"
#include "Level.h"
#include "Collision.h"

void Player::Init(sf::Vector2f pos) {
    sprite.setSize(sf::Vector2f(32, 32));
    sprite.setFillColor(sf::Color::Blue);
    sprite.setPosition(pos);
}

void Player::Update() {
    boundingBox = sprite.getGlobalBounds();
}

void Player::Execute(sf::Keyboard::Key key, Level level) {
    int x = 0, y = 0;

    if (clock.getElapsedTime().asMilliseconds() >= 100) {
        if (key == sf::Keyboard::Down) {
            y = 32;
        }
        else if (key == sf::Keyboard::Up) {
            y = -32;
        }
        else if (key == sf::Keyboard::Left) {
            x = -32;
        }
        else if (key == sf::Keyboard::Right) {
            x = 32;
        }

        sprite.move(x, y);

        if (isPlayerCollidingWithObjects(getPosition(), level)) {
            sprite.move(-x, -y);
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
