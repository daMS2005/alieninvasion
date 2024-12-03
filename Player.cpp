#include "Player.hpp"
#include <iostream>

Player::Player() : speed(430.0f), shootCooldown(0.33f), health(100), texturePath("../resources/player.png") { 
    // Default skin
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading default player texture: " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(400.0f, 500.0f);
    if (!shootingSoundBuffer.loadFromFile("../resources/shootingsound.ogg")) {
        std::cerr << "Error loading shooting sound\n";
    }
    shootingSound.setBuffer(shootingSoundBuffer);
    // Configure health bar
    healthBarBackground.setSize(sf::Vector2f(200.0f, 20.0f)); // Background size
    healthBarBackground.setFillColor(sf::Color::Red);         // Background color
    healthBarBackground.setPosition(580.0f, 10.0f);           // Top-right corner (adjust x and y)

    healthBarForeground.setSize(sf::Vector2f(200.0f, 20.0f)); // Foreground size
    healthBarForeground.setFillColor(sf::Color::Green);       // Foreground color
    healthBarForeground.setPosition(580.0f, 10.0f);           // Top-right corner (adjust x and y)
}

// Get health
int Player::getHealth() {
    return health;
}

// Handle player input
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

// Shoot a projectile
void Player::shoot() {
    if (shootClock.getElapsedTime().asSeconds() >= shootCooldown) {
        sf::Vector2f position(sprite.getPosition().x + sprite.getGlobalBounds().width / 2,
                              sprite.getPosition().y);
        projectiles.emplace_back(position); // Create a new projectile
        shootingSound.play();               // Play the shooting sound
        shootClock.restart();               // Restart the cooldown timer
    }
}


// Take damage and update health bar
void Player::takeDamage(int damage) {
    health -= damage; // Reduce health
    if (health < 0) {
        health = 0; // Prevent negative health
    }

    // Update health bar
    float healthPercentage = static_cast<float>(health) / 100.0f;
    healthBarForeground.setSize(sf::Vector2f(200.0f * healthPercentage, 20.0f));
}

// Update projectiles
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
void Player::update() {
    //To be implemented
}
// Change skin dynamically
void Player::setSkin(const std::string& filePath) {
    if (!texture.loadFromFile(filePath)) {
        std::cerr << "Error loading skin texture: " << filePath << std::endl;
    } else {
        texturePath = filePath; // Update the stored texture path
        sprite.setTexture(texture); // Apply the new texture
    }
}

// Render the player sprite
void Player::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

// Render projectiles
void Player::renderProjectiles(sf::RenderWindow& window) {
    for (auto& projectile : projectiles) {
        projectile.render(window);
    }
}

// Render health bar
void Player::renderHealthBar(sf::RenderWindow& window) {
    window.draw(healthBarBackground);
    window.draw(healthBarForeground);
}

// Get reference to projectiles
std::vector<Projectile>& Player::getProjectiles() {
    return projectiles;
}

// Get player position
sf::Vector2f Player::getPosition() {
    return sprite.getPosition();
}

// Get player bounds
sf::FloatRect Player::getBounds() {
    return sprite.getGlobalBounds();
}

// Remove a projectile by index
void Player::removeProjectile(size_t index) {
    if (index < projectiles.size()) {
        projectiles.erase(projectiles.begin() + index);
    }
}
