#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include "utility.h"


#define WALLCHAR '#'
#define FLOORCHAR ' '
#define DOORCHAR '+'
#define GOLDCHAR '*'
#define WEAPONCHAR '?'
#define HEALTHPOTIONCHAR '^'
#define WINDOWSIZE_X 800 // in px
#define WINDOWSIZE_Y 600 // in px

class RogueMap {
private:
    // map size
    int mapHeight;
    int mapWidth;

    // pointer to the map
    char* map;

public:
    RogueMap();
    ~RogueMap();

    void loadMap(int width, int height);

    // Get the character at position xy on the map 
    char getXY(int x, int y);

    // Set the character at position xy on the map 
    bool setXY(int x, int y, char value);

    // Print the map at an offset
    void printMap();
};