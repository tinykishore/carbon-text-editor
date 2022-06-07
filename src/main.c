//
// Created by tinykishore on 6/7/22.
//

#include <unistd.h>

int main() {
    int c;
    while (read(STDERR_FILENO, &c, 1) == 1 && c != 'q');
    return 0;
}