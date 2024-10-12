#pragma once
#include <raylib.h>

typedef short               int8;
typedef unsigned short      uint8;
typedef int                 int16;
typedef unsigned int        uint16;
typedef long                int32;
typedef unsigned long       uint32;
typedef long long           int64;
typedef unsigned long long  uint64;

namespace _G
{
    inline constexpr int GAME_WIDTH = 320;
    inline constexpr int GAME_HEIGHT = 180;
    inline constexpr int GAME_FPS = 60;
    inline const char* GAME_TITLE = "Ghost Alien Game";

    inline Font font;


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
    inline void LoadData()
    {
        Texture::player_texture = LoadTexture("assets/images/alien-ss.png");

        Image font_image = LoadImage("assets/fonts/Munro.ttf");
        ImageFormat(&font_image, PIXELFORMAT_UNCOMPRESSED_GRAYSCALE);
        font = LoadFontFromImage(font_image, {255, 255, 255, 255}, 0);
        SetTextureFilter(font.texture, TEXTURE_FILTER_POINT);
        UnloadImage(font_image);
    };

    inline void UnloadData()
    {
        UnloadTexture(Texture::player_texture);

        UnloadFont(font);
    };
};