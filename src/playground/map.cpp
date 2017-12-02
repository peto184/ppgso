//
// Created by peto184 on 27-Oct-17.
//

#include "map.h"

using namespace std;

Map::Map(const string& filepath) {
    loadMap(filepath);
}

void Map::loadMap(const string& filepath) {
    ifstream tileMap;
    tileMap.open(filepath);

    string line;
    if (tileMap.is_open()){
        tileMap >> mapHeight >> mapWidth;

        char t;
        for (unsigned long long int i = 0; i < mapHeight; i++){
            map.emplace_back(vector<Tile>());
            for (int j = 0; j < mapWidth; j++){
                tileMap >> t;
                switch (t){
                    case '-':
                        map.at(i).emplace_back(Map::Tile::AIR);
                        break;
                    case '=':
                        map.at(i).emplace_back(Map::Tile::BLOCK);
                        break;
                    case 'S':
                        map.at(i).emplace_back(Map::Tile::PLAYER);
                        break;
                    case 'F':
                        map.at(i).emplace_back(Map::Tile::FINISH);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    // Print map to std out
    for (auto v : map){
        for (auto w : v){
            switch (w){
                case Map::Tile::AIR:
                    cout << "-";
                    break;
                case Map::Tile::BLOCK:
                    cout << "=";
                    break;
                case Map::Tile::PLAYER:
                    cout << "S";
                    break;
                case Map::Tile::FINISH:
                    cout << "F";
                    break;
                default:
                    cout << "?";
                    break;
            }
        }
        cout << endl;
    }

}
