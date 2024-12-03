#include <gtest/gtest.h>
#include "Projectile.hpp"

/**
 * @brief Test: Initial Position of Projectile.
 */
TEST(ProjectileTest, InitialPosition) {
    Projectile projectile({100.0f, 200.0f});
    EXPECT_EQ(projectile.getBounds().top, 200.0f); // Verify Y position
    EXPECT_EQ(projectile.getBounds().left, 100.0f); // Verify X position
}

/**
 * @brief Test: Projectile Movement.
 */
TEST(ProjectileTest, Movement) {
    Projectile projectile({0.0f, 200.0f});
    float deltaTime = 0.016f; // Simulate a frame (~60 FPS)
    projectile.update(deltaTime);
    EXPECT_LT(projectile.getBounds().top, 200.0f); // Ensure Y position decreases
}

/**
 * @brief Test: Off-Screen Detection.
 */
TEST(ProjectileTest, OffScreenDetection) {
    Projectile projectile({0.0f, -10.0f});
    EXPECT_TRUE(projectile.isOffScreen()); // Projectile should be off-screen
}