#include <gtest/gtest.h>
#include "Alien.hpp"
#include "Player.hpp"
#include "Projectile.hpp"

TEST(CollisionTest, PlayerAlienCollision) {
    Player player;
    Alien alien({player.getPosition().x, player.getPosition().y}, 3);
    EXPECT_TRUE(alien.getBounds().intersects(player.getBounds()));

    player.takeDamage(30);
    EXPECT_EQ(player.getHealth(), 70); // Player takes damage
}

TEST(CollisionTest, ProjectileAlienCollision) {
    Alien alien({100.0f, 100.0f}, 3);
    Projectile projectile({100.0f, 100.0f});
    EXPECT_TRUE(projectile.getBounds().intersects(alien.getBounds()));

    alien.takeDamage(1);
    EXPECT_EQ(alien.getHealth(), 2); // Alien takes damage
}
