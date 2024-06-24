#pragma once
#include <vector>
#include "Tile.h"

class Map
{
private:
	std::vector<std::vector<Tile>> mapTiles;

public:
	Map(const std::vector<std::vector<Tile>> &data);

	void Draw();

	Vector2 GetPositionToIndex(Vector2 position);


};

