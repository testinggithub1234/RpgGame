#include "Engine.h"
#include "Fps.h"

Engine::Engine() {

}

bool Engine::Init() {
    std::shared_ptr<sf::RenderWindow> initWindow(
            new sf::RenderWindow(sf::VideoMode(800, 600, 32), "RPG"));

    window = initWindow;
    window->setVerticalSyncEnabled(false);
    window->setFramerateLimit(0);

    level.LoadLevel("level");
    terrain.Load("Resources/tileset.png", sf::Vector2u(32, 32), level.getTerrain(), level.getSize().x, level.getSize().y,
                 window->getView());

    player.init(level.getPlayerPosition(), sf::Vector2f(32, 32), "Resources/player.png");
    entities.Init();

    // entities.addNpc(sf::Vector2f(3, 0), sf::Vector2f(32, 32), "Resources/policeNPC.png");

    playerView.reset(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    playerView.setCenter(player.getPixelPosition());

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
    frameTime = frameClock.restart();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down) or
        sf::Keyboard::isKeyPressed(sf::Keyboard::Left) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.execute();
    }
    else {
        player.stop();
    }
    if (collision.isPlayerColliding(player.getPosition(), player.getDestination(),
                                    sf::Vector2f(level.getSize().x, level.getSize().y),
                                    level.getSolidObjectsList())) {
        player.undoMovement();
    }
    player.movement();
    showFps();
}

void Engine::Update() {
    player.update(frameTime);
    entities.Update();

    playerView.setCenter(player.getPixelPosition());
    window->setView(playerView);
}

void Engine::RenderFrame() {
    window->clear(sf::Color(64, 164, 223));///Don't forget to add a color
    window->draw(terrain);
    window->draw(entities);
    window->draw(player);
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
