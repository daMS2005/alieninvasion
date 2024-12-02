#include "Player.hpp"
#include <iostream>

Player::Player() : speed(380.0f), shootCooldown(0.33f), health(100) { // By default we start with 100 health
    if (!texture.loadFromFile("resources/player.png")) {
        std::cerr << "Error loading player texture\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(400.0f, 500.0f);

    // Configure health bar
    healthBarBackground.setSize(sf::Vector2f(200.0f, 20.0f)); // Background size
    healthBarBackground.setFillColor(sf::Color::Red);         // Background color
    healthBarBackground.setPosition(580.0f, 10.0f);           // Top-right corner (adjust x and y)

    healthBarForeground.setSize(sf::Vector2f(200.0f, 20.0f)); // Foreground size
    healthBarForeground.setFillColor(sf::Color::Green);       // Foreground color
    healthBarForeground.setPosition(580.0f, 10.0f);           // Top-right corner (adjust x and y)
}


int Player::getHealth() {
    return health;
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
        shoot(); // Attempt to shoot
    }
}

void Player::shoot() {
    if (shootClock.getElapsedTime().asSeconds() >= shootCooldown) {
        sf::Vector2f position(sprite.getPosition().x + sprite.getGlobalBounds().width / 2,
                              sprite.getPosition().y);
        projectiles.emplace_back(position); // Create a new projectile
        shootClock.restart();              // Restart the cooldown timer
    }
}
void Player::takeDamage(int damage) {
    health -= damage; // Reduce health
    if (health < 0) {
        health = 0; // Prevent negative health
    }

    // Update health bar
    float healthPercentage = static_cast<float>(health) / 100.0f;
    healthBarForeground.setSize(sf::Vector2f(200.0f * healthPercentage, 20.0f));
}

float Player::getSpeed() const {
    return speed; // Return the current speed of the player
}

void Player::setSpeed(float newSpeed) {
    speed = newSpeed; // Set the player's speed to the new value
}

void Player::update() {
    // General player update logic (if needed)
}

void Player::updateProjectiles(float deltaTime) {
    for (auto it = projectiles.begin(); it != projectiles.end();) {
        it->update(deltaTime);
        if (it->isOffScreen()) {
            it = projectiles.erase(it); // Remove off-screen projectiles
        } else {
            ++it;
        }
    }
}

void Player::render(sf::RenderWindow& window) {
    window.draw(sprite); // Render the player
}

void Player::renderProjectiles(sf::RenderWindow& window) {
    for (auto& projectile : projectiles) {
        projectile.render(window); // Render projectiles
    }
}
void Player::renderHealthBar(sf::RenderWindow& window) {
    window.draw(healthBarBackground); // Draw health bar background
    window.draw(healthBarForeground); // Draw health bar foreground
}

std::vector<Projectile>& Player::getProjectiles() {
    return projectiles; // Return reference to projectiles
}

sf::Vector2f Player::getPosition() const {
    return sprite.getPosition();
}

sf::FloatRect Player::getBounds() const {
    return sprite.getGlobalBounds();
}

void Player::removeProjectile(size_t index) {
    if (index < projectiles.size()) {
        projectiles.erase(projectiles.begin() + index);
    }
}
