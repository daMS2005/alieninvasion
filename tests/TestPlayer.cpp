#include <gtest/gtest.h>
#include "Player.hpp"

TEST(PlayerTest, InitialHealth) {
    Player player;
    EXPECT_EQ(player.getHealth(), 100); // Default health
}

TEST(PlayerTest, TakeDamage) {
    Player player;
    player.takeDamage(30);
    EXPECT_EQ(player.getHealth(), 70); // Damage taken correctly
}

TEST(PlayerTest, ShootingCooldown) {
    Player player;
    player.shoot();
    EXPECT_EQ(player.getProjectiles().size(), 1); // A projectile is fired
}
