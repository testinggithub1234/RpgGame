#ifndef RPGGAME_ENGINE_H
#define RPGGAME_ENGINE_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Level.h"
#include "Player.h"

class Engine {
private:
    std::shared_ptr<sf::RenderWindow> window;

    bool Init();

    void MainLoop();

    void RenderFrame();

    void ProcessInput();

    void Update();

    TileMap map;

    Level level;

    sf::View playerView;

public:
    Engine();

    Player player;

    void Go();
};


#endif //RPGGAME_ENGINE_H
