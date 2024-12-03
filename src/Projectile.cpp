#include "Projectile.hpp"
#include <iostream>

/**
 * @brief Constructs a new Projectile object with a specified position and velocity.
 * @param position The initial position of the projectile.
 * @param velocity The initial velocity of the projectile.
 */
Projectile::Projectile(const sf::Vector2f& position, const sf::Vector2f& velocity)
    : velocity(velocity) {
    if (!texture.loadFromFile("../resources/laser.png")) {
        std::cerr << "Error loading projectile texture\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

/**
 * @brief Constructs a new Projectile object with a specified position.
 * @param position The initial position of the projectile.
 */
Projectile::Projectile(const sf::Vector2f& position)
    : velocity(0.0f, -300.0f) { // Default upward velocity
    if (!texture.loadFromFile("../resources/laser.png")) {
        std::cerr << "Error loading projectile texture\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

/**
 * @brief Updates the projectile's position based on its velocity and the elapsed time.
 * @param deltaTime The time elapsed since the last update.
 */
void Projectile::update(float deltaTime) {
    sprite.move(velocity * deltaTime); // Move the projectile using velocity
}

/**
 * @brief Renders the projectile on the given window.
 * @param window The window to render the projectile on.
 */
void Projectile::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

/**
 * @brief Gets the bounding box of the projectile.
 * @return The bounding box of the projectile.
 */
sf::FloatRect Projectile::getBounds() const {
    return sprite.getGlobalBounds();
}

/**
 * @brief Checks if the projectile is off the screen.
 * @return True if the projectile is off the screen, false otherwise.
 */
bool Projectile::isOffScreen() const {
    return sprite.getPosition().y < 0 || sprite.getPosition().y > 600;
}