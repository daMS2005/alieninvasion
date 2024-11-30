#include "Player.hpp"
#include <iostream>

Player::Player() : speed(200.0f) { // Default player speed
    if (!texture.loadFromFile("resources/player.png")) {
        std::cerr << "Error loading player texture\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(400.0f, 500.0f); // Initialize player position (centered at the bottom)
}

void Player::handleInput(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite.getPosition().x > 0) {
        sprite.move(-speed * deltaTime, 0); // Move left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        sprite.getPosition().x < 800 - sprite.getGlobalBounds().width) {
        sprite.move(speed * deltaTime, 0); // Move right
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        shoot(); // Fire a projectile
    }
}

void Player::update() {
    // No specific logic for the player yet, but this can be expanded
}

void Player::updateProjectiles(float deltaTime) {
    for (auto it = projectiles.begin(); it != projectiles.end();) {
        it->update(deltaTime); // Update each projectile with deltaTime
        if (it->isOffScreen()) {
            it = projectiles.erase(it); // Remove projectiles that are off-screen
        } else {
            ++it;
        }
    }
}

void Player::render(sf::RenderWindow& window) {
    window.draw(sprite); // Draw the player sprite
}

void Player::renderProjectiles(sf::RenderWindow& window) {
    for (auto& projectile : projectiles) {
        projectile.render(window); // Draw each projectile
    }
}

void Player::shoot() {
    sf::Vector2f position(sprite.getPosition().x + sprite.getGlobalBounds().width / 2,
                          sprite.getPosition().y); // Set projectile starting position
    projectiles.emplace_back(position); // Create a new projectile
}

std::vector<Projectile>& Player::getProjectiles() {
    return projectiles;
}

