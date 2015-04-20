#include "Level.h"
#include <fstream>
#include <iostream>

void Level::LoadLevel(std::string lev) {
    std::ifstream readLevel("Data/" + lev + ".dat");
    readLevel >> width >> height;

    map.resize(width * height);
    for (int i = 0; i < width * height; i++) {
        readLevel >> map[i];
    }

    readLevel >> playerPos.x >> playerPos.y;
    playerPos.x *= 32;// Pixels
    playerPos.y *= 32;

    std::vector<int> solidObjectsList;

    while (!readLevel.eof()) {
        int var;
        readLevel >> var;
        solidObjectsList.push_back(var);
    }
/*
    solidObjects.resize(width * height);

    for (int i = 0; i < width * height; i++) {
        solidObjects[i] = false;
        for (int j = 0; j < solidObjectsList.size(); j++) {
            if (map[i] == solidObjectsList[j]) {
                solidObjects[i] = true;
                break;
            }
        }
    }

    solidObjectsList.clear();*/
}

