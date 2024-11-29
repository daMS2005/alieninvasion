#include "Projectile.hpp"
#include <iostream>

Projectile::Projectile(const sf::Vector2f& position) : speed(-500.0f) {
    if (!texture.loadFromFile("resources/projectile.png")) {
        std::cerr << "Error loading projectile texture\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(position.x, position.y);
}

void Projectile::update() {
    sprite.move(0, speed * 0.016f); // Move upwards
}

void Projectile::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Projectile::getBounds() const {
    return sprite.getGlobalBounds();
}

bool Projectile::isOffScreen() const {
    return sprite.getPosition().y + sprite.getGlobalBounds().height < 0;
}
