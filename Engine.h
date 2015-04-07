#ifndef RPGGAME_ENGINE_H
#define RPGGAME_ENGINE_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Level.h"
#include "Player.h"
#include "EntityManager.h"

class Engine {
public:
    Engine();

    void Go();

private:
    std::shared_ptr<sf::RenderWindow> window;

    bool Init();

    void MainLoop();

    void RenderFrame();

    void ProcessInput();

    void Update();

    Player player;

    EntityManager entities;

    TileMap map;

    Level level;

    sf::View playerView;

};

#endif //RPGGAME_ENGINE_H
