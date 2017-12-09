//
// Created by peto184 on 27-Oct-17.
//

#ifndef PPGSO_MAP_H
#define PPGSO_MAP_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Map {
public:
    enum Tile {
        PLAYER = 'S',
        ENEMY = 'E',
        AIR = '-',
        BLOCK = '=',
        FINISH = 'F'
    };

    int mapHeight;
    int mapWidth;

    std::vector<std::vector<enum Tile> > map;

    string filepath;

    explicit Map(const std::string& filepath);

    void loadMap(const std::string& filepath);
};


#endif //PPGSO_MAP_H
