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

    move = null;
    destination.x = 0;
    destination.y = 0;
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
        animatedSprite.play(*currentAnimation);

    initPos = getPixelPosition();


    animatedSprite.move(movement * frameTime.asSeconds());
}

void Player::movement() {
    if(move != null){

    }
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


