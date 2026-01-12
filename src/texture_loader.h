#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include "raylib.h"
#include "resource_dir.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  W_PAWN,
  W_KING,
  W_QUEEN,
  W_ROOK,
  W_BISHOP,
  W_KNIGHT,
  B_PAWN,
  B_KING,
  B_QUEEN,
  B_ROOK,
  B_BISHOP,
  B_KNIGHT,
} TextureName;

typedef struct {
  Texture textures[12];
} TextureStore;

const char *TextureNameMap[12] = {
    "w_pawn_png_128px.png",   "w_king_png_128px.png",   "w_queen_png_128px.png",  "w_rook_png_128px.png",
    "w_bishop_png_128px.png", "w_knight_png_128px.png", "b_pawn_png_128px.png",   "b_king_png_128px.png",
    "b_queen_png_128px.png",  "b_rook_png_128px.png",   "b_bishop_png_128px.png", "b_knight_png_128px.png",
};

TextureStore *LoadTextures() {
  // Utility function from resource_dir.h to find the resources folder and set
  // it as the current working directory so we can load from it
  SearchAndSetResourceDir("resources");

  fprintf(stderr, "Loading textures\n");
  TextureStore *store = malloc(sizeof(TextureStore));

  for (int i = 0; i < 12; i++) {
    const char *name = TextureNameMap[i];
    fprintf(stderr, "Loading texture with index %d, and name %s\n", i, name);
    store->textures[i] = LoadTexture(name);
  }

  return store;
}

void UnloadTextures(TextureStore *store) {
  for (int i = 0; i <= 12; i++) {
    UnloadTexture(store->textures[i]);
  }
  free(store);
}

#endif
