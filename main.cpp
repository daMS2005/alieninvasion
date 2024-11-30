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
    const int scoreThreshold = 100;
    std::set<int> usedPositions; // Prevent aliens from overlapping

    // Load font for score display
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

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
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
                x = rand() % 750; // Generate random x within screen bounds
            } while (usedPositions.count(x)); // Avoid overlapping positions
            usedPositions.insert(x);
            aliens.emplace_back(sf::Vector2f(static_cast<float>(x), 100), 3); // Spawn with 3 health
            spawnClock.restart();
        }

        // Update aliens
        for (auto& alien : aliens) {
            alien.update(deltaTime, scoreThreshold, score); // Pass score to control alien movement
        }

        // Check collisions between projectiles and aliens
        for (auto& alien : aliens) {
            for (auto it = player.getProjectiles().begin(); it != player.getProjectiles().end();) {
                if (it->getBounds().intersects(alien.getBounds())) {
                    alien.takeDamage(1); // Decrease alien health
                    it = player.getProjectiles().erase(it); // Remove projectile
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

        // Render everything
        window.clear(sf::Color::Black);
        for (auto& alien : aliens) {
            alien.render(window); // Render aliens
        }
        player.render(window); // Render player
        player.renderProjectiles(window); // Render projectiles
        window.draw(scoreText); // Render score
        window.display();

        // Remove off-screen aliens
        aliens.erase(
            std::remove_if(aliens.begin(), aliens.end(), [](Alien& alien) {
                return alien.isOffScreen();
            }),
            aliens.end()
        );
    }

    return 0;
}
