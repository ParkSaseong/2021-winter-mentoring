#ifndef VIEW_H
#define VIEW_H

/**
 * board를 화면에 출력해준다.
 */
void render_board(int board[20][10]);

/**
 * 다음 블록을 출력해준다.
 */
void render_next_block(int block[4][4]);

/**
 * 홀드 하고 있는 블록을 출력한다.
 */
void render_hold_block(int block[4][4]);

#endif /* VIEW_H */
