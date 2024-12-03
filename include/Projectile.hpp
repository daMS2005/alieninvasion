#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Graphics.hpp>

/// @class Projectile
/// @brief Represents a projectile fired by the player.
///
/// This class handles the properties and behaviors of projectiles,
/// including movement, rendering, and collision detection.
class Projectile {
private:
    sf::Sprite sprite; ///< The sprite representing the projectile.
    sf::Texture texture; ///< The texture used for the projectile's sprite.
    float speed; ///< The speed at which the projectile moves.

public:
    /// @brief Constructs a Projectile object at the specified position.
    /// @param position The initial position of the projectile.
    Projectile(const sf::Vector2f& position);

    /// @brief Updates the projectile's position.
    /// @param deltaTime The elapsed time since the last frame, used for frame-independent movement.
    void update(float deltaTime);

    /// @brief Renders the projectile to the specified window.
    /// @param window The SFML window where the projectile will be drawn.
    void render(sf::RenderWindow& window);

    /// @brief Gets the bounding box of the projectile's sprite.
    /// @return A FloatRect representing the projectile's bounding box.
    sf::FloatRect getBounds() const;

    /// @brief Checks if the projectile is off-screen.
    /// @return True if the projectile is outside the visible area, false otherwise.
    bool isOffScreen() const;
};

#endif // PROJECTILE_HPP
