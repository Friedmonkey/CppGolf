#pragma once
#include <vector>
#include "Tile.h"

class Map
{
private:
	std::vector<std::vector<Tile>> mapTiles;

public:
	Map(const std::vector<std::vector<int>> &data);

	void Draw();

	Vector2 GetPositionToIndex(Vector2 position);

	const int GetWidth();
	const int GetHeight();

	const std::vector<std::vector<Tile>> &GetData();
	const Tile &GetTile(int x, int y);
};

