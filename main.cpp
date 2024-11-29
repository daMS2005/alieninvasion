#include "Player.hpp"
#include "Projectile.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Alien Invasion");
    Player player;

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player.shoot();
        }

        float deltaTime = clock.restart().asSeconds();

        player.handleInput();
        player.update();
        player.updateProjectiles();

        window.clear();
        player.render(window);
        player.renderProjectiles(window);
        window.display();
    }

    return 0;
}
