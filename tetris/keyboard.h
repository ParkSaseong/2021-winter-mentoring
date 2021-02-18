#ifndef KEYBOARD_H
#define KEYBOARD_H

int get_key();

typedef enum {
    KEY_UP = 279165,
    KEY_DOWN = 279166,
    KEY_RIGHT = 279167,
    KEY_LEFT = 279168,
} KEY_INPUT;

int get_key(void);

#endif /* KEYBOARD_H */