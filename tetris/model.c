#include "model.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

const int blocks[][4][4] = {
    {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
    },
    {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
    },
    {
        {0, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
    },
    {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
    },
    {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 1, 1},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
    },
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    },
};

static int rand_number_factory(int max) {
    int ret = rand();

    return ret % max;
}

tetris *tetris_alloc(void) {
    tetris *this = malloc(sizeof(tetris));
    srand(time(NULL));

    for (int y = 0; y < BOARD_HEIGHT; y++) {
        this->board[y][0] = 1;
        this->board[y][BOARD_WIDTH - 1] = 1;
    }

    for (int x = 0; x < BOARD_WIDTH; x++) {
        this->board[0][x] = 1;
        this->board[BOARD_HEIGHT - 1][x] = 1;
    }

    this->next_block_queue = queue_alloc(1024);

    for (int i = 0; i < 1024; i++) {
        queue_enqueue(this->next_block_queue, rand_number_factory(BLOCK_NUM));
    }
    
    return this;
}

void tetris_free(tetris *this) {
    free(this);
}

void tetris_update_board(tetris *this, int board[BOARD_HEIGHT][BOARD_WIDTH]) {
    memcpy(this->board, board, sizeof(int) * BOARD_HEIGHT * BOARD_WIDTH);
}

void tetris_put_block(tetris *this, int block[4][4], int y, int x) {
    for (int i = 0; i < 4; i++)
        memcpy(&this->board[y + i][x], block[i], sizeof(int) * 4);
}

void tetris_get_board(tetris *this, int board[BOARD_HEIGHT][BOARD_WIDTH]) {
    memcpy(board, this->board, sizeof(int) * BOARD_HEIGHT * BOARD_WIDTH);
}

void tetris_get_block(tetris *this, int block[4][4]) {
    memcpy(block, this->block, sizeof(int) * 16);
}

void tetris_get_next_block(tetris *this, int next_block[4][4]) {
    int block_idx = *queue_front(this->next_block_queue);
    memcpy(next_block, blocks[block_idx], sizeof(int) * 16);
}

void tetris_needs_new_block(tetris *this) {
    tetris_get_next_block(this, this->block);
    queue_dequeue(this->next_block_queue);
    queue_enqueue(this->next_block_queue, rand_number_factory(BLOCK_NUM));
}

void tetris_get_hold_block(tetris *this, int hold_block[4][4]) {
    memcpy(hold_block, this->hold_block, sizeof(int) * 16);
}
