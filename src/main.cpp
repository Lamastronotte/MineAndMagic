#include "Game.hpp"

#include <raylib.h>

int main()
{
  InitWindow(800, 600, "MAM");
  InitAudioDevice(); 

  SetTargetFPS(60); 

  Game game;
  Texturemanager.init();

  while (!WindowShouldClose())
  {
    game.update();
  }

  Texturemanager.destroy();
  CloseAudioDevice();
  CloseWindow();
}