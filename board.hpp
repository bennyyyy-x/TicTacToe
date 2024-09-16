//
// Created by Benny Xu on 2024-01-14.
//

#ifndef TICTACTOE_BOARD_HPP
#define TICTACTOE_BOARD_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class board {
private:
    int table[3][3]{}; // 0 = empty, 1 = player1, 2 = player2
public:
    board();
    bool update(int player, int x, int y);
    int get_table(int x, int y) const;

    int check_horizontal() const;
    int check_vertical() const;
    int check_diagonal() const;

    void reset();
};


#endif //TICTACTOE_BOARD_HPP
