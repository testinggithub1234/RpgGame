#ifndef RPGGAME_ENTITYMANAGER_H
#define RPGGAME_ENTITYMANAGER_H


#include <SFML/Graphics.hpp>
#include <bits/stl_list.h>
#include "Npc.h"
#include "TextureManager.h"

class EntityManager : public sf::Drawable {
public:
    EntityManager();

    void update(sf::Time frameTime);

    void npcMovement();

    std::vector<sf::FloatRect> getNpcsGlobalBounds();

    void addNpc(sf::Vector2f pos, sf::Vector2f size, std::string texLocation);

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void updateBounds();

    std::vector<Npc> npcList;
    std::vector<sf::FloatRect> npcsBounds;
    TextureManager texture;
};


#endif //RPGGAME_ENTITYMANAGER_H
