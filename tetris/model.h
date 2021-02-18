#ifndef MODEL_H
#define MODEL_H

#define BOARD_HEIGHT 20
#define BOARD_WIDTH 10
#define BLOCK_LEN 4
#define BLOCK_SIZE 16
#define BLOCK_NUM 6

#include "queue.h"

typedef struct {
    int board[BOARD_HEIGHT][BOARD_WIDTH];
    int block[4][4];
    int hold_block[4][4];
    
    queue *next_block_queue;
} tetris;

tetris *tetris_alloc(void);

void tetris_free(tetris *this);

void tetris_needs_new_block(tetris *this);

void tetris_update_board(tetris *this, int board[BOARD_HEIGHT][BOARD_WIDTH]);

void tetris_get_board(tetris *this, int board[BOARD_HEIGHT][BOARD_WIDTH]);

void tetris_get_block(tetris *this, int block[4][4]);

void tetris_get_next_block(tetris *this, int next_block[4][4]);

void tetris_get_hold_block(tetris *this, int hold_block[4][4]);

#endif /* MODEL_H */
