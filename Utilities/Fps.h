#ifndef FPS_H_INCLUDED
#define FPS_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

sf::Clock fpsCounter;
int fpsVar;

void showFps() {
    int elapsedTime = fpsCounter.getElapsedTime().asMilliseconds();

    if (elapsedTime >= 1000) {
        std::cout << fpsVar << "\n";
        fpsCounter.restart();
        fpsVar = 0;
    }
    else
        fpsVar++;
}

#endif // FPS_H_INCLUDED
