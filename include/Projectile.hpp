#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Graphics.hpp>

/**
 * @class Projectile
 * @brief Represents a projectile in the game.
 */
class Projectile {
private:
    sf::Sprite sprite; ///< The sprite representing the projectile.
    sf::Texture texture; ///< The texture of the projectile.
    sf::Vector2f velocity; ///< The velocity of the projectile.

public:
    /**
     * @brief Constructs a new Projectile object with a specified position and velocity.
     * @param position The initial position of the projectile.
     * @param velocity The initial velocity of the projectile.
     */
    Projectile(const sf::Vector2f& position, const sf::Vector2f& velocity);

    /**
     * @brief Constructs a new Projectile object with a specified position.
     * @param position The initial position of the projectile.
     */
    Projectile(const sf::Vector2f& position);

    /**
     * @brief Updates the projectile's position based on its velocity and the elapsed time.
     * @param deltaTime The time elapsed since the last update.
     */
    void update(float deltaTime);

    /**
     * @brief Renders the projectile on the given window.
     * @param window The window to render the projectile on.
     */
    void render(sf::RenderWindow& window);

    /**
     * @brief Gets the bounding box of the projectile.
     * @return The bounding box of the projectile.
     */
    sf::FloatRect getBounds() const;

    /**
     * @brief Checks if the projectile is off the screen.
     * @return True if the projectile is off the screen, false otherwise.
     */
    bool isOffScreen() const;
};

#endif // PROJECTILE_HPP