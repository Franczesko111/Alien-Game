#include <raylib.h>
#include <all/ALL.hpp>

int main()
{
    InitWindow(1280, 720, "Alien Game");
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