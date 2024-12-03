#include <gtest/gtest.h>
#include "Alien.hpp"

TEST(AlienTest, Initialization) {
    Alien alien({100.0f, 50.0f}, 5, Alien::AlienType::Blue);
    EXPECT_EQ(alien.getHealth(), 5);
    EXPECT_EQ(alien.getBounds().top, 50.0f);
    EXPECT_EQ(alien.getBounds().left, 100.0f);
}

TEST(AlienTest, TakeDamage) {
    Alien alien({0.0f, 0.0f}, 3, Alien::AlienType::Green);
    alien.takeDamage(1);
    EXPECT_EQ(alien.getHealth(), 2);
}

TEST(AlienTest, IsDead) {
    Alien alien({0.0f, 0.0f}, 1, Alien::AlienType::Yellow);
    alien.takeDamage(1);
    EXPECT_TRUE(alien.isDead());
}
