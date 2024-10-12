#pragma once
#include <raylib.h>

namespace _G
{
    namespace Texture
    {
        inline Texture2D player_texture;
    };

    inline void LoadTextures()
    {
        Texture::player_texture = LoadTexture("assets/images/cubert.png");
    };

    inline void UnloadTextures()
    {
        UnloadTexture(Texture::player_texture);
    };
};