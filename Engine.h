#ifndef RPGGAME_ENGINE_H
#define RPGGAME_ENGINE_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Player.h"
#include "EntityManager.h"
#include "Collision.h"
#include "TileMap.h"

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

    TileMap terrain;

    TileMap secondLayer;

    Level level;

    Collision collision;

    sf::View playerView;

    sf::Clock frameClock;

    sf::Time frameTime;
};

#endif //RPGGAME_ENGINE_H
