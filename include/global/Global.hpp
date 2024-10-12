#pragma once
#include <raylib.h>

namespace _G
{
    inline constexpr int GAME_WIDTH = 320;
    inline constexpr int GAME_HEIGHT = 180;
    inline constexpr int GAME_FPS = 60;
    inline const char* GAME_TITLE = "Ghost Alien Game";


    /* Premade variables/classes to use */
    struct Spritesheet
    {
        Rectangle source;
        Rectangle dest;
        Vector2 origin;
    };


    /* Special namespaces for textures, sounds, etc. */
    namespace Texture
    {
        inline Texture2D player_texture;
    };


    /* Functions to load, unload data (textures, sounds, etc.) */
    inline void LoadTextures()
    {
        Texture::player_texture = LoadTexture("assets/images/cubert.png");
    };

    inline void UnloadTextures()
    {
        UnloadTexture(Texture::player_texture);
    };
};