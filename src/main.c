/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit
https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"

#include "resource_dir.h" // utility header for SearchAndSetResourceDir
//
const int BOARD_WIDTH = 64 * 8;

void DrawChessboard() {
  bool isWhite = true;
  Color sqrColor = WHITE;
  Vector2 pos = {.x = 64, .y = 64};
  Vector2 size = {.x = 64, .y = 64};

  int offsetX = GetScreenWidth() / 2 - BOARD_WIDTH / 2;
  int offsetY = GetScreenHeight() / 2 - BOARD_WIDTH / 2;

  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pos.x = offsetX + (64 * x);
      pos.y = offsetY + (64 * y);
      DrawRectangleV(pos, size, isWhite ? WHITE : BLACK);
      isWhite = !isWhite;
    }
    isWhite = !isWhite;
  }
}

void DrawBackground() {
    Color fromGradient = { .r = 90, .g = 250, .b = 245, .a = 100 };
    Color toGradient = { .r = 90, .g = 250, .b = 245, .a = 50 };
    DrawRectangleGradientV(0, 0, GetScreenWidth(), GetScreenHeight(), fromGradient, toGradient);
}

int main() {
  // Tell the window to use vsync and work on high DPI displays
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  // Create the window and OpenGL context
  InitWindow(1280, 800, "Hello Raylib");

  // Utility function from resource_dir.h to find the resources folder and set
  // it as the current working directory so we can load from it
  SearchAndSetResourceDir("resources");

  // Load a texture from the resources directory
  Texture wabbit = LoadTexture("wabbit_alpha.png");

  // game loop
  while (!WindowShouldClose()) // run the loop untill the user presses ESCAPE or
                               // presses the Close button on the window
  {
    // drawing
    BeginDrawing();

    // Setup the back buffer for drawing (clear color and depth buffers)
    ClearBackground(BLACK);
    DrawBackground();

    DrawChessboard();

    // end the frame and get ready for the next one  (display frame, poll input,
    // etc...)
    EndDrawing();
  }

  // cleanup
  // unload our texture so it can be cleaned up
  UnloadTexture(wabbit);

  // destroy the window and cleanup the OpenGL context
  CloseWindow();
  return 0;
}
