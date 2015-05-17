#ifndef RPGGAME_LEVELLOADER_H
#define RPGGAME_LEVELLOADER_H

#include <string>
#include <SFML/System/Thread.hpp>
#include <memory>
#include "../Map/Level.h"
#include "EntityManager.h"

class LevelLoader {
public:
    LevelLoader() : thread(&LevelLoader::LoadLevel, this) {

    }
    void start();

    void setData(Level &level, EntityManager &entities);

    void setLevel(std::string level);

    bool isLevelLoading();

private:
    void LoadLevel();

    std::string levelData;
    sf::Thread thread;
    bool isLoading;

    Level *level;
    EntityManager *entities;
};


#endif //RPGGAME_LEVELLOADER_H
