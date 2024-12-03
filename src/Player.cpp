#include "Player.hpp"
#include <iostream>

/**
 * @brief Constructs a new Player object with default settings.
 */
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

/**
 * @brief Gets the player's health.
 * @return The player's health.
 */
int Player::getHealth() {
    return health;
}

/**
 * @brief Handles player input for movement and shooting.
 * @param deltaTime The time elapsed since the last update.
 */
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

/**
 * @brief Shoots a projectile if the cooldown period has elapsed.
 */
void Player::shoot() {
    if (shootClock.getElapsedTime().asSeconds() >= shootCooldown) {
        sf::Vector2f position(sprite.getPosition().x + sprite.getGlobalBounds().width / 2,
                              sprite.getPosition().y);
        projectiles.emplace_back(position); // Create a new projectile
        shootingSound.play();               // Play the shooting sound
        shootClock.restart();               // Restart the cooldown timer
    }
}

/**
 * @brief Inflicts damage to the player and updates the health bar.
 * @param damage The amount of damage to inflict.
 */
void Player::takeDamage(int damage) {
    health -= damage; // Reduce health
    if (health < 0) {
        health = 0; // Prevent negative health
    }

    // Update health bar
    float healthPercentage = static_cast<float>(health) / 100.0f;
    healthBarForeground.setSize(sf::Vector2f(200.0f * healthPercentage, 20.0f));
}

/**
 * @brief Updates the player's projectiles.
 * @param deltaTime The time elapsed since the last update.
 */
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

/**
 * @brief Updates the player's state.
 */
void Player::update() {
    // To be implemented
}

/**
 * @brief Changes the player's skin dynamically.
 * @param filePath The file path to the new texture.
 */
void Player::setSkin(const std::string& filePath) {
    if (!texture.loadFromFile(filePath)) {
        std::cerr << "Error loading skin texture: " << filePath << std::endl;
    } else {
        texturePath = filePath; // Update the stored texture path
        sprite.setTexture(texture); // Apply the new texture
    }
}

/**
 * @brief Renders the player sprite.
 * @param window The window to render the player on.
 */
void Player::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

/**
 * @brief Renders the player's projectiles.
 * @param window The window to render the projectiles on.
 */
void Player::renderProjectiles(sf::RenderWindow& window) {
    for (auto& projectile : projectiles) {
        projectile.render(window);
    }
}

/**
 * @brief Renders the player's health bar.
 * @param window The window to render the health bar on.
 */
void Player::renderHealthBar(sf::RenderWindow& window) {
    window.draw(healthBarBackground);
    window.draw(healthBarForeground);
}

/**
 * @brief Gets a reference to the player's active projectiles.
 * @return A reference to the vector of active projectiles.
 */
std::vector<Projectile>& Player::getProjectiles() {
    return projectiles;
}

/**
 * @brief Gets the player's position.
 * @return The player's position.
 */
sf::Vector2f Player::getPosition() {
    return sprite.getPosition();
}

/**
 * @brief Gets the bounding box of the player.
 * @return The bounding box of the player.
 */
sf::FloatRect Player::getBounds() {
    return sprite.getGlobalBounds();
}

/**
 * @brief Removes a projectile at the specified index.
 * @param index The index of the projectile to remove.
 */
void Player::removeProjectile(size_t index) {
    if (index < projectiles.size()) {
        projectiles.erase(projectiles.begin() + index);
    }
}