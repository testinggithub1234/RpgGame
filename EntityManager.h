#ifndef RPGGAME_ENTITYMANAGER_H
#define RPGGAME_ENTITYMANAGER_H


#include <SFML/Graphics.hpp>
#include "Npc.h"
#include "TextureManager.h"

class EntityManager: public sf::Drawable {
public:
    EntityManager();

    std::vector<Npc> npcList;

    void Init();

    void Update();

    void addNpc(sf::Vector2f pos, sf::Vector2f size, std::string texLocation);
private:
    TextureManager texture;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};


#endif //RPGGAME_ENTITYMANAGER_H
