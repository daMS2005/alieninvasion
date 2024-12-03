#ifndef ALIEN_HPP
#define ALIEN_HPP

#include <SFML/Graphics.hpp>

/// @class Alien
/// @brief Represents an alien in the game.
///
/// This class handles the properties and behaviors of aliens, including movement,
/// health, rendering, and interaction with other game entities.
class Alien {
public:
    /// @enum AlienType
    /// @brief Enumerates the types of aliens.
    enum class AlienType { 
        Blue,  ///< Represents a blue alien.
        Green, ///< Represents a green alien.
        Yellow ///< Represents a yellow alien.
    };

private:
    sf::Sprite sprite; ///< The sprite representing the alien.
    sf::Texture texture0; ///< Texture for animation frame 0.
    sf::Texture texture1; ///< Texture for animation frame 1.
    float speed; ///< Speed of the alien's movement.
    int health; ///< The alien's health points.
    sf::Clock animationClock; ///< Timer for handling sprite animation.
    bool useTexture0; ///< Toggle between textures for animation.
    bool isMoving; ///< Whether the alien is currently moving.
    AlienType alienType; ///< The type of the alien (affects appearance and behavior).

public:
    /// @brief Gets the current health of the alien.
    /// @return The alien's current health as an integer.
    int getHealth() const;

    /// @brief Constructs an Alien object.
    /// @param position The initial position of the alien.
    /// @param initialHealth The starting health of the alien (default is 3).
    /// @param type The type of alien (default is AlienType::Blue).
    Alien(const sf::Vector2f& position, int initialHealth = 3, AlienType type = AlienType::Blue);

    /// @brief Updates the alien's state, including position and animation.
    /// @param deltaTime The elapsed time since the last update.
    /// @param scoreThreshold A score threshold that may affect alien behavior.
    /// @param currentScore The player's current score, used to adjust behavior.
    void update(float deltaTime, int scoreThreshold, int currentScore);

    /// @brief Renders the alien to the specified window.
    /// @param window The SFML window where the alien will be drawn.
    void render(sf::RenderWindow& window);

    /// @brief Gets the bounding box of the alien's sprite.
    /// @return A FloatRect representing the alien's bounding box.
    sf::FloatRect getBounds() const;

    /// @brief Checks if the alien has moved off the screen.
    /// @return True if the alien is off-screen, false otherwise.
    bool isOffScreen() const;

    /// @brief Starts the alien's movement.
    void startMoving();

    /// @brief Reduces the alien's health by a specified amount of damage.
    /// @param damage The amount of damage to apply to the alien.
    void takeDamage(int damage);

    /// @brief Checks if the alien is dead (health <= 0).
    /// @return True if the alien is dead, false otherwise.
    bool isDead() const;
};

#endif // ALIEN_HPP
