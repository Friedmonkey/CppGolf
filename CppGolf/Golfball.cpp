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
    DragBall();


    //slowly decrese the velocity using linear interpolation
    velocity = Lerp(velocity, 0.0f, 2.0f * GetFrameTime());

    Vector2 direct = Vector2Multiply(direction, { velocity , velocity });

    //smoothly update the position using linear interpolation
    position = Vector2Lerp(position, Vector2Add(position, direct), GetFrameTime());
}

void Golfball::CheckCollision(Map& map)
{
    for (int y = -1; y <= 1; y++) 
    {
        if (y == 0) continue;

        for (int x = -1; x <= 1; x++) 
        {
            if (x == 0) continue;

            //get the index
            const Vector2 index = map.GetPositionToIndex(position);

            //get the tile
            const Tile &tile = map.GetTile(index.x + x,index.y + y);

            //if we collide with this tile
            if (CheckCollisionCircleRec(position, radius, tile.rect))
            {
                Bounce(tile);
            }
        }
    }
}

void Golfball::DragBall()
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
        dragDirection.x = cos(atan2(GetMouseY() - position.y, GetMouseX() - position.x)) * -1;
        dragDirection.x = sin(atan2(GetMouseY() - position.y, GetMouseX() - position.x)) * -1;
    }

    //if you let go of the selected ball
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && selected)
    {
        //apply whatever we calculate to the golfball
        direction = dragDirection;
        velocity = Clamp(Vector2Distance(GetMousePosition(), position), -256, 256) * 4.0;
        selected = false;
    }
}

void Golfball::Bounce(const Tile& tile)
{

}
