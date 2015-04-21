#include "Actor.h"

Actor::Actor() {
}

void Actor::init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation) {
    walkingAnimationUp.setSpriteSheet(texture.getTexture(texLocation));
    walkingAnimationDown.setSpriteSheet(texture.getTexture(texLocation));
    walkingAnimationLeft.setSpriteSheet(texture.getTexture(texLocation));
    walkingAnimationRight.setSpriteSheet(texture.getTexture(texLocation));

    AnimatedSprite initAnimatedSprite(sf::seconds(0.2), true, true);
    animatedSprite = initAnimatedSprite;
    animatedSprite.setPosition(pos);
    move = _NULL;
    direction.x = 0;
    direction.y = 0;

    this->size = size;
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

void Actor::update(sf::Time frameTime) {
    this->frameTime = frameTime;
    animatedSprite.update(this->frameTime);
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
                    animatedSprite.setPosition(destination.x * 32, destination.y * 32);
                    move = _NULL;
                }
            }
            else if (getPixelPosition().x > destination.x * 32 or getPixelPosition().y > destination.y * 32) {
                animatedSprite.setPosition(destination.x * 32, destination.y * 32);
                move = _NULL;
            }
            break;
    }
}

void Actor::undoMovement() {
    animatedSprite.setPosition(initPos);
    destination = getPosition();
    direction = sf::Vector2f(0, 0);
    move = _NULL;
}

void Actor::stop() {
    if (move == _NULL) {
        animatedSprite.stop();
    }
}

sf::Vector2f Actor::getPosition() {
    return sf::Vector2f(animatedSprite.getPosition().x / getSize().x, animatedSprite.getPosition().y / getSize().y);
}

sf::Vector2f Actor::getPixelPosition() {
    return animatedSprite.getPosition();
}

sf::Vector2f Actor::getSize() {
    return sf::Vector2f(animatedSprite.getGlobalBounds().height, animatedSprite.getGlobalBounds().width);
}

sf::Vector2f Actor::getDestination() {
    return destination;
}

sf::FloatRect Actor::getGlobalBounds() {
    return animatedSprite.getGlobalBounds();
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

void Actor::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(animatedSprite);
}