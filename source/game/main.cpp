#include <raylib.h>

int main()
{
    InitWindow(1280, 720, "Ghost Alien Game");
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}