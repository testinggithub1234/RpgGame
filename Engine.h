#ifndef RPGGAME_ENGINE_H
#define RPGGAME_ENGINE_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "Manager/TextureManager.h"
#include "Manager/EntityManager.h"
#include "Map/Level.h"
#include "Manager/LevelLoader.h"

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

    TextureManager texture;

    EntityManager entities;

    Level level;

    LevelLoader levelLoader;

    sf::View playerView;

    sf::Clock frameClock;

    sf::Time frameTime;
};

#endif //RPGGAME_ENGINE_H
