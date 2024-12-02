#ifndef POWERUP_HPP
#define POWERUP_HPP

#include <SFML/Graphics.hpp>

class PowerUp {
private:
    sf::CircleShape shape;

public:
    PowerUp(const sf::Vector2f& position) {
        shape.setRadius(15.0f);  // Power-up is a red circle
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(position);
    }

    sf::FloatRect getBounds() const {
        return shape.getGlobalBounds();
    }

    void render(sf::RenderWindow& window) {
        window.draw(shape);  // Draw the power-up
    }
};

#endif // POWERUP_HPP
