#include <iostream>
#include "Settings.h"

#define FUCHSIA CLITERAL(Color){ 255, 0, 255, 255 }   // My own White (raylib logo)

int main()
{
    std::cout << "Hello World!\n";
    InitWindow(SW, SH, "Golf game lol");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(FUCHSIA);


        EndDrawing();
    }
    CloseWindow();
}
