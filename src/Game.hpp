#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>

#include "Utils.hpp"
#include "Textures.hpp"
#include "TileMap.hpp"

#include <string>

class Game {
public:

  Game() { init(); }

  void init();

  void update();

  void draw();

  void updateCamera();

public:

  Camera2D camera;
  Vector2 cameraPos;
  TileMap tilemap; // background
  int* tileGrid;

};

void Game::init()
{
  camera = {0};
  cameraPos = {0.f, 0.f};
  camera.target = cameraPos;
  camera.offset = {Utils::screenSize.x / 2.f, Utils::screenSize.y / 2.f};
  camera.rotation = 0.f;
  camera.zoom = 1.f;

  tilemap.generate(tileGrid, {15, 25}, 3);
}

void Game::update()
{
  updateCamera();
  draw();
}

void Game::draw()
{
  BeginDrawing();
  {

    ClearBackground(BLACK);

    BeginMode2D(camera);
    {
      tilemap.draw({100, 100}, textures[2]);
    }
    EndMode2D();

    // GUI DRAWING

    Vector2 mousePos = GetMousePosition();

    auto msg = std::to_string(mousePos.x) + ", " + std::to_string(mousePos.y);
    DrawText(msg.c_str(), 50, 50, 20, WHITE);

    msg = std::to_string(IsCursorOnScreen());
    DrawText(msg.c_str(), 50, 75, 20, WHITE);
  }
  EndDrawing();
}

void Game::updateCamera()
{
  camera.target = cameraPos;
  camera.zoom += ((float)GetMouseWheelMove() * 0.05f);

  Vector2 vel = {0, 0};
  float speed = 5.f;

  if (IsKeyDown(KEY_W))
    vel.y = -speed;
  if (IsKeyDown(KEY_S))
    vel.y = speed;
  if (IsKeyDown(KEY_A))
    vel.x = -speed;
  if (IsKeyDown(KEY_D))
    vel.x = speed;

  Vector2 mousePos = GetMousePosition();

  if(CheckCollisionPointRec(mousePos, {0, 0, Utils::screenSize.x, 10})) // TOP
    vel.y = -speed;

  if (CheckCollisionPointRec(mousePos, {0, Utils::screenSize.y - 10, Utils::screenSize.x, Utils::screenSize.y})) // BOT
    vel.y = speed;

  if (CheckCollisionPointRec(mousePos, {0, 0, 10, Utils::screenSize.y})) // LEFT
    vel.x = -speed;

  if (CheckCollisionPointRec(mousePos, {Utils::screenSize.x - 10, 0, Utils::screenSize.x, Utils::screenSize.y})) // BOT
    vel.x = speed;

  cameraPos.x += vel.x;
  cameraPos.y += vel.y;
}

#endif