#include "Engine.h"
#include "Fps.h"

Engine::Engine() {

}

bool Engine::Init() {
    std::shared_ptr<sf::RenderWindow> initWindow(new sf::RenderWindow(sf::VideoMode(800, 600, 32), "RPG"));

    window = initWindow;
    level.LoadLevel("level");
    map.Load("Resources/tileset.png", sf::Vector2u(32, 32), level.map, level.width, level.height);

    player.Init(level.playerPos);
    playerView.reset(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    playerView.setCenter(player.getPosition());

    return !!window;
}

void Engine::RenderFrame() {
    window->clear();
    window->draw(map);
    window->draw(player);
    window->display();
    showFps();
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
            player.Execute(event.key.code);
        }
    }
}

void Engine::Update() {
    player.Update();

    playerView.setCenter(player.getPosition());
    window->setView(playerView);
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
