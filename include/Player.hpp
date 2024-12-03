#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.hpp"
#include <SFML/Audio.hpp>

/**
 * @class Player
 * @brief Represents the player in the game.
 */
class Player {
private:
    sf::Sprite sprite; ///< The sprite representing the player.
    sf::Texture texture; ///< The texture of the player.
    float speed; ///< Movement speed.
    std::vector<Projectile> projectiles; ///< Active projectiles.
    sf::Clock shootClock; ///< Timer for shooting cooldown.
    float shootCooldown; ///< Minimum time between shots.
    int health; ///< Player's health.
    sf::RectangleShape healthBarBackground; ///< Health bar background.
    sf::RectangleShape healthBarForeground; ///< Health bar foreground.
    sf::SoundBuffer shootingSoundBuffer; ///< Buffer for shooting sound.
    sf::Sound shootingSound; ///< Shooting sound.
    std::string texturePath; ///< Tracks the current texture path.

    /**
     * @brief Loads the sounds for the player.
     */
    void loadSounds();

public:
    /**
     * @brief Constructs a new Player object.
     */
    Player();

    /**
     * @brief Handles the player's input.
     * @param deltaTime The time elapsed since the last update.
     */
    void handleInput(float deltaTime);

    /**
     * @brief Updates the player's state.
     */
    void update();

    /**
     * @brief Updates the player's projectiles.
     * @param deltaTime The time elapsed since the last update.
     */
    void updateProjectiles(float deltaTime);

    /**
     * @brief Renders the player on the given window.
     * @param window The window to render the player on.
     */
    void render(sf::RenderWindow& window);

    /**
     * @brief Renders the player's projectiles on the given window.
     * @param window The window to render the projectiles on.
     */
    void renderProjectiles(sf::RenderWindow& window);

    /**
     * @brief Renders the player's health bar on the given window.
     * @param window The window to render the health bar on.
     */
    void renderHealthBar(sf::RenderWindow& window);

    /**
     * @brief Makes the player shoot a projectile.
     */
    void shoot();

    /**
     * @brief Handles player damage.
     * @param damage The amount of damage to inflict.
     */
    void takeDamage(int damage);

    /**
     * @brief Sets the player's skin.
     * @param filePath The file path to the texture.
     */
    void setSkin(const std::string& filePath);

    /**
     * @brief Gets the player's position.
     * @return The player's position.
     */
    sf::Vector2f getPosition();

    /**
     * @brief Gets the bounding box of the player.
     * @return The bounding box of the player.
     */
    sf::FloatRect getBounds();

    /**
     * @brief Gets the player's active projectiles.
     * @return A reference to the vector of active projectiles.
     */
    std::vector<Projectile>& getProjectiles();

    /**
     * @brief Removes a projectile at the specified index.
     * @param index The index of the projectile to remove.
     */
    void removeProjectile(size_t index);

    /**
     * @brief Gets the player's health.
     * @return The player's health.
     */
    int getHealth();
};

#endif // PLAYER_HPP