#include "Engine.h"
#include "Fps.h"

Engine::Engine() {

}

bool Engine::Init() {
    std::shared_ptr<sf::RenderWindow> initWindow(new sf::RenderWindow(sf::VideoMode(800, 600, 32), "RPG"));
    window = initWindow;

    level.LoadLevel("level");
    map.Load("Resources/tileset.png", sf::Vector2u(32, 32), level.map, level.width, level.height);

    player.Init(level.playerPos, sf::Vector2f(32, 32), "Resources/avatar.png");
    entities.Init();

    playerView.reset(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    playerView.setCenter(player.getPixelPosition());

    return !!window;
}

void Engine::RenderFrame() {
    window->clear(sf::Color(64, 164, 223));///Don't forget to add a color
    window->draw(map);
    window->draw(entities);
    window->draw(player);
    window->display();
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
            player.Execute(event.key.code, level);
        }
        if (event.type == sf::Event::KeyReleased) {
            player.Stop();
        }
    }
}

void Engine::Update() {
    player.Update();

    playerView.setCenter(player.getPixelPosition());
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
