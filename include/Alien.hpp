#ifndef ALIEN_HPP
#define ALIEN_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.hpp"

/// @class Alien
/// @brief Represents an alien in the game.
///
/// This class handles the properties and behaviors of aliens, including movement,
/// health, rendering, interaction with other game entities, and shooting mechanics.
class Alien {
public:
    /// @enum AlienType
    /// @brief Enumerates the types of aliens.
    enum class AlienType { 
        Blue,  ///< Represents a blue alien.
        Yellow, ///< Represents a yellow alien.
        Green, ///< Represents a green alien.
        UFO ///< Represents a UFO alien.
    };

private:
    sf::Sprite sprite; ///< The sprite representing the alien.
    sf::Texture texture1; ///< Texture for animation frame 1.
    sf::Texture texture2; ///< Texture for animation frame 2.
    AlienType type; ///< The type of the alien (affects appearance and behavior).
    int health; ///< The alien's health points.
    float speed; ///< Speed of the alien's movement.
    bool isMoving; ///< Whether the alien is currently moving.
    sf::Clock animationClock; ///< Timer for handling sprite animation.
    sf::Clock shootClock; ///< Timer for handling shooting intervals.
    bool useTexture1; ///< Toggle between textures for animation.
    std::vector<Projectile> projectiles; ///< Projectiles fired by this alien.

public:
    /// @brief Constructs an Alien object.
    /// @param position The initial position of the alien.
    /// @param alienType The type of alien.
    /// @param initialHealth The starting health of the alien (default is 3).
    Alien(const sf::Vector2f& position, AlienType alienType, int initialHealth = 3);

    /// @brief Renders the alien to the specified window.
    /// @param window The SFML window where the alien will be drawn.
    void render(sf::RenderWindow& window);

    /// @brief Handles the shooting logic for the alien.
    void shoot();

    /// @brief Gets the projectiles fired by the alien.
    /// @return A reference to a vector of projectiles.
    std::vector<Projectile>& getProjectiles();

    /// @brief Updates the state of the alien's projectiles.
    /// @param deltaTime The elapsed time since the last update.
    void updateProjectiles(float deltaTime);

    /// @brief Renders the alien's projectiles to the specified window.
    /// @param window The SFML window where the projectiles will be drawn.
    void renderProjectiles(sf::RenderWindow& window);

    /// @brief Reduces the alien's health by a specified amount of damage.
    /// @param damage The amount of damage to apply to the alien.
    void takeDamage(int damage);

    /// @brief Checks if the alien is dead (health <= 0).
    /// @return True if the alien is dead, false otherwise.
    bool isDead() const;

    /// @brief Gets the bounding box of the alien's sprite.
    /// @return A FloatRect representing the alien's bounding box.
    sf::FloatRect getBounds() const;

    /// @brief Checks if the alien has moved off the screen.
    /// @return True if the alien is off-screen, false otherwise.
    bool isOffScreen() const;

    /// @brief Updates the alien's state, including position, animation, and shooting.
    /// @param deltaTime The elapsed time since the last update.
    /// @param scoreThreshold A score threshold that may affect alien behavior.
    /// @param currentScore The player's current score, used to adjust behavior.
    void update(float deltaTime, int scoreThreshold, int currentScore);

    /// @brief Gets the type of the alien.
    /// @return The type of the alien as an AlienType.
    AlienType getType() const;
};

#endif // ALIEN_HPP
