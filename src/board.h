#ifndef BOARD_H
#define BOARD_H

#include "bb.h"

#define WHITE 0x00
#define BLACK 0x10

#define EMPTY 0x00
#define PAWN 0x01
#define KNIGHT 0x02
#define BISHOP 0x03
#define ROOK 0x04
#define QUEEN 0x05
#define KING 0x06

#define WHITE_PAWN 0x01
#define WHITE_KNIGHT 0x02
#define WHITE_BISHOP 0x03
#define WHITE_ROOK 0x04
#define WHITE_QUEEN 0x05
#define WHITE_KING 0x06

#define BLACK_PAWN 0x11
#define BLACK_KNIGHT 0x12
#define BLACK_BISHOP 0x13
#define BLACK_ROOK 0x14
#define BLACK_QUEEN 0x15
#define BLACK_KING 0x16

#define PIECE(x) ((x) & 0x0f)
#define COLOR(x) ((x) & 0x10)

#define CASTLE_ALL 15
#define CASTLE_WHITE 3
#define CASTLE_BLACK 12
#define CASTLE_WHITE_KING 1
#define CASTLE_WHITE_QUEEN 2
#define CASTLE_BLACK_KING 4
#define CASTLE_BLACK_QUEEN 8

typedef struct {
    int squares[64];
    int color;
    int castle;
    bb ep;
    bb all;
    bb white;
    bb black;
    bb white_pawns;
    bb black_pawns;
    bb white_knights;
    bb black_knights;
    bb white_bishops;
    bb black_bishops;
    bb white_rooks;
    bb black_rooks;
    bb white_queens;
    bb black_queens;
    bb white_kings;
    bb black_kings;
} Board;

void board_clear(Board *board);
void board_reset(Board *board);
void board_set(Board *board, int sq, int piece);
void board_print(Board *board);
void board_load_fen(Board *board, char *fen);

#endif
