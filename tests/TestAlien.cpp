#include "Alien.hpp"
#include <gtest/gtest.h>

/**
 * @brief Test for Blue Alien Initialization.
 */
TEST(AlienTest, BlueAlienInitialization) {
    Alien alien({100.0f, 50.0f}, Alien::AlienType::Blue, 5);
    EXPECT_FALSE(alien.isDead()); // Check that alien is not dead on initialization
    EXPECT_EQ(alien.getType(), Alien::AlienType::Blue); // Verify type is Blue
}

/**
 * @brief Test for Green Alien Initialization.
 */
TEST(AlienTest, GreenAlienInitialization) {
    Alien alien({0.0f, 0.0f}, Alien::AlienType::Green, 2);
    EXPECT_FALSE(alien.isDead()); // Check that alien is not dead on initialization
    EXPECT_EQ(alien.getType(), Alien::AlienType::Green); // Verify type is Green
}

/**
 * @brief Test for Yellow Alien Initialization.
 */
TEST(AlienTest, YellowAlienInitialization) {
    Alien alien({0.0f, 0.0f}, Alien::AlienType::Yellow, 1);
    EXPECT_FALSE(alien.isDead()); // Check that alien is not dead on initialization
    EXPECT_EQ(alien.getType(), Alien::AlienType::Yellow); // Verify type is Yellow
}