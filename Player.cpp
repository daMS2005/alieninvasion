#include "Player.hpp"
#include <iostream>

Player::Player() : speed(300.0f) {
    if (!texture.loadFromFile("player.png")) {
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
}

void Player::update() {
    // Additional updates if needed
}

void Player::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::Vector2f Player::getPosition() const {
    return sprite.getPosition();
}

sf::FloatRect Player::getBounds() const {
    return sprite.getGlobalBounds();
}
