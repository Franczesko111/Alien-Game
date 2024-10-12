#include <game/Game.hpp>

Game::Game()
{
    player = new Player;
}

Game::~Game()
{
    delete player;
}

void Game::Draw()
{
    player->Draw();
    DrawTextEx(_G::font, TextFormat("FPS: %i", GetFPS()), {4, 3}, 10, 1, GREEN);
}

void Game::Update()
{
    player->Update();

    if(IsKeyPressed(KeyboardKey::KEY_F)) ToggleBorderlessWindowed();
}