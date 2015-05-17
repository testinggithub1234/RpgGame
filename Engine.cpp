#include <string.h>
#include "Engine.h"
#include "Utilities/Fps.h"

Engine::Engine() {

}

bool Engine::Init() {
    std::shared_ptr<sf::RenderWindow> initWindow(
            new sf::RenderWindow(sf::VideoMode(800, 600, 32), "RPG"));

    window = initWindow;
    window->setVerticalSyncEnabled(false);
    window->setFramerateLimit(120);

    playerView.reset(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));

    levelLoader.setData(level, entities);

    levelLoader.setLevel("untitled2.tmx");

    levelLoader.start();

    return !!window;
}

void Engine::ProcessInput() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window->close();
            }
        }
    }
    entities.playerExecute();
    entities.npcMovement();
    showFps();
}

void Engine::Update() {
    frameTime = frameClock.restart();
    entities.update(frameTime);

    window->setView(window->getDefaultView());
    playerView.setCenter(entities.player.getPixelPosition());
    window->setView(playerView);
    if (entities.player.isMoving()) {
       level.updateView(playerView);
    }
}

void Engine::RenderFrame() {
        window->clear(sf::Color(64, 164, 223));///Don't forget to add a color
        window->draw(level);
        window->draw(entities);
        level.drawOver(*window);
        window->display();
}

void Engine::MainLoop() {
    while (window->isOpen()) {
        if(!levelLoader.isLevelLoading()) {
            ProcessInput();
            Update();
            RenderFrame();
        }else{
            //renderloadingscreen
        }
    }
}

void Engine::Go() {
    if (!Init()) {
        throw "Could not initialize Engine";
    }
    MainLoop();
}
