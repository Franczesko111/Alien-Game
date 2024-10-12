#include <game/Game.hpp>

int main()
{
    InitWindow(1280, 720, "Ghost Alien Game");
    SetTargetFPS(60);

    _G::LoadTextures();
    Game game;

    while(!WindowShouldClose())
    {
        BeginDrawing();

            game.Draw();

            ClearBackground(LIGHTGRAY);

            game.Update();

        EndDrawing();
    }

    _G::UnloadTextures();
    CloseWindow();
    return 0;
}