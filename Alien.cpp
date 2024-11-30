#include "Alien.hpp"
#include <iostream>

Alien::Alien(const sf::Vector2f& position, int initialHealth)
    : speed(150.0f), useTexture0(true), isMoving(false), health(initialHealth) {
    if (!texture0.loadFromFile("resources/bluealien0.png")) {
        std::cerr << "Error loading bluealien0.png\n";
    }
    if (!texture1.loadFromFile("resources/bluealien1.png")) {
        std::cerr << "Error loading bluealien1.png\n";
    }
    sprite.setTexture(texture0);
    sprite.setPosition(position);
}

void Alien::update(float deltaTime, int scoreThreshold, int currentScore) {
    if (currentScore >= scoreThreshold) {
        isMoving = true;
    }

    if (animationClock.getElapsedTime().asSeconds() > 0.5f) {
        if (useTexture0) {
            sprite.setTexture(texture1);
        } else {
            sprite.setTexture(texture0);
        }
        useTexture0 = !useTexture0;
        animationClock.restart();
    }

    if (isMoving) {
        sprite.move(0, speed * deltaTime);
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

void Alien::startMoving() {
    isMoving = true;
}

void Alien::takeDamage(int damage) {
    health -= damage;
    std::cout << "Alien took " << damage << " damage. Health: " << health << "\n";
}

bool Alien::isDead() const {
    return health <= 0;
}