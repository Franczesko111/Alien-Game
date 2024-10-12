#pragma once
#include <global/Global.hpp>

constexpr uint8 PLAYER_SIZE = 16;

class Player
{
    public:
        Player();
        void Draw();
        void Update();
    
    private:
        enum class State
        {
            IDLE,
            MOVING
        };

        _G::Spritesheet spr;
        float timer;

        Player::State state;
        int16 x, y;
        uint8 frame, side, anim;
        int8 dir;
        int8 x_trigger, y_trigger;

        void Spritesheet();
        void Animate(float duration, uint8 start_frame, uint8 end_frame);
        void UpdateAnimData(Player::State state, uint8 anim);
};