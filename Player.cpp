#include "Player.h"
#include "Collision.h"

void Player::Init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation) {
    sprite.setSize(size);
    sprite.setPosition(pos);

    moveUp.Init(getPixelPosition(), getSize(), texLocation);
    moveDown.Init(getPixelPosition(), getSize(), texLocation);
    moveLeft.Init(getPixelPosition(), getSize(), texLocation);
    moveRight.Init(getPixelPosition(), getSize(), texLocation);
    moveUp.PushFrame(2, 0, 32, 38);
    moveUp.PushFrame(8, 0, 32, 38);
    moveUp.PushFrame(9, 0, 32, 38);
    moveDown.PushFrame(0, 0, 32, 38);
    moveDown.PushFrame(4, 0, 32, 38);
    moveDown.PushFrame(5, 0, 32, 38);
    moveLeft.PushFrame(1, 0, 32, 38);
    moveLeft.PushFrame(6, 0, 32, 38);
    moveLeft.PushFrame(7, 0, 32, 38);
    moveRight.PushFrame(3, 0, 32, 38);
    moveRight.PushFrame(10, 0, 32, 38);
    moveRight.PushFrame(11, 0, 32, 38);

    move = down;
}

void Player::Update() {
    boundingBox = sprite.getGlobalBounds();
    moveUp.Update(getPixelPosition());
    moveDown.Update(getPixelPosition());
    moveLeft.Update(getPixelPosition());
    moveRight.Update(getPixelPosition());
}

void Player::Execute(sf::Keyboard::Key key, Level level) {
    int x = 0, y = 0;

    if (clock.getElapsedTime().asMilliseconds() >= 80) {
        if (key == sf::Keyboard::Down) {
            y += 32;
            move = down;
            moveDown.Start();
        }
        else if (key == sf::Keyboard::Up) {
            y += -32;
            move = up;
            moveUp.Start();
        }
        else if (key == sf::Keyboard::Left) {
            x += -32;
            move = left;
            moveLeft.Start();
        }
        else if (key == sf::Keyboard::Right) {
            x += 32;
            move = right;
            moveRight.Start();
        }
        sprite.move(x, y);

        if (isPlayerCollidingWithObjects(getPosition(), level)) {
            sprite.move(-x, -y);
        }

        clock.restart();
    }
}

sf::Vector2f Player::getPosition() {
    return sf::Vector2f(sprite.getPosition().x / sprite.getSize().x, sprite.getPosition().y / sprite.getSize().y);
}

sf::Vector2f Player::getPixelPosition() {
    return sprite.getPosition();
}

sf::Vector2f Player::getSize() {
    return sprite.getSize();
}

void Player::Stop() {
    moveDown.Stop();
    moveUp.Stop();
    moveLeft.Stop();
    moveRight.Stop();
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    switch (move) {
        case up :
            target.draw(moveUp, states);
            break;
        case down :
            target.draw(moveDown, states);
            break;
        case left :
            target.draw(moveLeft, states);
            break;
        case right :
            target.draw(moveRight, states);
            break;
    }
}

