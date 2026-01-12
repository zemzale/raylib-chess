/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit
https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "board.h"
#include "raylib.h"
#include "texture_loader.h"

const float PIECE_SCALE = 0.45f;
const int BOARD_CELL_SIZE = 64;
const int BOARD_WIDTH = BOARD_CELL_SIZE * 8;

Texture TextureForPiece(TextureStore *store, Piece piece) {
  int index;

  switch (piece.type) {
  case ROOK:
    index = piece.isBlack ? B_ROOK : W_ROOK;
    break;
  case KNIGHT:
    index = piece.isBlack ? B_KNIGHT : W_KNIGHT;
    break;
  case BISHOP:
    index = piece.isBlack ? B_BISHOP : W_BISHOP;
    break;
  case QUEEN:
    index = piece.isBlack ? B_QUEEN : W_QUEEN;
    break;
  case KING:
    index = piece.isBlack ? B_KING : W_KING;
    break;
  case PAWN:
    index = piece.isBlack ? B_PAWN : W_PAWN;
    break;
  default:
    index = 0;
    break;
  }

  return store->textures[index];
}

void DrawPiece(Texture texture, Vector2 pos) {

  int textureOffsetX = (BOARD_CELL_SIZE - texture.width * PIECE_SCALE) / 2;
  int textureOffsetY = (BOARD_CELL_SIZE - texture.height * PIECE_SCALE) / 2;

  pos.x += textureOffsetX;
  pos.y += textureOffsetY;

  DrawTextureEx(texture, pos, 0.0f, PIECE_SCALE, WHITE);
}

void DrawChessboard(TextureStore *store, Board *board) {
  bool isWhite = true;
  Color sqrColor = WHITE;

  int offsetX = GetScreenWidth() / 2 - BOARD_WIDTH / 2;
  int offsetY = GetScreenHeight() / 2 - BOARD_WIDTH / 2;

  Vector2 pos = {.x = BOARD_CELL_SIZE + offsetX, .y = BOARD_CELL_SIZE + offsetY};
  Vector2 size = {.x = BOARD_CELL_SIZE, .y = BOARD_CELL_SIZE};

  for (int i = 0; i < board->board_size; i++) {
    DrawRectangleV(pos, size, isWhite ? WHITE : BLACK);

    if (board->squares[i].piece.type != EMPTY) {
      Texture pieceTexture = TextureForPiece(store, board->squares[i].piece);
      DrawPiece(pieceTexture, pos);
    }

    isWhite = !isWhite;
    pos.x += BOARD_CELL_SIZE;
    if ((i + 1) % 8 == 0) {
      pos.y += BOARD_CELL_SIZE;
      pos.x = BOARD_CELL_SIZE + offsetX;
      isWhite = !isWhite;
    }
  }
}

void DrawBackground() {
  Color fromGradient = {.r = 90, .g = 250, .b = 245, .a = 100};
  Color toGradient = {.r = 90, .g = 250, .b = 245, .a = 50};
  DrawRectangleGradientV(0, 0, GetScreenWidth(), GetScreenHeight(), fromGradient, toGradient);
}

int main() {
  // Tell the window to use vsync and work on high DPI displays
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  // Create the window and OpenGL context
  InitWindow(1920, 1080, "Hello Raylib");

  TextureStore *textureStore = LoadTextures();

  Board board = InitBoard();

  // game loop
  while (!WindowShouldClose()) // run the loop untill the user presses ESCAPE or
                               // presses the Close button on the window
  {
    // drawing
    BeginDrawing();

    // Setup the back buffer for drawing (clear color and depth buffers)
    ClearBackground(BLACK);
    DrawBackground();

    DrawChessboard(textureStore, &board);
    // DrawPieces(textureStore);

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
