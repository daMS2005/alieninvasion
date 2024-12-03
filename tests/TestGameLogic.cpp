#include <gtest/gtest.h>
#include "Player.hpp"
#include "Alien.hpp"

TEST(GameLogicTest, AlienSpawning) {
    std::vector<Alien> aliens;
    // Simulate spawning logic
    aliens.emplace_back(sf::Vector2f(100.0f, 100.0f), 3, Alien::AlienType::Blue);
    EXPECT_EQ(aliens.size(), 1); // One alien spawned
}

TEST(GameLogicTest, ScoreUpdate) {
    int score = 0;
    Alien alien({0.0f, 0.0f}, 1);
    alien.takeDamage(1);
    if (alien.isDead()) score += 10;
    EXPECT_EQ(score, 10); // Score increases
}

TEST(GameLogicTest, GameOver) {
    Player player;
    player.takeDamage(100);
    EXPECT_EQ(player.getHealth(), 0); // Player is out of health
}
