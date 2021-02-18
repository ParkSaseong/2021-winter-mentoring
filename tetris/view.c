#include "view.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char view_blocks[][4] = {
    " ",
    "□",
    "░",
    "▓",
};

static void move_cursor(int y, int x) {
    printf("\033[%dd\033[%dG", y, x);
}

const int board_by = 4;
const int board_bx = 8;

const int next_block_by = 4;
const int next_block_bx = 30;


/**
 * board를 화면에 출력해준다.
 */
void render_board(int board[20][10]) {
    int dot;

    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 10; x++) {
            move_cursor(board_by + y, board_bx + x * 2);
            dot = board[y][x];
            printf("%s", view_blocks[dot]);
        }
    }
}

void render_next_block(int block[4][4]) {
    int dot;

    for (int y = 0; y < 4; y ++) {
        for (int x = 0; x < 4; x++) {
            move_cursor(next_block_by + y, next_block_bx + x * 2);
            dot = block[y][x];
            printf("%s", view_blocks[dot]);
        }
    }
}
