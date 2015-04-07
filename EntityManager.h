#ifndef RPGGAME_ENTITYMANAGER_H
#define RPGGAME_ENTITYMANAGER_H


#include <SFML/Graphics.hpp>
#include "Npc.h"

class EntityManager: public sf::Drawable {
public:
    EntityManager();
    void Init();
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    std::vector<Npc> npcs;

};


#endif //RPGGAME_ENTITYMANAGER_H
