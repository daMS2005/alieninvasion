#include "Projectile.hpp"
#include <iostream>

Projectile::Projectile(const sf::Vector2f& position) : speed(-500.0f) { // Set a negative speed for upward movement
    if (!texture.loadFromFile("../resources/projectile.png")) {
        std::cerr << "Error loading projectile texture\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(position.x, position.y); // Initialize the position
}

void Projectile::update(float deltaTime) {
    sprite.move(0, speed * deltaTime); // Use deltaTime for consistent upward movement
}

void Projectile::render(sf::RenderWindow& window) {
    window.draw(sprite); // Render the projectile
}

sf::FloatRect Projectile::getBounds() const {
    return sprite.getGlobalBounds(); // Return the projectile's bounds for collision detection
}

bool Projectile::isOffScreen() const {
    return sprite.getPosition().y + sprite.getGlobalBounds().height < 0; // Check if the projectile is above the screen
}
