#include "Alien.hpp"
#include <iostream>

Alien::Alien(const sf::Vector2f& position, AlienType alienType, int initialHealth)
    : type(alienType), health(initialHealth), speed(100.0f), isMoving(false), useTexture1(true) {
    if (type == AlienType::Blue) {
        if (!texture1.loadFromFile("resources/bluealien0.png") ||
            !texture2.loadFromFile("resources/bluealien1.png")) {
            std::cerr << "Error loading blue alien textures\n";
        }
    } else if (type == AlienType::Yellow) {
        if (!texture1.loadFromFile("resources/yellowalien0.png") ||
            !texture2.loadFromFile("resources/yellowalien1.png")) {
            std::cerr << "Error loading yellow alien textures\n";
        }
    } else if (type == AlienType::Green) {
        if (!texture1.loadFromFile("resources/greenalien0.png") ||
            !texture2.loadFromFile("resources/greenalien1.png")) {
            std::cerr << "Error loading green alien textures\n";
        }
    } else if (type == AlienType::UFO) {
        if (!texture1.loadFromFile("resources/ufo.png")) {
            std::cerr << "Error loading UFO texture\n";
        }
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
    if (shootClock.getElapsedTime().asSeconds() > 2.0f) {
        sf::Vector2f position(sprite.getPosition().x + sprite.getGlobalBounds().width / 2,
                              sprite.getPosition().y + sprite.getGlobalBounds().height);

        if (type == AlienType::Yellow || type == AlienType::Green) {
            projectiles.emplace_back(position, sf::Vector2f(0, 300.0f)); // Fire downward
        } else if (type == AlienType::UFO) {
            projectiles.emplace_back(position, sf::Vector2f(0, 400.0f)); // Stronger projectile
        }

        shootClock.restart();
    }
}

void Alien::update(float deltaTime, int scoreThreshold, int currentScore) {
    // Update movement based on type
    if (type == AlienType::Blue || type == AlienType::Yellow) {
        if (currentScore >= scoreThreshold) {
            isMoving = true;
        }
        if (isMoving) {
            sprite.move(0, speed * deltaTime);
        }
    } else if (type == AlienType::UFO) {
        // UFO horizontal movement
        static bool movingRight = true;
        if (movingRight) {
            sprite.move(speed * deltaTime, 0);
            if (sprite.getPosition().x + sprite.getGlobalBounds().width >= 800) {
                movingRight = false;
            }
        } else {
            sprite.move(-speed * deltaTime, 0);
            if (sprite.getPosition().x <= 0) {
                movingRight = true;
            }
        }
    }

    // Shooting logic
    shoot();

    // Update projectiles
    for (auto it = projectiles.begin(); it != projectiles.end();) {
        it->update(deltaTime);
        if (it->isOffScreen()) {
            it = projectiles.erase(it);
        } else {
            ++it;
        }
    }

    // Animation logic for Blue, Yellow, Green (UFO excluded)
    if (type != AlienType::UFO && animationClock.getElapsedTime().asSeconds() > 0.5f) {
        sprite.setTexture(useTexture1 ? texture2 : texture1);
        useTexture1 = !useTexture1;
        animationClock.restart();
    }
}

AlienType Alien::getType() const {
    return type;
}

void Alien::render(sf::RenderWindow& window) {
    window.draw(sprite);

    // Render projectiles
    for (auto& projectile : projectiles) {
        projectile.render(window);
    }
}

sf::FloatRect Alien::getBounds() const {
    return sprite.getGlobalBounds();
}

bool Alien::isOffScreen() const {
    return sprite.getPosition().y > 600;
}
std::vector<Projectile>& Alien::getProjectiles() {
    return projectiles;
}

