#include <game/Player.hpp>

Player::Player()
{
    x = 0;
    y = 0;
}

void Player::Draw()
{
    DrawRectangle(x, y, 16, 16, RED);
}

void Player::Update()
{
    x += (IsKeyDown(KeyboardKey::KEY_D) - IsKeyDown(KeyboardKey::KEY_A)) * 5;
    y += (IsKeyDown(KeyboardKey::KEY_S) - IsKeyDown(KeyboardKey::KEY_W)) * 5;
}