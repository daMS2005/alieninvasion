#include "Player.hpp"

Player::Player() : speed(300.0f) {
    if (!texture.loadFromFile("resources/player.png")) {
        std::cerr << "Error loading player texture\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(400.0f, 500.0f); // Center bottom
}

void Player::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite.getPosition().x > 0) {
        sprite.move(-speed * 0.016f, 0); // Move left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sprite.getPosition().x < 800 - sprite.getGlobalBounds().width) {
        sprite.move(speed * 0.016f, 0); // Move right
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        shoot();
    }
}

void Player::shoot() {
    if (shootClock.getElapsedTime().asMilliseconds() > 300) { // Fire every 300 ms
        sf::Vector2f position = sprite.getPosition();
        projectiles.emplace_back(position);
        shootClock.restart();
    }
}

void Player::updateProjectiles() {
    for (auto it = projectiles.begin(); it != projectiles.end();) {
        it->update();
        if (it->isOffScreen()) {
            it = projectiles.erase(it);
        } else {
            ++it;
        }
    }
}

void Player::renderProjectiles(sf::RenderWindow& window) {
    for (auto& projectile : projectiles) {
        projectile.render(window);
    }
}

const std::vector<Projectile>& Player::getProjectiles() const {
    return projectiles;
}

void Player::update() {
    updateProjectiles();
}
void Player::render(sf::RenderWindow& window) {
    window.draw(sprite); // Draw the player's sprite
}
