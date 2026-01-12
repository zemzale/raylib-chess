/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit
https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"
#include "texture_loader.h"

const float PIECE_SCALE = 0.45f;
const int BOARD_CELL_SIZE = 64;
const int BOARD_WIDTH = BOARD_CELL_SIZE * 8;

void DrawChessboard() {
  bool isWhite = true;
  Color sqrColor = WHITE;
  Vector2 pos = {.x = BOARD_CELL_SIZE, .y = BOARD_CELL_SIZE};
  Vector2 size = {.x = BOARD_CELL_SIZE, .y = BOARD_CELL_SIZE};

  int offsetX = GetScreenWidth() / 2 - BOARD_WIDTH / 2;
  int offsetY = GetScreenHeight() / 2 - BOARD_WIDTH / 2;

  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pos.x = offsetX + (BOARD_CELL_SIZE * x);
      pos.y = offsetY + (BOARD_CELL_SIZE * y);
      DrawRectangleV(pos, size, isWhite ? WHITE : BLACK);
      isWhite = !isWhite;
    }
    isWhite = !isWhite;
  }
}

void DrawBackground() {
  Color fromGradient = {.r = 90, .g = 250, .b = 245, .a = 100};
  Color toGradient = {.r = 90, .g = 250, .b = 245, .a = 50};
  DrawRectangleGradientV(0, 0, GetScreenWidth(), GetScreenHeight(), fromGradient, toGradient);
}

void DrawPiece(Texture texture, Vector2 pos) {

  int textureOffsetX = (BOARD_CELL_SIZE - texture.width * PIECE_SCALE) / 2;
  int textureOffsetY = (BOARD_CELL_SIZE - texture.height * PIECE_SCALE) / 2;

  pos.x += textureOffsetX;
  pos.y += textureOffsetY;

  DrawTextureEx(texture, pos, 0.0f, PIECE_SCALE, WHITE);
}

void DrawPieces(TextureStore *store) {
  int offsetX = GetScreenWidth() / 2 - BOARD_WIDTH / 2;
  int offsetY = GetScreenHeight() / 2 - BOARD_WIDTH / 2;

  Vector2 pos = {.x = offsetX, .y = offsetY};

  DrawPiece(store->textures[W_ROOK], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[W_KNIGHT], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[W_BISHOP], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[W_QUEEN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[W_KING], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[W_BISHOP], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[W_KNIGHT], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[W_ROOK], pos);

  pos.x = offsetX;
  pos.y += BOARD_CELL_SIZE;

  DrawPiece(store->textures[W_PAWN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[W_PAWN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[W_PAWN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[W_PAWN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[W_PAWN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[W_PAWN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[W_PAWN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[W_PAWN], pos);

  pos.x = offsetX;
  pos.y += BOARD_CELL_SIZE * 5;

  DrawPiece(store->textures[B_PAWN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_PAWN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_PAWN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_PAWN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_PAWN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_PAWN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_PAWN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_PAWN], pos);

  pos.x = offsetX;
  pos.y += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_ROOK], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_KNIGHT], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_BISHOP], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_QUEEN], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_KING], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_BISHOP], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_KNIGHT], pos);
  pos.x += BOARD_CELL_SIZE;
  DrawPiece(store->textures[B_ROOK], pos);
}

int main() {
  // Tell the window to use vsync and work on high DPI displays
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  // Create the window and OpenGL context
  InitWindow(1920, 1080, "Hello Raylib");

  TextureStore *textureStore = LoadTextures();

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
    DrawPieces(textureStore);

    // end the frame and get ready for the next one  (display frame, poll input,
    // etc...)
    EndDrawing();
  }

  // cleanup
  // unload our texture so it can be cleaned up
  UnloadTextures(textureStore);

  // destroy the window and cleanup the OpenGL context
  CloseWindow();
  return 0;
}
