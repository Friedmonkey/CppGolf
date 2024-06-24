#include "Map.h"
#include <cmath>

Map::Map(const std::vector<std::vector<int>> &data) : mapTiles(data.size())
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data.at(i).size(); j++)
		{
			int value = data.at(i).at(j);
			bool hasCollision = (value == 1);
			mapTiles.at(i).push_back(Tile(j, i, hasCollision));
		}
	}
}

void Map::Draw()
{
	for(const auto &i : mapTiles)
	{	
		for (const auto &j : i)
		{
			DrawRectangleLinesEx(j.rect, 1.0f, GREEN);
		}
	}
}

Vector2 Map::GetPositionToIndex(Vector2 position)
{
	float x = std::floor(asfloat(position.x / TILE_SIZE));
	float y = std::floor(asfloat(position.y / TILE_SIZE));
	return Vector2 {x,y};
}

const int Map::GetWidth()
{
	return mapTiles.at(0).size();
}

const int Map::GetHeight()
{
	return mapTiles.size();
}

const std::vector<std::vector<Tile>>& Map::GetData()
{
	return mapTiles;
}

const Tile& Map::GetTile(int x, int y)
{
	return mapTiles.at(x).at(y);
}

