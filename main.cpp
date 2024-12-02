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
#include <SFML/Audio.hpp> 

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
    sf::Music bgMusic;
    if (!bgMusic.openFromFile("resources/bgmusic.ogg")) {
        std::cerr << "Error loading background music\n";
        return -1;
    }
    bgMusic.setLoop(true);  // Loop the music
    bgMusic.play();  
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
            // HEREEEEEEEEEEEEEEEEEEEE
        } else if (currentState == GameState::Gameplay) {
    float deltaTime = clock.restart().asSeconds();

    if (isGameOver || player.getHealth() <= 0) {
        // Add score to the leaderboard
        std::ofstream file("leaderboard.txt", std::ios::app);
        if (file.is_open()) {
            file << score << "\n";
            file.close();
        } else {
            std::cerr << "Error opening leaderboard.txt for writing\n";
        }

        // Display Game Over screen
        sf::Text gameOverText("Game Over!", font, 48);
        gameOverText.setFillColor(sf::Color::Red);
        gameOverText.setPosition(200, 250);

        sf::Text restartText("Press R to Restart or ESC to Quit", font, 24);
        restartText.setFillColor(sf::Color::White);
        restartText.setPosition(150, 320);

        sf::Text menuText("Press M to Return to Menu", font, 24);
        menuText.setFillColor(sf::Color::White);
        menuText.setPosition(200, 360);

        window.clear(sf::Color::Black);
        window.draw(gameOverText);
        window.draw(restartText);
        window.draw(menuText);
        window.display();

        // Handle user input for Game Over options
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            currentState = GameState::Gameplay; // Restart game
            aliens.clear();                     // Clear aliens
            score = 0;                          // Reset score
            player = Player();                  // Reset player
            spawnClock.restart();               // Restart spawn clock
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
            currentState = GameState::StartMenu; // Go back to menu
            aliens.clear();                      // Clear aliens
            score = 0;                           // Reset score
            player = Player();                   // Reset player
            spawnClock.restart();                // Restart spawn clock
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close(); // Quit the game
        }

        return 0; // Skip further game logic if game over
    }

    // Normal game logic here...
    player.handleInput(deltaTime);
    player.update();
    player.updateProjectiles(deltaTime);

    for (auto& alien : aliens) {
        alien.update(deltaTime, 100, score);
    }
    // Spawn new aliens
    for (auto& alien : aliens) {
        for (auto it = player.getProjectiles().begin(); it != player.getProjectiles().end();) {
            if (it->getBounds().intersects(alien.getBounds())) {
                alien.takeDamage(1);
                if (alien.isDead()) {
                    score += 100;
                }
                it = player.getProjectiles().erase(it);
            } else {
                ++it;
            }
        }
    }

    aliens.erase(
        std::remove_if(aliens.begin(), aliens.end(), [](Alien& alien) {
            return alien.isDead();
        }),
        aliens.end()
    );

    aliens.erase(
        std::remove_if(aliens.begin(), aliens.end(), [](Alien& alien) {
            return alien.isOffScreen();
        }),
        aliens.end()
    );

    // Render game elements
    for (auto& alien : aliens) {
        alien.render(window);
    }
    player.render(window);
    player.renderProjectiles(window);
    player.renderHealthBar(window);

    scoreText.setString("Score: " + std::to_string(score));
    window.draw(scoreText);
}
else if (currentState == GameState::SkinSelection) {
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
