//
// Created by Benny Xu on 2024-01-14.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include <SFML/Graphics.hpp>
#include "board.h"

class game {
private:
    bool ended;
    int turn;
    board tictactoe;
    void display_result(sf::RenderWindow *window);

public:
    game();
    static void display_background(sf::RenderWindow *window);
    void display_board(sf::RenderWindow *window);
    void update(int x, int y);
    bool isEnded() const;
    void reset();
};


#endif //TICTACTOE_GAME_H
