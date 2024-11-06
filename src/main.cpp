#include "Game.hpp"

#include <raylib.h>

int main()
{
  InitWindow(800, 600, "MAM");
  InitAudioDevice(); 
  
  SetTargetFPS(60); 

  Game game;
  LoadAllTextures();

  while (!WindowShouldClose())
  {
    game.update();
  }

  UnloadAllTextures();
  CloseAudioDevice();
  CloseWindow();
}