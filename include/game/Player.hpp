#pragma once
#include <global/Global.hpp>

class Player
{
    public:
        Player();
        void Draw();
        void Update();
    
    private:
        int x, y;
};