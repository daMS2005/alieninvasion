#include "Player.hpp"
#include "Projectile.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// Function to display the menu
void displayMenu() {
    std::cout << "===================================\n";
    std::cout << "            SPACE INVADERS         \n";
    std::cout << "===================================\n\n";
    std::cout << "Welcome to Space Invaders!\n";
    std::cout << "---------------------------------\n";
    std::cout << "Press 'P' to Play Space Invaders!\n";
    std::cout << "Press 'Q' to Quit.\n";
}

int main() {
    // Display the menu
    displayMenu();

    char choice;
    std::cin >> choice;

    if (choice == 'Q' || choice == 'q') {
        std::cout << "Exiting Space Invaders. Goodbye!\n";
        return 0;
    } else if (choice != 'P' && choice != 'p') {
        std::cout << "Invalid choice. Exiting.\n";
        return 0;
    }

    return 0;
}

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
