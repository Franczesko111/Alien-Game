#include <game/Player.hpp>

Player::Player()
{
    x = 0;
    y = 0;
    spr.source = {0, 0, 16, 16};
    spr.origin = {0, 0};
}

/* PUBLIC */
void Player::Draw()
{
    DrawTexturePro(_G::Texture::player_texture, spr.source, spr.dest, spr.origin, 0.0f, WHITE);
}

void Player::Update()
{
    x += (IsKeyDown(KeyboardKey::KEY_D) - IsKeyDown(KeyboardKey::KEY_A)) * 5;
    y += (IsKeyDown(KeyboardKey::KEY_S) - IsKeyDown(KeyboardKey::KEY_W)) * 5;
    Spritesheet();
}

/* PRIVATE */
void Player::Spritesheet()
{
    spr.dest = {(float)x, (float)y, spr.source.width, spr.source.height};
}