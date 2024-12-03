#include "Alien.hpp"
#include <iostream>

/**
 * @brief Constructs a new Alien object with a specified position, type, and initial health.
 * @param position The initial position of the alien.
 * @param alienType The type of the alien.
 * @param initialHealth The initial health of the alien.
 */
Alien::Alien(const sf::Vector2f& position, Alien::AlienType alienType, int initialHealth)
    : type(alienType), health(initialHealth), speed(100.0f), isMoving(false), useTexture1(true) {
    if (type == Alien::AlienType::Blue) {
        if (!texture1.loadFromFile("../resources/bluealien0.png") ||
            !texture2.loadFromFile("../resources/bluealien1.png")) {
            std::cerr << "Error loading blue alien textures\n";
        }
    } else if (type == Alien::AlienType::Yellow) {
        if (!texture1.loadFromFile("../resources/yellowalien0.png") ||
            !texture2.loadFromFile("../resources/yellowalien1.png")) {
            std::cerr << "Error loading yellow alien textures\n";
        }
    } else if (type == Alien::AlienType::Green) {
        if (!texture1.loadFromFile("../resources/greenalien0.png") ||
            !texture2.loadFromFile("../resources/greenalien1.png")) {
            std::cerr << "Error loading green alien textures\n";
        }
    } else if (type == Alien::AlienType::UFO) {
        if (!texture1.loadFromFile("../resources/ufo.png")) {
            std::cerr << "Error loading UFO texture\n";
        }
    }

    sprite.setTexture(texture1);
    sprite.setPosition(position);
}

/**
 * @brief Inflicts damage to the alien.
 * @param damage The amount of damage to inflict.
 */
void Alien::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

/**
 * @brief Checks if the alien is dead.
 * @return True if the alien's health is 0 or less, false otherwise.
 */
bool Alien::isDead() const {
    return health <= 0;
}

/**
 * @brief Makes the alien shoot a projectile.
 */
void Alien::shoot() {
    if (shootClock.getElapsedTime().asSeconds() > 2.0f) {
        sf::Vector2f position(sprite.getPosition().x + sprite.getGlobalBounds().width / 2,
                              sprite.getPosition().y + sprite.getGlobalBounds().height);

        if (type == Alien::AlienType::Yellow || type == Alien::AlienType::Green) {
            projectiles.emplace_back(position, sf::Vector2f(0, 300.0f)); // Fire downward
        } else if (type == Alien::AlienType::UFO) {
            projectiles.emplace_back(position, sf::Vector2f(0, 400.0f)); // Stronger projectile
        }

        shootClock.restart();
    }
}

/**
 * @brief Updates the alien's state.
 * @param deltaTime The time elapsed since the last update.
 * @param scoreThreshold The score threshold for certain behaviors.
 * @param currentScore The current score of the player.
 */
void Alien::update(float deltaTime, int scoreThreshold, int currentScore) {
    if (type == Alien::AlienType::Blue || type == Alien::AlienType::Yellow) {
        if (currentScore >= scoreThreshold) {
            isMoving = true; // Blue and Yellow start moving based on score
        }
        if (isMoving) {
            sprite.move(0, speed * deltaTime);
        }
    } else if (type == Alien::AlienType::UFO) {
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
    } else if (type == Alien::AlienType::Green) {
        // Ensure green aliens remain visible
        if (sprite.getPosition().y < 150.0f) { // Adjust to desired starting Y position
            sprite.setPosition(sprite.getPosition().x, 150.0f);
        }
    }

    // Shooting logic
    shoot();

    // Animation logic for Blue, Yellow, Green (UFO excluded)
    if (type != Alien::AlienType::UFO && animationClock.getElapsedTime().asSeconds() > 0.5f) {
        sprite.setTexture(useTexture1 ? texture2 : texture1);
        useTexture1 = !useTexture1;
        animationClock.restart();
    }

    // Update projectiles
    for (auto it = projectiles.begin(); it != projectiles.end();) {
        it->update(deltaTime);
        if (it->isOffScreen()) {
            it = projectiles.erase(it);
        } else {
            ++it;
        }
    }
}

/**
 * @brief Gets the type of the alien.
 * @return The type of the alien.
 */
Alien::AlienType Alien::getType() const {
    return type;
}

/**
 * @brief Renders the alien on the given window.
 * @param window The window to render the alien on.
 */
void Alien::render(sf::RenderWindow& window) {
    window.draw(sprite);

    // Render projectiles
    for (auto& projectile : projectiles) {
        projectile.render(window);
    }
}

/**
 * @brief Gets the bounding box of the alien.
 * @return The bounding box of the alien.
 */
sf::FloatRect Alien::getBounds() const {
    return sprite.getGlobalBounds();
}

/**
 * @brief Checks if the alien is off the screen.
 * @return True if the alien is off the screen, false otherwise.
 */
bool Alien::isOffScreen() const {
    return sprite.getPosition().y > 600;
}

/**
 * @brief Gets the alien's active projectiles.
 * @return A reference to the vector of active projectiles.
 */
std::vector<Projectile>& Alien::getProjectiles() {
    return projectiles;
}