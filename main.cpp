#include "Player.hpp"
#include "Projectile.hpp"
#include "Alien.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <set>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Alien Invasion");
    Player player;
    std::vector<Alien> aliens;
    sf::Clock spawnClock;
    sf::Clock clock;
    sf::Clock scoreClock;
    int score = 0;
    bool isGameOver = false; // Track if the game is over
    std::set<int> usedPositions;

    // Load font for text
    sf::Font font;
    if (!font.loadFromFile("resources/arial.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }

    // Create score text
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.0f, 10.0f);

    // Create Game Over text
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("Game Over!");
    gameOverText.setPosition(300.0f, 250.0f); // Centered in the window

    // Create Restart text
    sf::Text restartText;
    restartText.setFont(font);
    restartText.setCharacterSize(24);
    restartText.setFillColor(sf::Color::White);
    restartText.setString("Press R to Restart or Esc to Quit");
    restartText.setPosition(220.0f, 320.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Check for game over state
        if (isGameOver) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                // Restart the game
                player = Player(); // Reset the player
                aliens.clear();    // Clear all aliens
                score = 0;         // Reset score
                isGameOver = false;
                spawnClock.restart();
                clock.restart();
                scoreClock.restart();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                // Quit the game
                window.close();
            }

            // Render Game Over screen
            window.clear(sf::Color::Black);
            window.draw(gameOverText);
            window.draw(restartText);
            window.display();
            continue; // Skip the rest of the loop
        }

        // Calculate delta time
        float deltaTime = clock.restart().asSeconds();

        // Handle player input and update state
        player.handleInput(deltaTime);
        player.update();
        player.updateProjectiles(deltaTime);

        // Increment score over time
        if (scoreClock.getElapsedTime().asSeconds() > 1.0f) {
            score += 10; // Add 10 points every second
            scoreClock.restart();
        }

        scoreText.setString("Score: " + std::to_string(score));

        // Spawn new aliens periodically
        if (spawnClock.getElapsedTime().asSeconds() > 2.0f) {
            int x;
            do {
                x = rand() % 750;
            } while (usedPositions.count(x));
            usedPositions.insert(x);
            Alien::AlienType type;
            int randType = rand() % 3; // Random number between 0 and 2
            if (randType == 0) {
                type = Alien::AlienType::Blue;
            } else if (randType == 1) {
                type = Alien::AlienType::Green;
            } else {
                type = Alien::AlienType::Yellow;
            }

            aliens.emplace_back(sf::Vector2f(static_cast<float>(x), 100), 3, type);

            spawnClock.restart();
        }

        // Update aliens
        for (auto& alien : aliens) {
            alien.update(deltaTime, 100, score);
        }
        
        // Check collisions between projectiles and aliens
        for (auto& alien : aliens) {
            for (auto it = player.getProjectiles().begin(); it != player.getProjectiles().end();) {
                if (it->getBounds().intersects(alien.getBounds())) {
                    alien.takeDamage(1);
                    it = player.getProjectiles().erase(it);
                } else {
                    ++it;
                }
            }
        }

        // Remove dead aliens
        aliens.erase(
            std::remove_if(aliens.begin(), aliens.end(), [](Alien& alien) {
                return alien.isDead();
            }),
            aliens.end()
        );

        // Check for off-screen aliens and apply damage
        for (auto it = aliens.begin(); it != aliens.end();) {
            if (it->isOffScreen()) {
                player.takeDamage(10);
                it = aliens.erase(it);
            } else {
                ++it;
            }
        }

        // Check if the player's health is zero
        if (player.getHealth() <= 0) {
            isGameOver = true;
            continue;
        }

        // Render everything
        window.clear(sf::Color::Black);
        for (auto& alien : aliens) {
            alien.render(window);
        }
        player.render(window);
        player.renderProjectiles(window);
        player.renderHealthBar(window);
        window.draw(scoreText);
        window.display();


    }


    return 0;
}
