#include "Alien.hpp"
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Alien");
    Alien alien(sf::Vector2f(400.0f, 300.0f)); // Center of the screen

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black); // Solid black background
        alien.render(window);          // Render single alien
        window.display();
    }

    return 0;
}
