#ifndef TEXTURES_HPP
#define TEXTURES_HPP

/*
access any textures from any file aslong as they are loaded
*/

#include <raylib.h>
#include <string>

const int totalTexture = 3;

Texture2D textures[totalTexture];

void LoadAllTextures()
{
  const char *names[] = {
    "./Graphics/bananes.png",
    "./Graphics/kitty.png",
    "./Graphics/textureGrid.png"
  };

  for(int i = 0; i < totalTexture; i++)
    textures[i] = LoadTexture(names[i]);
}

void UnloadAllTextures()
{
  for(int i = 0; i < totalTexture; i++)
    UnloadTexture(textures[i]);
}

#endif