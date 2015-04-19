#include "Player.h"
#include <iostream>

using namespace std;

void Player::init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation) {
    if (!texture.loadFromFile("Resources/player.png")) {
        std::cout << "Failed to load player spritesheet!" << std::endl;
    }

    walkingAnimationDown.setSpriteSheet(texture);
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(0, 0, 32, 32));
    walkingAnimationLeft.setSpriteSheet(texture);
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(0, 32, 32, 32));
    walkingAnimationRight.setSpriteSheet(texture);
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(0, 64, 32, 32));
    walkingAnimationUp.setSpriteSheet(texture);
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(0, 96, 32, 32));

    AnimatedSprite initAnimatedSprite(sf::seconds(0.2), true, false);
    animatedSprite = initAnimatedSprite;
    animatedSprite.setPosition(sf::Vector2f(sf::Vector2f(0, 0)));
    animatedSprite.setAnimation(*currentAnimation);

    move = null;
}

void Player::update(sf::Time frameTime) {
    this->frameTime = frameTime;
    animatedSprite.update(this->frameTime);
}

void Player::execute() {
    sf::Vector2f movement(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        movement.y += speed;
        move = down;
        currentAnimation = &walkingAnimationDown;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        movement.y -= speed;
        move = up;
        currentAnimation = &walkingAnimationUp;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        movement.x -= speed;
        move = left;
        currentAnimation = &walkingAnimationLeft;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        movement.x += speed;
        move = right;
        currentAnimation = &walkingAnimationRight;
    }

    initPos = getPixelPosition();

    animatedSprite.play(*currentAnimation);
    animatedSprite.move(movement * frameTime.asSeconds());
}

void Player::stop() {
    animatedSprite.stop();
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

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(animatedSprite);
}


void Player::undoMovement() {
    animatedSprite.setPosition(initPos);
}
