//
// Created by Benny Xu on 2024-01-14.
//

#include "board.h"

board::board() {
    for (auto & i : table) {
        for (auto & j : i) {
            j = 0;
        }
    }
}

bool board::update(int player, int x, int y) {
    if (table[x][y] != 0) {
        return false;
    }
    table[x][y] = player;
    return true;
}

int board::get_table(int x, int y) const {
    return table[x][y];
}

int board::check_vertical() const {
    for (int i = 0; i < 3; ++i) {
        if (table[i][0] != 0 && table[i][0] == table[i][1] && table[i][1] == table[i][2]) {
            return i;
        }
    }
    return -1;
}

int board::check_horizontal() const {
    for (int i = 0; i < 3; ++i) {
        if (table[0][i] != 0 && table[0][i] == table[1][i] && table[1][i] == table[2][i]) {
            return i;
        }
    }
    return -1;
}

int board::check_diagonal() const {
    if (table[1][1] != 0) {
        if (table[0][0] == table[1][1] && table[1][1] == table[2][2]) {
            return 1;
        }
        if (table[0][2] == table[1][1] && table[1][1] == table[2][0]) {
            return 2;
        }
    }
    return -1;
}

void board::reset() {
    for (auto & i : table) {
        for (auto & j : i) {
            j = 0;
        }
    }
}