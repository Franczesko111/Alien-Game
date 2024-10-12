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
        Player *player;
};