#ifndef RPGGAME_ENTITYMANAGER_H
#define RPGGAME_ENTITYMANAGER_H

#include <SFML/Graphics.hpp>
#include <bits/stl_list.h>
#include "TextureManager.h"
#include "../Collision/Collision.h"
#include "../Player/Player.h"
#include "../Map/Npc/Npc.h"

class EntityManager : public sf::Drawable {
public:
    EntityManager();

    void loadData(Collision collision, sf::Vector2f size);

    void update(sf::Time frameTime);

    void npcMovement();

    std::vector<sf::FloatRect> getNpcsGlobalBounds();

    void addNpc(sf::Vector2f pos, sf::Vector2f size, std::string texLocation);

    void playerExecute();

    Player player;

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void updateBounds();

    void updateDrawOrder();

    void updatePlayerOrder();

    int playerDrawOrder = 0;
    Collision collision;
    sf::Vector2f levelSize;
    std::vector<Npc> npcList;
    std::vector<sf::FloatRect> npcsBounds;
    TextureManager texture;
};


#endif //RPGGAME_ENTITYMANAGER_H
