#include "Alien.hpp"
#include <gtest/gtest.h>

/**
 * @brief Test: Alien Initialization in a Vector.
 */
TEST(GameLogicTest, AlienInitialization) {
    std::vector<Alien> aliens;

    // Add an alien using the correct constructor
    aliens.emplace_back(sf::Vector2f(100.0f, 100.0f), Alien::AlienType::Blue, 3);

    // Check that the alien was successfully added to the vector
    EXPECT_EQ(aliens.size(), 1);
    EXPECT_EQ(aliens[0].getType(), Alien::AlienType::Blue); // Verify the type of the alien
    EXPECT_FALSE(aliens[0].isDead()); // Check that the alien is not dead
}

/**
 * @brief Test: Alien Health Initialization.
 */
TEST(GameLogicTest, AlienHealthInitialization) {
    // Initialize a Green alien with 2 health points
    Alien alien({0.0f, 0.0f}, Alien::AlienType::Green, 2);

    // Check initial state
    EXPECT_FALSE(alien.isDead()); // The alien should not be dead initially
    EXPECT_EQ(alien.getType(), Alien::AlienType::Green); // Verify the type is Green
}