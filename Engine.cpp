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

    char *a = "untitled2.tmx";

    level.LoadLevel(a);

    Collision collision;
    collision.loadData(level.getSize(), level.getSolidObjectsList());

    entities.loadData(collision, level.getSize());


    playerView.reset(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    playerView.setCenter(entities.player.getPixelPosition());

    level.updateView(playerView);

    entities.addNpc(sf::Vector2f(1, 1), sf::Vector2f(32, 48), "Resources/player.png");
    entities.addNpc(sf::Vector2f(2, 1), sf::Vector2f(32, 48), "Resources/player.png");
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
        ProcessInput();
        Update();
        RenderFrame();
    }
}

void Engine::Go() {
    if (!Init()) {
        throw "Could not initialize Engine";
    }
    MainLoop();
}