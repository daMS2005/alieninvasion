#include "Alien.hpp"
#include "Player.hpp"
#include <gtest/gtest.h>

// Test: Collision between an Alien and the Player
TEST(CollisionTest, AlienCollisionWithPlayer) {
    // Initialize player
    Player player;

    // Initialize alien at the player's position
    Alien alien({player.getPosition().x, player.getPosition().y}, Alien::AlienType::Blue, 3);

    // Simulate collision
    bool collision = alien.getBounds().intersects(player.getBounds());

    // Check collision logic
    EXPECT_TRUE(collision); // The alien should collide with the player
    EXPECT_EQ(alien.isDead(), false); // The alien should not be dead on initialization
}

// Test: Alien taking damage
TEST(CollisionTest, AlienDamage) {
    // Initialize alien
    Alien alien({100.0f, 100.0f}, Alien::AlienType::Green, 3);

    // Simulate damage
    alien.takeDamage(1);

    // Check if health is reduced and alien is still alive
    EXPECT_FALSE(alien.isDead()); // Alien should not be dead yet
}

// Test: Alien dying after sufficient damage
TEST(CollisionTest, AlienDeath) {
    // Initialize alien
    Alien alien({100.0f, 100.0f}, Alien::AlienType::Yellow, 1);

    // Simulate damage that kills the alien
    alien.takeDamage(1);

    // Check if the alien is dead
    EXPECT_TRUE(alien.isDead()); // Alien should be dead
    EXPECT_EQ(alien.getType(), Alien::AlienType::Yellow); // Verify the alien type remains unchanged
}
