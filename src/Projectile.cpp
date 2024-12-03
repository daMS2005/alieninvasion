#include "Projectile.hpp"
#include <iostream>

Projectile::Projectile(const sf::Vector2f& position, const sf::Vector2f& velocity)
    : velocity(velocity) {
    if (!texture.loadFromFile("../resources/laser.png")) {
        std::cerr << "Error loading projectile texture\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

Projectile::Projectile(const sf::Vector2f& position)
    : velocity(0.0f, -300.0f) { // Default upward velocity
    if (!texture.loadFromFile("../resources/laser.png")) {
        std::cerr << "Error loading projectile texture\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Projectile::update(float deltaTime) {
    sprite.move(velocity * deltaTime); // Move the projectile using velocity
}

void Projectile::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Projectile::getBounds() const {
    return sprite.getGlobalBounds();
}

bool Projectile::isOffScreen() const {
    return sprite.getPosition().y < 0 || sprite.getPosition().y > 600;
}