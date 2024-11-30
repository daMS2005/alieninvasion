#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Graphics.hpp>

class Projectile {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity;

public:
    Projectile(const sf::Vector2f& position, const sf::Vector2f& velocity); // Existing constructor
    Projectile(const sf::Vector2f& position); // Overloaded constructor
    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    bool isOffScreen() const;
};

#endif // PROJECTILE_HPP
