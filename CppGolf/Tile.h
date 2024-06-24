#pragma once

#include "Settings.h"

struct Tile {
    const int xIndex, yIndex;
    const Rectangle rect;
    const bool collidable;

    Tile(int index_x, int index_y, bool collidable) :
        xIndex(index_x), yIndex(index_y),
        rect{ asfloat(index_x * TILE_SIZE), asfloat(index_y * TILE_SIZE), asfloat(TILE_SIZE), asfloat(TILE_SIZE) },
        collidable(collidable)
    {

    }
};