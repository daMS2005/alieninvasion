#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.hpp"
#include <SFML/Audio.hpp>

/// @class Player
/// @brief Represents the player character in the game.
///
/// This class handles the player's movement, shooting, health, and rendering.
class Player {
private:
    sf::Sprite sprite; ///< The sprite representing the player.
    sf::Texture texture; ///< The texture used for the player's sprite.
    float speed; ///< The movement speed of the player.
    std::vector<Projectile> projectiles; ///< Active projectiles fired by the player.
    sf::Clock shootClock; ///< Timer to enforce shooting cooldown.
    float shootCooldown; ///< Minimum time (in seconds) between shots.
    int health; ///< The player's health points.
    sf::RectangleShape healthBarBackground; ///< Background for the player's health bar.
    sf::RectangleShape healthBarForeground; ///< Foreground for the player's health bar.
    sf::SoundBuffer shootingSoundBuffer; ///< Buffer for the shooting sound effect.
    sf::Sound shootingSound; ///< The sound effect played when the player shoots.
    std::string texturePath; ///< Tracks the current texture path.

    /// @brief Loads sound effects for the player.
    void loadSounds();

public:
    /// @brief Constructs a Player object and initializes its properties.
    Player();

    /// @brief Handles player input and updates position based on input.
    /// @param deltaTime The elapsed time since the last frame.
    void handleInput(float deltaTime);

    /// @brief Updates the player's state, such as animations or cooldowns.
    void update();

    /// @brief Updates the active projectiles fired by the player.
    /// @param deltaTime The elapsed time since the last frame.
    void updateProjectiles(float deltaTime);

    /// @brief Renders the player sprite to the specified window.
    /// @param window The SFML window where the player will be drawn.
    void render(sf::RenderWindow& window);

    /// @brief Renders all active projectiles to the specified window.
    /// @param window The SFML window where the projectiles will be drawn.
    void renderProjectiles(sf::RenderWindow& window);

    /// @brief Renders the player's health bar to the specified window.
    /// @param window The SFML window where the health bar will be drawn.
    void renderHealthBar(sf::RenderWindow& window);

    /// @brief Fires a projectile if the cooldown allows.
    void shoot();

    /// @brief Reduces the player's health by a specified amount.
    /// @param damage The amount of damage to apply to the player.
    void takeDamage(int damage);

    /// @brief Sets the player's sprite texture using a specified file path.
    /// @param filePath The path to the texture file.
    void setSkin(const std::string& filePath);

    /// @brief Gets the player's current position.
    /// @return A 2D vector representing the player's position.
    sf::Vector2f getPosition() const;

    /// @brief Gets the bounding box of the player's sprite.
    /// @return A FloatRect representing the player's bounding box.
    sf::FloatRect getBounds() const;

    /// @brief Gets a reference to the player's active projectiles.
    /// @return A vector containing the active projectiles.
    std::vector<Projectile>& getProjectiles();

    /// @brief Removes a projectile from the player's projectile list.
    /// @param index The index of the projectile to remove.
    void removeProjectile(size_t index);

    /// @brief Gets the player's current health.
    /// @return The player's health as an integer.
    int getHealth();
};

#endif // PLAYER_HPP
