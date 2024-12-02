#include "Player.hpp"
#include "Projectile.hpp"
#include "Alien.hpp"
#include "GameState.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <algorithm>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Alien Invasion");
    GameState currentState = GameState::StartMenu;

    Player player;
    std::vector<Alien> aliens;
    sf::Clock spawnClock;
    sf::Clock clock;
    sf::Clock scoreClock;
    int score = 0;
    bool isGameOver = false;
    bool initialSetup = true;

    // Load font
    sf::Font font;
    if (!font.loadFromFile("resources/retrofont.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }

    // Menu UI elements
    sf::Text title("Alien Invasion", font, 50);
    title.setPosition(200, 50);

    sf::Text playButton("Play Game", font, 30);
    playButton.setPosition(300, 150);

    sf::Text skinButton("Change Skins", font, 30);
    skinButton.setPosition(300, 250);

    sf::Text leaderboardButton("Leaderboard", font, 30);
    leaderboardButton.setPosition(300, 350);

    sf::Text quitButton("Quit", font, 30);
    quitButton.setPosition(300, 450);

    // Score text
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.0f, 10.0f);

    // Leaderboard elements
    sf::Text leaderboardTitle("Leaderboard", font, 40);
    leaderboardTitle.setPosition(200, 50);
    sf::Text backButton("Back", font, 30);
    backButton.setPosition(300, 500);

    // Skin selection UI
    sf::Sprite skin1, skin2, skin3;
    sf::Texture skinTexture1, skinTexture2, skinTexture3;
    if (!skinTexture1.loadFromFile("resources/skin1.png") ||
        !skinTexture2.loadFromFile("resources/skin2.png") ||
        !skinTexture3.loadFromFile("resources/skin3.png")) {
        std::cerr << "Error loading skin textures\n";
        return -1;
    }
    skin1.setTexture(skinTexture1);
    skin2.setTexture(skinTexture2);
    skin3.setTexture(skinTexture3);
    skin1.setPosition(200, 200);
    skin2.setPosition(350, 200);
    skin3.setPosition(500, 200);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (currentState == GameState::StartMenu && event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (playButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    currentState = GameState::Gameplay;
                    spawnClock.restart(); // Reset spawn clock
                    aliens.clear();       // Clear any existing aliens
                    score = 0;            // Reset score
                    isGameOver = false;   // Reset game state
                    initialSetup = true;  // Allow initial alien setup
                }
                if (skinButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    currentState = GameState::SkinSelection;
                }
                if (leaderboardButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    currentState = GameState::Leaderboard;
                }
                if (quitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    window.close();
                }
            }

            if (currentState == GameState::SkinSelection && event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (skin1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    player.setSkin("resources/skin1.png");
                    currentState = GameState::StartMenu;
                }
                if (skin2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    player.setSkin("resources/skin2.png");
                    currentState = GameState::StartMenu;
                }
                if (skin3.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    player.setSkin("resources/skin3.png");
                    currentState = GameState::StartMenu;
                }
            }

            if (currentState == GameState::Leaderboard && event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    currentState = GameState::StartMenu;
                }
            }
        }

        window.clear();

        if (currentState == GameState::StartMenu) {
            window.draw(title);
            window.draw(playButton);
            window.draw(skinButton);
            window.draw(leaderboardButton);
            window.draw(quitButton);
        } else if (currentState == GameState::Gameplay) {
            float deltaTime = clock.restart().asSeconds();

            if (isGameOver) {
                // Handle game over logic
                continue;
            }

            // Handle player input and updates
            player.handleInput(deltaTime);
            player.update();
            player.updateProjectiles(deltaTime);

            // Spawn initial row of aliens (once)
            if (initialSetup) {
                for (int i = 0; i < 10; ++i) {
                    AlienType type = (i % 2 == 0) ? AlienType::Blue : AlienType::Yellow; // Alternate alien types
                    aliens.emplace_back(sf::Vector2f(50.0f + i * 70.0f, 100.0f), type);


                }
                initialSetup = false;
            }

            // Spawn new aliens periodically
            if (spawnClock.getElapsedTime().asSeconds() > 2.0f) {
                float x = static_cast<float>(rand() % 750); // Random x position
                AlienType type = (rand() % 2 == 0) ? AlienType::Blue : AlienType::Yellow; // Randomize alien type
                aliens.emplace_back(sf::Vector2f(x, -50), type, 3); // Position, type, health

                spawnClock.restart();                      // Restart the spawn clock
            }

            // Update aliens
            // Update aliens
// Update aliens
for (auto& alien : aliens) {
    alien.update(deltaTime, 100, score); // Update alien position and logic
}

// Handle player health when aliens go offscreen or touch the player
for (auto it = aliens.begin(); it != aliens.end();) {
    if (it->isOffScreen()) { 
        player.takeDamage(10); // Player loses 10 health for offscreen aliens
        it = aliens.erase(it); // Remove the offscreen alien
    } else if (it->getBounds().intersects(player.getBounds())) { 
        player.takeDamage(20); // Player loses 20 health for collision
        it = aliens.erase(it); // Remove the alien after collision
    } else {
        ++it; // Move to the next alien
    }
}

// Collision detection between projectiles and aliens
for (auto& alien : aliens) { // Check collisions for all aliens
    for (auto it = player.getProjectiles().begin(); it != player.getProjectiles().end();) {
        if (it->getBounds().intersects(alien.getBounds())) { // Collision detected
            alien.takeDamage(1);              // Reduce alien health
            if (alien.isDead()) {
                score += 100;                 // Increase score if alien is dead
            }
            it = player.getProjectiles().erase(it); // Remove the projectile after collision
        } else {
            ++it; // Move to the next projectile
        }
    }
}

// Remove dead aliens
aliens.erase(
    std::remove_if(aliens.begin(), aliens.end(), [](Alien& alien) {
        return alien.isDead(); // Remove aliens whose health is 0 or below
    }),
    aliens.end()
);

// Render game elements
for (auto& alien : aliens) {
    alien.render(window); // Render remaining aliens
}
player.render(window);            // Render the player
player.renderProjectiles(window); // Render projectiles
player.renderHealthBar(window);   // Render the health bar

// Update and render score
scoreText.setString("Score: " + std::to_string(score));
window.draw(scoreText);



        } else if (currentState == GameState::SkinSelection) {
            sf::Text skinTitle("Select Your Skin", font, 40);
            skinTitle.setPosition(200, 50);
            window.draw(skinTitle);
            window.draw(skin1);
            window.draw(skin2);
            window.draw(skin3);
        } else if (currentState == GameState::Leaderboard) {
            window.clear(sf::Color::Black);
            window.draw(leaderboardTitle);

            std::vector<int> scores;
            std::ifstream file("leaderboard.txt");
            std::string line;

            if (file.is_open()) {
                while (std::getline(file, line)) {
                    if (line == "Top Score:") continue;
                    try {
                        int score = std::stoi(line);
                        scores.push_back(score);
                    } catch (...) {
                        std::cerr << "Error parsing score: " << line << std::endl;
                    }
                }
                file.close();
                std::sort(scores.rbegin(), scores.rend());

                if (scores.empty()) {
                    sf::Text noScoresText("No scores available.", font, 30);
                    noScoresText.setPosition(200, 200);
                    window.draw(noScoresText);
                } else {
                    int y = 150;
                    for (size_t i = 0; i < std::min(scores.size(), size_t(10)); ++i) {
                        sf::Text scoreText(std::to_string(i + 1) + ". " + std::to_string(scores[i]), font, 30);
                        scoreText.setPosition(200, y);
                        window.draw(scoreText);
                        y += 40;
                    }
                }
            }

            window.draw(backButton);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    currentState = GameState::StartMenu;
                }
            }
        }

        window.display();
    }

    return 0;
}
