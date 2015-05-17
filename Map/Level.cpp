#include "Level.h"
#include <fstream>
#include <iostream>
#include "../Utilities/Parser.h"

Level::Level() {
   // terrain = Terrain("Resources/map.png");
}

void Level::LoadLevel(char *lev) {
    txml::XMLDocument doc;
    doc.LoadFile(lev);
    txml::XMLElement *root = doc.FirstChildElement("map");

    root->QueryAttribute("width", &width);
    root->QueryAttribute("height", &height);

    playerPos.x = 0;// Pixels
    playerPos.y = 48;

    txml::XMLElement *pListElement = root->FirstChildElement("layer");
    std::vector<std::vector<int> > layerList;
    std::vector<int> vec;

    while (pListElement != nullptr) {
        txml::XMLElement *data = pListElement->FirstChildElement("data");
        std::string check = pListElement->Attribute("name");

        const char *a = data->GetText();
        char *str = (char *) a;
        char *pch = strtok(str, " ,.-");
        vec.clear();
        while (pch != NULL) {
            int i;
            i = atoi(pch);
            vec.push_back(i - 1);
            pch = strtok(NULL, " ,");
        }
        layerList.push_back(vec);
        TileMap tile;
        tile.load("Resources/tileset.png", sf::Vector2u(32, 32), vec, width, height);

        if (check == "under") {
            underPlayer.push_back(tile);
        }
        else if (check == "over") {
            overPlayer.push_back(tile);
        }

        pListElement = pListElement->NextSiblingElement("layer");
    }

    std::vector<int> solidObjectsList;

    txml::XMLElement *solidObj = root->FirstChildElement("tileset")->FirstChildElement("tile");
    while (solidObj != nullptr) {
        std::string check = solidObj->FirstChildElement("properties")->FirstChildElement("property")->Attribute(
                "value");
        if (check == "Solid") {
            int val;
            solidObj->QueryAttribute("id", &val);
            solidObjectsList.push_back(val);
        }
        solidObj = solidObj->NextSiblingElement("tile");
    }

    solidObjects.resize((unsigned long) (width * height));
    for (int i = 0; i < solidObjects.size(); i++) {
        solidObjects[i] = false;
    }

    for (int i = 0; i < solidObjectsList.size(); i++) {
        for (int j = 0; j < layerList.size(); j++) {
            for (int k = 0; k < layerList[j].size(); k++) {
                if (layerList[j][k] == solidObjectsList[i]) {
                    solidObjects[k] = true;
                }
            }
        }
    }
}

sf::Vector2f Level::getPlayerPosition() {
    return playerPos;
}

std::vector<bool> Level::getSolidObjectsList() {
    return solidObjects;
}

std::vector<Portal> Level::getPortals() {
    return portals;
}

sf::Vector2f Level::getSize() {
    return sf::Vector2f(width, height);
}

void Level::updateView(sf::View view) {
    terrain.setView(view);
}

void Level::draw(sf::RenderTarget &target, sf::RenderStates states) const {
   // target.draw(terrain);
    for (int i = 0; i < underPlayer.size(); i++) {
        target.draw(underPlayer[i]);
    }
}

void Level::drawOver(sf::RenderWindow &target) {
    for (int i = 0; i < overPlayer.size(); i++) {
        target.draw(overPlayer[i]);
    }
}

