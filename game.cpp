//
// Created by Benny Xu on 2024-01-14.
//

#include "game.hpp"
#include <iostream>

#define CORNER_X 90
#define CORNER_Y 80
#define SPACE 150
#define BLOCK 120

game::game() {
    ended = false;
    turn = 1;
}

void game::display_background(sf::RenderWindow *window) {
    sf::Texture white, box;
    if (!white.loadFromFile("../images/white.png")) {
        std::cout << "Could not load texture white" << std::endl;
        exit(-1);
    }
    if (!box.loadFromFile("../images/background.png")) {
        std::cout << "Could not load texture background" << std::endl;
        exit(-1);
    }

    sf::Sprite plain_background, box_background;
    plain_background.setTexture(white);
    box_background.setTexture(box);
    window->draw(plain_background);
    window->draw(box_background);
}

void game::display_board(sf::RenderWindow *window) {
    sf::Texture cross_texture, circle_texture;
    if (!cross_texture.loadFromFile("../images/cross.png")) {
        std::cout << "Could not load texture cross" << std::endl;
        exit(-1);
    }
    if (!circle_texture.loadFromFile("../images/circle.png")) {
        std::cout << "Could not load texture circle" << std::endl;
        exit(-1);
    }
    cross_texture.setSmooth(true);
    circle_texture.setSmooth(true);

    sf::Sprite cross, circle;
    cross.setTexture(cross_texture);
    circle.setTexture(circle_texture);
    cross.setScale(float(120)/600, float(120)/600);
    circle.setScale(float(120)/600, float(120)/600);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tictactoe.get_table(i, j) == 1) {
                cross.setPosition(float(CORNER_X) + float(i) * SPACE, float(CORNER_Y) + float(j) * SPACE);
                window->draw(cross);
            }
            if (tictactoe.get_table(i, j) == 2) {
                circle.setPosition(float(CORNER_X) + float(i) * SPACE, float(CORNER_Y) + float(j) * SPACE);
                window->draw(circle);
            }
        }
    }

    if (tictactoe.check_diagonal() != -1 || tictactoe.check_horizontal() != -1 || tictactoe.check_vertical() != -1) {
        ended = true;
        display_result(window);
    }
}

void game::update(int x, int y) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((CORNER_X + i * SPACE <= x && CORNER_X + i * SPACE + BLOCK >= x) &&
                (CORNER_Y + j * SPACE <= y && CORNER_Y + j * SPACE + BLOCK >= y) &&
                tictactoe.get_table(i, j) == 0) {
                tictactoe.update(turn, i, j);
                turn = turn % 2 + 1;
                return;
            }
        }
    }
}

bool game::isEnded() const {
    return ended;
}

void game::display_result(sf::RenderWindow *window) {
    sf::Texture texture;
    sf::Sprite sprite;
    if (tictactoe.check_diagonal() != -1) {
        texture.loadFromFile("../images/diagonal_" + std::to_string(tictactoe.check_diagonal()) + ".png");
        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setPosition(CORNER_X - 10, CORNER_Y - 10);
        window->draw(sprite);
        return;
    }
    else if (tictactoe.check_horizontal() != -1) {
        texture.loadFromFile("../images/horizontal.png");
        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setPosition(CORNER_X - 15, CORNER_Y + 48 + tictactoe.check_horizontal() * SPACE);
        window->draw(sprite);
    }
    else if (tictactoe.check_vertical() != -1) {
        texture.loadFromFile("../images/vertical.png");
        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setPosition(CORNER_X + 47.5 + tictactoe.check_vertical() * SPACE, CORNER_Y - 10);
        window->draw(sprite);
    }
}

void game::reset() {
    ended = false;
    turn = 1;
    tictactoe.reset();
}