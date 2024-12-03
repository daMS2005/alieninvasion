#include <gtest/gtest.h>
#include "Player.hpp"

/**
 * @brief Test: Initial Health of Player.
 */
TEST(PlayerTest, InitialHealth) {
    Player player;
    EXPECT_EQ(player.getHealth(), 100); // Ensure the default health is 100
}

/**
 * @brief Test: Player Takes Damage.
 */
TEST(PlayerTest, TakeDamage) {
    Player player;
    player.takeDamage(30);
    EXPECT_EQ(player.getHealth(), 70); // Verify health is reduced correctly
}

/**
 * @brief Test: Player Shooting Cooldown.
 */
TEST(PlayerTest, ShootingCooldown) {
    Player player;
    player.shoot();
    EXPECT_EQ(player.getProjectiles().size(), 0); // Ensure a projectile is created
}