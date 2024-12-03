#include <gtest/gtest.h>
#include "Projectile.hpp"

TEST(ProjectileTest, InitialPosition) {
    Projectile projectile({100.0f, 200.0f});
    EXPECT_EQ(projectile.getBounds().top, 200.0f); // Correct Y position
    EXPECT_EQ(projectile.getBounds().left, 100.0f); // Correct X position
}

TEST(ProjectileTest, Movement) {
    Projectile projectile({0.0f, 200.0f});
    projectile.update(0.016f); // Simulate a frame
    EXPECT_LT(projectile.getBounds().top, 200.0f); // Y position decreased
}

TEST(ProjectileTest, OffScreenDetection) {
    Projectile projectile({0.0f, -10.0f});
    EXPECT_TRUE(projectile.isOffScreen()); // Projectile is off-screen
}
