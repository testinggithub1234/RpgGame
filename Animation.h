#ifndef RPGGAME_MOVEMENTANIMATION_H
#define RPGGAME_MOVEMENTANIMATION_H


#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class MovementAnimation : public sf::Drawable {
public:
    MovementAnimation();

    bool stopped;

    void Init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation);

    void PushFrame(int left, int top, int width, int height);

    void Start();

    void Stop();

    void Update(sf::Vector2f pos);

private:
    std::string textureLocation;

    std::vector<sf::RectangleShape> sprites;

    sf::Vector2f position, size;

    sf::Clock clock;
    int frame;

    TextureManager texture;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //RPGGAME_MOVEMENTANIMATION_H
