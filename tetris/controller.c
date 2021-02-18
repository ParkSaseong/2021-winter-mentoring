#include "keyboard.h"
#include "view.h"
#include "model.h"
#include <stdio.h>



int main() {
    int key;
    tetris *model = tetris_alloc();
    int board[BOARD_HEIGHT][BOARD_WIDTH];
    int block[BLOCK_LEN][BLOCK_LEN];
    int next_block[BLOCK_LEN][BLOCK_LEN];
    int hold_block[BLOCK_LEN][BLOCK_LEN];

    while (1) {
        tetris_get_board(model, board);
        tetris_get_block(model, block);
        tetris_get_next_block(model, next_block);
        tetris_get_hold_block(model, hold_block);
        
        key = get_key();
        switch (key)
        {
        case KEY_UP:
            break;
        case KEY_DOWN:
            break;
        case KEY_LEFT:
            break;
        case KEY_RIGHT:
            break;
        default:
            break;
        }
        tetris_update_board(model, board);
        render_board(model->board);
        render_next_block(model->block);

        tetris_needs_new_block(model);
    }

    tetris_free(model);
}
