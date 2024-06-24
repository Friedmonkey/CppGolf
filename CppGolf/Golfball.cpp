#include "Golfball.h"
#include <RayMath.h>
#include <cmath>

Golfball::Golfball(Vector2 position) :
    position(position),
    dragDirection{0.0f, 0.0f},
    direction{0.0f, 0.0f},
    radius(16.0f),
    velocity(0.0f),
    selected(false)
{
}

void Golfball::Draw()
{
    DrawCircleLinesV(position, radius, GREEN);

    if (selected) //if we have the ball selected, show where its going to go
    {
        float length = Vector2Distance(position, GetMousePosition());
        Vector2 direct = Vector2Multiply(dragDirection, { length, length });
        DrawLineEx(position, Vector2Add(position, direct), 1.0f, GREEN);
    }
}

void Golfball::Update()
{
}

void Golfball::CheckCollision(Map& map)
{
}

void Golfball::Push()
{
    if (CheckCollisionPointCircle(GetMousePosition(), position, radius) && IsMouseButtonPressed(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)))
    {
        //if you click the ball
        selected = true;
    }

    //if you're still holding mouse button down and the ball is selected
    if (IsMouseButtonDown(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) && selected)
    {
        //set the drag to whatever your mouse is
        using namespace std;
        dragDirection.x = cos(atan2(GetMouseY() - position.y, GetMouseX() - position.x)) * -1;
        dragDirection.x = sin(atan2(GetMouseY() - position.y, GetMouseX() - position.x)) * -1;
    }
}

void Golfball::Bounce(const Tile& tile)
{
}
