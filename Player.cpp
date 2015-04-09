#include "Player.h"
#include "Collision.h"

void Player::Init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation) {
    texture.loadFromFile(texLocation);
    sprite.setSize(size);
    sprite.setTexture(&texture);
    sprite.setPosition(pos);


    moveUp.Init(getPixelPosition(), getSize(), "Resources/avatar.png");
    moveDown.Init(getPixelPosition(), getSize(), "Resources/avatar.png");
    moveLeft.Init(getPixelPosition(), getSize(), "Resources/avatar.png");
    moveRight.Init(getPixelPosition(), getSize(), "Resources/avatar.png");
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

    movement = down;
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
    bool moved = false;

    if (clock.getElapsedTime().asMilliseconds() >= 80) {
        if (key == sf::Keyboard::Down) {
            y += 32;
            movement = down;
            moved = true;
        }
        else if (key == sf::Keyboard::Up) {
            y += -32;
            movement = up;
            moved = true;
        }
        else if (key == sf::Keyboard::Left) {
            x += -32;
            movement = left;
            moved = true;
        }
        else if (key == sf::Keyboard::Right) {
            x += 32;
            movement = right;
            moved = true;
        }
        sprite.move(x, y);

        if (isPlayerCollidingWithObjects(getPosition(), level)) {
            sprite.move(-x, -y);
            moved = false;
        }
        moveUp.Start();
        moveDown.Start();
        moveRight.Start();
        moveLeft.Start();

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

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    switch (movement) {
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

void Player::Stop() {
    moveDown.Stop();
    moveUp.Stop();
    moveLeft.Stop();
    moveRight.Stop();
}
