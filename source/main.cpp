#include <game/Game.hpp>

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(_G::GAME_WIDTH, _G::GAME_HEIGHT, _G::GAME_TITLE);
    SetTargetFPS(_G::GAME_FPS);

    _G::LoadData();
    Game game;
    RenderTexture render_texture = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());

    while(!WindowShouldClose())
    {
        BeginTextureMode(render_texture);
            game.Update();

            ClearBackground(LIGHTGRAY);

            game.Draw();
        EndTextureMode();

        BeginDrawing();
            DrawTexturePro(
                render_texture.texture,
                Rectangle{ 0, 0, static_cast<float>(render_texture.texture.width), static_cast<float>(-render_texture.texture.height) },
                Rectangle{ 0, 0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) },
                Vector2{ 0, 0 },
                0,
                WHITE);
        EndDrawing();
    }

    UnloadRenderTexture(render_texture);
    _G::UnloadData();
    CloseWindow();
    return 0;
}