#ifndef ALIEN_HPP
#define ALIEN_HPP

#include <SFML/Graphics.hpp>

class Alien {
private:
    sf::Sprite sprite;
    sf::Texture texture0;
    sf::Texture texture1;
    float speed;
    int health;               // Alien health
    sf::Clock animationClock; // Timer for animation
    bool useTexture0;         // Toggle between textures
    bool isMoving;            // Whether the alien is moving or static

public:
    Alien(const sf::Vector2f& position, int initialHealth = 3); // Default health = 3
    void update(float deltaTime, int scoreThreshold, int currentScore);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    bool isOffScreen() const;
    void startMoving();
    void takeDamage(int damage); // Reduce health
    bool isDead() const;         // Check if alien is dead
};

#endif // ALIEN_HPP
