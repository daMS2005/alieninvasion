#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Graphics.hpp>

class Projectile {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed;

public:
    Projectile(const sf::Vector2f& position);
    void update();
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    bool isOffScreen() const;
};

#endif // PROJECTILE_HPP
