#include <iostream>
#include "Animation.h"

MovementAnimation::MovementAnimation() {

}

void MovementAnimation::Init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation) {
    stopped = true;

    position = pos;
    this->size = size;
    textureLocation = texLocation;

    Update(pos);
    frame = 0;
}

void MovementAnimation::PushFrame(int left, int top, int width, int height) {
    sf::IntRect subRect;
    subRect.left = left * width;
    subRect.top = top * height;
    subRect.width = width;
    subRect.height = height;

    sf::RectangleShape sprite;
    sprite.setTexture(&texture.getTexture(textureLocation));
    sprite.setTextureRect(subRect);
    sprite.setPosition(position);
    sprite.setSize(size);

    sprites.push_back(sprite);
}

void MovementAnimation::Update(sf::Vector2f pos) {
    for(int i = 0; i < sprites.size();i++)
        sprites[i].setPosition(pos);

    if (clock.getElapsedTime().asMilliseconds() > 500) {
        if (frame < sprites.size() - 1)
            frame++;
        else
            frame = 1;

        if(stopped){
            frame = 0;
        }

        clock.restart();
    }
}

void MovementAnimation::Start() {
    if(stopped){
        frame = 1;
        stopped = false;
    }
}

void MovementAnimation::Stop() {
    stopped = true;
}

void MovementAnimation::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprites[frame], states);
}

