#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <raylib.h>
#include "rlgl.h"

#include "Textures.hpp"
#include "Utils.hpp"

#include <fstream>
#include <ostream>
#include <sstream>
#include <string>

// CHECK OUT FOR https://www.raylib.com/examples/models/loader.html?name=models_rlgl_solar_system

// generate
class TileMap {
public:
  int* grid;
  Vector2* vertices;
  Vector2* texCoords;
  Utils::Size size;

  void generate(int* data, Utils::Size gridSize, int textureNum); // textureNum is the number of textures in the texture grid
  void regen(); // remakes the textures of all tiles
  void genFromFile(const char* filePath); // generate the tilemap from the file

  void draw(Utils::Size tileSize, Texture2D texture);
};

void TileMap::generate(int *data, Utils::Size gridSize, int textureNum) {

  size.x = gridSize.x;
  size.y = gridSize.y;

  vertices = new Vector2[int(size.x * size.y * 4)];
  texCoords = new Vector2[int(size.x * size.y * 4)];

  float coord_offset = 1.f / textureNum;
  
  int index = 0;

  for(int x = 0; x < size.x; x++)
  {
    for(int y = 0; y < size.y; y++)
    {
      texCoords[index + 0] = {coord_offset * data[int(x + y * size.y)]               , 0.f};
      texCoords[index + 1] = {coord_offset * data[int(x + y * size.y)]               , 1.f};
      texCoords[index + 2] = {coord_offset * data[int(x + y * size.y)] + coord_offset, 1.f};
      texCoords[index + 3] = {coord_offset * data[int(x + y * size.y)] + coord_offset, 0.f};

      vertices [index + 0] = {0.f + x, 0.f + y};
      vertices [index + 1] = {0.f + x, 1.f + y};
      vertices [index + 2] = {1.f + x, 1.f + y};
      vertices [index + 3] = {1.f + x, 0.f + y};

      index += 4;
    }
  }
}

void TileMap::regen()
{
  delete texCoords;
  texCoords = new Vector2[int(size.x * size.y * 4)];

  int index = 0;

  for(int x = 0; x < size.x; x++)
  {
    for(int y = 0; y < size.y; y++)
    {
      texCoords[index + 0] = {0.f, 0.f};
      texCoords[index + 1] = {0.f, 1.f};
      texCoords[index + 2] = {1.f, 1.f};
      texCoords[index + 3] = {1.f, 0.f};

      index += 4;
    }
  }
}

void TileMap::draw(Utils::Size tileSize, Texture2D texture)
{
  // rlgl things to be more efficient
  // TODO: add vao, vbo, ebo stuff

  rlSetTexture(texture.id);

  rlBegin(RL_QUADS);

  for(int i = 0; i < size.x * size.y * 4; i++) {
    rlTexCoord2f(texCoords[i].x, texCoords[i].y);
    rlVertex2f(vertices[i].x * tileSize.x, vertices[i].y * tileSize.y);
  }

  rlEnd();
}

void TileMap::genFromFile(const char* filePath)
{
  
}

#endif