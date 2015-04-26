#include "Level.h"
#include <fstream>
#include <iostream>
#include "Parser.h"

Level::Level() {

}

void Level::LoadLevel(std::string lev) {
    txml::XMLDocument doc;
    doc.LoadFile("untitled.tmx");
    txml::XMLElement *root = doc.FirstChildElement("map");

    root->QueryAttribute("width", &width);
    root->QueryAttribute("height", &height);

    playerPos.x = 0;// Pixels
    playerPos.y = -16;

    //Terrain
    txml::XMLElement *data = root->FirstChildElement("layer")->FirstChildElement("data");
    const char *a = data->GetText();
    char *str = (char *) a;
    char *pch = strtok(str, " ,.-");

    while (pch != NULL) {
        int i;
        i = atoi(pch);
        terrain.push_back(i - 1);
        pch = strtok(NULL, " ,");
    }

    //Second Layer
    data = root->FirstChildElement("layer")->NextSiblingElement("layer");
    std::string check = data->Attribute("name");
    if (check == "SecondLayer") {
        data = data->FirstChildElement("data");
        a = data->GetText();
        str = (char *) a;
        pch = strtok(str, " ,.-");

        while (pch != NULL) {
            int i;
            i = atoi(pch);
            secondLayer.push_back(i - 1);
            pch = strtok(NULL, " ,");
        }
    }

    //Solid objects list
    std::vector<int> solidObjectsList;

    txml::XMLElement *solidObj = root->FirstChildElement("tileset")->FirstChildElement("tile");
    while (solidObj != nullptr) {
        check = solidObj->FirstChildElement("properties")->FirstChildElement("property")->Attribute(
                "value");
        if (check == "Solid") {
            int val;
            solidObj->QueryAttribute("id", &val);
            std::cout << val << ' ';
            solidObjectsList.push_back(val);
        }
        solidObj = solidObj->NextSiblingElement("tile");
    }

    solidObjects.resize((unsigned long) (width * height));

    for (int i = 0; i < terrain.size(); i++) {
        solidObjects[i] = false;
        for (int j = 0; j < solidObjectsList.size(); j++) {
            if (terrain[i] == solidObjectsList[j]) {
                solidObjects[i] = true;
                break;
            }
        }
    }

    for (int i = 0; i < secondLayer.size(); i++) {
        for (int j = 0; j < solidObjectsList.size(); j++) {
            if (secondLayer[i] == solidObjectsList[j]) {
                solidObjects[i] = true;
                break;
            }
        }
    }

    solidObjectsList.clear();
}

std::vector<int> Level::getTerrain() {
    return terrain;
}

std::vector<int> Level::getSecondLayer() {
    return secondLayer;
}

sf::Vector2f Level::getPlayerPosition() {
    return playerPos;
}

std::vector<bool> Level::getSolidObjectsList() {
    return solidObjects;
}

sf::Vector2f Level::getSize() {
    return sf::Vector2f(width, height);
}

