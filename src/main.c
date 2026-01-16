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
#include <assert.h>
#include <stdio.h>

const float PIECE_SCALE = 0.45f;

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

Vector2 BoardOffset() {
  int offsetX = GetScreenWidth() / 2 - BOARD_WIDTH / 2;
  int offsetY = GetScreenHeight() / 2 - BOARD_WIDTH / 2;

  Vector2 offset = {.x = offsetX, .y = offsetY};

  return offset;
}

void DrawChessboard(TextureStore *store, Board *board) {
  bool isWhite = true;
  Color sqrColor = WHITE;

  Vector2 offset = BoardOffset();

  Vector2 pos = offset;
  Vector2 size = {.x = BOARD_CELL_SIZE, .y = BOARD_CELL_SIZE};

  for (int i = 0; i < board->board_size; i++) {

    if (board->squares[i].isSelected) {
      sqrColor = YELLOW;
    } else {
      sqrColor = isWhite ? WHITE : BLACK;
    }

    DrawRectangleV(pos, size, sqrColor);

    if (board->squares[i].piece.type != EMPTY) {
      Texture pieceTexture = TextureForPiece(store, board->squares[i].piece);
      DrawPiece(pieceTexture, pos);
    }

    isWhite = !isWhite;
    pos.x += BOARD_CELL_SIZE;
    if ((i + 1) % 8 == 0) {
      pos.y += BOARD_CELL_SIZE;
      pos.x = offset.x;
      isWhite = !isWhite;
    }
  }
}

void DrawBackground() {
  Color fromGradient = {.r = 90, .g = 250, .b = 245, .a = 100};
  Color toGradient = {.r = 90, .g = 250, .b = 245, .a = 50};
  DrawRectangleGradientV(0, 0, GetScreenWidth(), GetScreenHeight(), fromGradient, toGradient);
}

void CheckForInput(Board *board) {
  if (IsMouseButtonPressed(0)) {
    Vector2 mouse_pos = GetMousePosition();
    fprintf(stderr, "Mouse click pressed at X:%f Y%f\n", mouse_pos.x, mouse_pos.y);

    Vector2 offset = BoardOffset();

    if ((mouse_pos.x > offset.x && mouse_pos.x < offset.x + BOARD_WIDTH) &&
        (mouse_pos.y > offset.y && mouse_pos.y < offset.y + BOARD_WIDTH)) {
      fprintf(stderr, "Mouse click is on board \n");

      Vector2 local_pos = {.x = mouse_pos.x - offset.x, .y = mouse_pos.y - offset.y};
      fprintf(stderr, "Mouse click is on local cordinates : %f:%f\n", local_pos.x, local_pos.y);
      int x_index = (int)local_pos.x / BOARD_CELL_SIZE;
      int y_index = (int)local_pos.y / BOARD_CELL_SIZE;
      int selected = x_index + y_index * 8;
      fprintf(stderr, "Mouse click is on board row with selected index : %d\n", selected);

      assert(selected < board->board_size);

      for (int i = 0; i < board->board_size; i++) {
        board->squares[i].isSelected = false;
      }
      board->squares[selected].isSelected = true;
    }
  }
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

    CheckForInput(&board);
    DrawChessboard(textureStore, &board);

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
