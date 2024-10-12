#include <game/Player.hpp>

Player::Player()
{
    x = 0;
    y = 0;
    spr.origin = {0, 0};
    dir = 1;
}

/* PUBLIC */
void Player::Draw()
{
    DrawTexturePro(_G::Texture::player_texture, spr.source, spr.dest, spr.origin, 0.0f, WHITE);
}

void Player::Update()
{
    x_trigger = IsKeyDown(KeyboardKey::KEY_D) - IsKeyDown(KeyboardKey::KEY_A);
    y_trigger = IsKeyDown(KeyboardKey::KEY_S) - IsKeyDown(KeyboardKey::KEY_W);
    x += x_trigger * 2;
    y += y_trigger * 2;

    if(x_trigger == 1)          { side = 4; dir = 1; }
    else if(x_trigger == -1)    { side = 4; dir = -1; }
    else if(y_trigger == -1)    { side = 2; dir = 1; }
    else                        { side = 0; dir = 1; }

    if(x_trigger != 0 || y_trigger != 0) {
        UpdateAnimData(Player::State::MOVING, 1);
    }
    else {
        UpdateAnimData(Player::State::IDLE, 0);
    }

    switch(state)
    {
        case Player::State::MOVING: { Animate(0.3f, 0, 2); break; }
        default: { Animate(0.6f, 0, 2); break; }
    }

    Spritesheet();
}

/* PRIVATE */
void Player::Spritesheet()
{
    spr.source = {(float)PLAYER_SIZE * (frame + side), (float)PLAYER_SIZE * anim, (float)PLAYER_SIZE * dir, PLAYER_SIZE};
    spr.dest = {(float)x, (float)y, spr.source.width * dir, spr.source.height};
}

void Player::Animate(float duration, uint8 start_frame, uint8 end_frame)
{
    if(timer == 0.0f) {
        timer = duration;
        frame = start_frame;
    }

    timer -= GetFrameTime();
    if(timer < 0.0f) {
        timer = duration;
        frame++;
        if(frame == end_frame) frame = start_frame;
    }
}

void Player::UpdateAnimData(Player::State state, uint8 anim)
{
    if(this->state != state) {
        this->anim = anim;
        timer = 0.0f;
        this->state = state;
    }
}