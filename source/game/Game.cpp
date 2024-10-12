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
    DrawFPS(10, 10);
}

void Game::Update()
{
    player->Update();

    if(IsKeyPressed(KeyboardKey::KEY_F)) ToggleBorderlessWindowed();
}