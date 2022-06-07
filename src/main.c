//
// Created by tinykishore on 6/7/22.
//

#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

struct termios original;

void disableRawMode() {
    tcsetattr(STDERR_FILENO, TCSAFLUSH, &original);
}

void enableRawMode() {
    tcgetattr(STDERR_FILENO, &original);
    atexit(disableRawMode);
    struct termios raw = original;
    raw.c_lflag &= ~(ECHO);
    tcsetattr(STDERR_FILENO, TCSAFLUSH, &raw);
}

int main() {
    enableRawMode();

    int c;
    while (read(STDERR_FILENO, &c, 1) == 1 && c != 'q');
    return 0;
}