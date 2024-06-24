#pragma once
#include "Settings.h"
#include "Map.h"

class Golfball
{
private:
	Vector2 position;
	Vector2 direction;
	Vector2 dragDirection;

	float const radius;
	float velocity;

	bool selected;

public:
	Golfball(Vector2 position);

	void Draw();

	void Update();

	void CheckCollision(Map &map);

private:
	void DragBall();
	void Bounce(const Tile &tile);

};

