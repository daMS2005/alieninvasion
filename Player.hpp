#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.hpp"
#include <SFML/Audio.hpp>

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
    sf::SoundBuffer shootingSoundBuffer;
    sf::Sound shootingSound;
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
    void setSkin(const std::string& filePath); // Ensure this is declared
    sf::Vector2f getPosition();
    sf::FloatRect getBounds();
    std::vector<Projectile>& getProjectiles();
    void removeProjectile(size_t index);
    int getHealth();
    private:
    std::string texturePath; // Tracks the current texture path
    void loadSounds();
};

#endif // PLAYER_HPP
