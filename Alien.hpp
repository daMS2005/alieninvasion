#ifndef ALIEN_HPP
#define ALIEN_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.hpp"

// Updated AlienType enum to include Green and UFO aliens
enum class AlienType { Blue, Yellow, Green, UFO };

class Alien {
private:
    sf::Sprite sprite;
    sf::Texture texture1;
    sf::Texture texture2;
    AlienType type;                      // Alien type (Blue, Yellow, Green, or UFO)
    int health;                          // Health of the alien
    float speed;                         // Speed of the alien
    bool isMoving;                       // Whether the alien is moving
    sf::Clock animationClock;            // Clock to handle animation
    sf::Clock shootClock;                // Clock to manage shooting
    bool useTexture1;                    // Alternate between two textures
    std::vector<Projectile> projectiles; // Projectiles fired by this alien

public:
    Alien(const sf::Vector2f& position, AlienType alienType, int initialHealth = 3);
    
    void render(sf::RenderWindow& window);
    void shoot();                        // Alien shooting logic
    std::vector<Projectile>& getProjectiles();
    void updateProjectiles(float deltaTime);
    void renderProjectiles(sf::RenderWindow& window);
    void takeDamage(int damage);
    bool isDead() const;
    sf::FloatRect getBounds() const;
    bool isOffScreen() const;
    void update(float deltaTime, int scoreThreshold, int currentScore);
    
    AlienType getType() const; // Getter for alien type
};

#endif // ALIEN_HPP
