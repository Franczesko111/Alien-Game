#pragma once
#include <game/Player.hpp>

class Game
{
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
    
    private:
        RenderTexture render_texture = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
        Player *player;
};