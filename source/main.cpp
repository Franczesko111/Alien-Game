#include <game/Game.hpp>

int main()
{
    InitWindow(_G::GAME_WIDTH, _G::GAME_HEIGHT, _G::GAME_TITLE);
    SetTargetFPS(_G::GAME_FPS);

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