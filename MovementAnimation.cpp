#include <iostream>
#include "MovementAnimation.h"

MovementAnimation::MovementAnimation() {

}

void MovementAnimation::Init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation) {
    stopped = true;
    texture.loadFromFile(texLocation);
    texture.setSmooth(false);
    sprite.setTexture(&texture);
    sprite.setPosition(pos);
    sprite.setSize(size);

    Update(pos);
}

void MovementAnimation::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}


void MovementAnimation::PushFrame(int left, int top, int width, int height) {
    sf::IntRect subRect;
    subRect.left = left * width;
    subRect.top = top * height;
    subRect.width = width;
    subRect.height = height;
    tex.push_back(subRect);
    sprite.setTextureRect(tex[0]);
}

void MovementAnimation::Update(sf::Vector2f pos) {
    sprite.setPosition(pos);
    if (clock.getElapsedTime().asMilliseconds() > 500) {
        if (frame < tex.size() - 1)
            frame++;
        else
            frame = 1;
        if(stopped){
            sprite.setTextureRect(tex[0]);
        }

        clock.restart();
    }
}

void MovementAnimation::Stop() {
    stopped = true;
}

void MovementAnimation::Start() {
    stopped = false;
    sprite.setTextureRect(tex[frame]);
}
