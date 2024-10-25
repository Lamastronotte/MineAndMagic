#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>

#include "Utils.hpp"
#include "Textures.hpp"

class Game {
public:

  Game() { init(); }

  void init() {

  }

  void update() {
    draw();
  }

  void draw() {
    BeginDrawing();

    EndDrawing();
  }
};

#endif