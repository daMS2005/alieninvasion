#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.hpp"

class Player {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed; // Movement speed
    std::vector<Projectile> projectiles; // Active projectiles
    sf::Clock shootClock; // Timer for shooting cooldown
    float shootCooldown;  // Minimum time between shots
    int health;           // Player's health
    sf::RectangleShape healthBarBackground; // Health bar background
    sf::RectangleShape healthBarForeground; // Health bar foreground

public:
    Player();
    void handleInput(float deltaTime);
    void update();
    void updateProjectiles(float deltaTime);
    void render(sf::RenderWindow& window);
    void renderProjectiles(sf::RenderWindow& window);
    void renderHealthBar(sf::RenderWindow& window); // Render the health bar
    void shoot();
    void takeDamage(int damage); // Handle player damage
    float getSpeed() const;  // Add this to get the player's speed
    void setSpeed(float newSpeed); // Declare setSpeed method

    sf::Vector2f getPosition() const;
    sf::FloatRect getBounds() const;
    std::vector<Projectile>& getProjectiles();
    void removeProjectile(size_t index);
    int getHealth();

};

#endif // PLAYER_HPP
