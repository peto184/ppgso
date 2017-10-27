//
// Created by peto184 on 27-Oct-17.
//

#ifndef PPGSO_MAP_H
#define PPGSO_MAP_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

class Map {
public:
    enum Tile {
        PLAYER = 'S',
        AIR = '-',
        BLOCK = '='
    };

    int mapHeight;
    int mapWidth;

    std::vector<std::vector<enum Tile> > map;

    explicit Map(const std::string& filepath);

    void loadMap(const std::string& filepath);
};


#endif //PPGSO_MAP_H
