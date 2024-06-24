#include "Map.h"
#include <cmath>

Map::Map(const std::vector<std::vector<Tile>> &data) : mapTiles(data.size())
{

}

void Map::Draw()
{

}

Vector2 Map::GetPositionToIndex(Vector2 position)
{
	float x = std::floor(asfloat(position.x / TILE_SIZE));
	float y = std::floor(asfloat(position.y / TILE_SIZE));
	return Vector2 {x,y};
}

