#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "game.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "TicTacToe", sf::Style::Default);

    game ttt;

    while (window.isOpen()) {
        window.clear();
        game::display_background(&window);
        ttt.display_board(&window);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonReleased && !ttt.isEnded()) {
                ttt.update(sf::Mouse::getPosition(window).x,
                           sf::Mouse::getPosition(window).y);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                ttt.reset();
            }
        }
        window.display();
    }

    return 0;
}
