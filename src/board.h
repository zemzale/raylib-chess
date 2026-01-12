#include <stdbool.h>
#include <stddef.h>

typedef enum {
  EMPTY,
  ROOK,
  KNIGHT,
  BISHOP,
  QUEEN,
  KING,
  PAWN,
} PieceType;

typedef struct {
  PieceType type;
  bool isBlack;
} Piece;

typedef struct {
  bool isSelected;
  Piece piece;

} Square;

typedef struct {
  Square squares[64];
  size_t board_size;
} Board;

Board InitBoard() {
  Board board = {.board_size = 64,
                 .squares = {
                     {.piece = {.isBlack = true, .type = ROOK}},
                     {.piece = {.isBlack = true, .type = KNIGHT}},
                     {.piece = {.isBlack = true, .type = BISHOP}},
                     {.piece = {.isBlack = true, .type = KING}},
                     {.piece = {.isBlack = true, .type = QUEEN}},
                     {.piece = {.isBlack = true, .type = BISHOP}},
                     {.piece = {.isBlack = true, .type = KNIGHT}},
                     {.piece = {.isBlack = true, .type = ROOK}},
                     {.piece = {.isBlack = true, .type = PAWN}},
                     {.piece = {.isBlack = true, .type = PAWN}},
                     {.piece = {.isBlack = true, .type = PAWN}},
                     {.piece = {.isBlack = true, .type = PAWN}},
                     {.piece = {.isBlack = true, .type = PAWN}},
                     {.piece = {.isBlack = true, .type = PAWN}},
                     {.piece = {.isBlack = true, .type = PAWN}},
                     {.piece = {.isBlack = true, .type = PAWN}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.type = EMPTY}},
                     {.piece = {.isBlack = false, .type = PAWN}},
                     {.piece = {.isBlack = false, .type = PAWN}},
                     {.piece = {.isBlack = false, .type = PAWN}},
                     {.piece = {.isBlack = false, .type = PAWN}},
                     {.piece = {.isBlack = false, .type = PAWN}},
                     {.piece = {.isBlack = false, .type = PAWN}},
                     {.piece = {.isBlack = false, .type = PAWN}},
                     {.piece = {.isBlack = false, .type = PAWN}},
                     {.piece = {.isBlack = false, .type = ROOK}},
                     {.piece = {.isBlack = false, .type = KNIGHT}},
                     {.piece = {.isBlack = false, .type = BISHOP}},
                     {.piece = {.isBlack = false, .type = KING}},
                     {.piece = {.isBlack = false, .type = QUEEN}},
                     {.piece = {.isBlack = false, .type = BISHOP}},
                     {.piece = {.isBlack = false, .type = KNIGHT}},
                     {.piece = {.isBlack = false, .type = ROOK}},
                 }};

  return board;
}
