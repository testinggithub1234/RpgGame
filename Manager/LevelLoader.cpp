#include <string.h>
#include "LevelLoader.h"

sf::Mutex mutex;

void LevelLoader::LoadLevel() {
    mutex.lock();

    isLoading = true;
    char *a;
    a = new char[levelData.length() + 1];

    strcpy(a, levelData.c_str());

    level->LoadLevel(a);

    delete[] a;

    Collision collision;
    collision.loadData(level->getSize(), level->getSolidObjectsList());

    entities->loadData(collision, level->getSize());

    entities->addNpc(sf::Vector2f(1, 1), sf::Vector2f(32, 48), "Resources/player.png");
    entities->addNpc(sf::Vector2f(2, 1), sf::Vector2f(32, 48), "Resources/player.png");

    entities->player.setPosition(level->getPlayerPosition());

    isLoading = false;

    mutex.unlock();
}

void LevelLoader::setLevel(std::string level) {
    this->levelData = level;
}

bool LevelLoader::isLevelLoading() {
    return isLoading;
}

void LevelLoader::setData(Level &level, EntityManager &entities) {
    this->level = &level;
    this->entities = &entities;
}

void LevelLoader::start() {
    thread.launch();
}
