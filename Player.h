#ifndef RPGGAME_PLAYER_H
#define RPGGAME_PLAYER_H

#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Animation.h"
#include "Npc.h"

class Player : public sf::Drawable {
public:
    Player() { }

    void Init(sf::Vector2f pos, sf::Vector2f size, std::string texLocation);

    void Execute(sf::Keyboard::Key key, std::vector<bool> solidObjects, std::vector<Npc> npcList);

    void Update();

    void Stop();

    sf::RectangleShape sprite;

    sf::Vector2f getPosition();

    sf::Vector2f getPixelPosition();

    sf::Vector2f getSize();

    sf::FloatRect boundingBox;

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    enum Movement{up, down, right, left};
    Movement move;

    sf::Clock clock;

    Animation moveDown;
    Animation moveUp;
    Animation moveLeft;
    Animation moveRight;
};


#endif //RPGGAME_PLAYER_H
