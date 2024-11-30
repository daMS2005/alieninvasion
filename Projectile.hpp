#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Graphics.hpp>

class Projectile {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed; // Speed of the projectile

public:
    Projectile(const sf::Vector2f& position);
    void update(float deltaTime); // Accept deltaTime for frame-independent movement
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const; // Get the projectile's bounds
    bool isOffScreen() const;        // Check if the projectile is off-screen
};

#endif // PROJECTILE_HPP
