#include "Alien.hpp"
#include <iostream>

Alien::Alien(const sf::Vector2f& position, AlienType alienType, int initialHealth)
    : type(alienType), health(initialHealth), speed(100.0f), isMoving(false), useTexture1(true) {
    if (type == AlienType::Blue) {
        if (!texture1.loadFromFile("resources/bluealien0.png") ||
            !texture2.loadFromFile("resources/bluealien1.png")) {
            std::cerr << "Error loading blue alien textures\n";
        }
        health = 1; // Blue aliens have less health
    } else if (type == AlienType::Yellow) {
        if (!texture1.loadFromFile("resources/yellowalien0.png") ||
            !texture2.loadFromFile("resources/yellowalien1.png")) {
            std::cerr << "Error loading yellow alien textures\n";
        }
        health = 2; // Yellow aliens have more health
    }

    sprite.setTexture(texture1);
    sprite.setPosition(position);
}

void Alien::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

bool Alien::isDead() const {
    return health <= 0;
}

void Alien::shoot() {
    if (type == AlienType::Yellow && shootClock.getElapsedTime().asSeconds() > 2.0f) {
        sf::Vector2f position(sprite.getPosition().x + sprite.getGlobalBounds().width / 2,
                              sprite.getPosition().y + sprite.getGlobalBounds().height);
        projectiles.emplace_back(position, sf::Vector2f(0, 300.0f)); // Fire downward
        shootClock.restart();
    }
}


void Alien::update(float deltaTime, int scoreThreshold, int currentScore) {
    // Check if aliens should start moving based on score
    if (currentScore >= scoreThreshold) {
        isMoving = true;
    }

    // Move the alien downward if it is active
    if (isMoving) {
        sprite.move(0, speed * deltaTime);
    }

    // Yellow aliens can shoot
    if (type == AlienType::Yellow) {
        shoot();
    }

    // Alternate textures for animation
    if (animationClock.getElapsedTime().asSeconds() > 0.5f) {
        if (type == AlienType::Blue) {
            sprite.setTexture(useTexture1 ? texture1 : texture2); // Alternate blue textures
        } else if (type == AlienType::Yellow) {
            sprite.setTexture(useTexture1 ? texture1 : texture2); // Alternate yellow textures
        }
        useTexture1 = !useTexture1; // Toggle texture flag
        animationClock.restart();
    }
}



void Alien::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Alien::getBounds() const {
    return sprite.getGlobalBounds();
}

bool Alien::isOffScreen() const {
    return sprite.getPosition().y > 600;
}
