#include "PowerUp.hpp"

PowerUp::PowerUp(const sf::Vector2f& position) {
    shape.setRadius(20.0f);              // Set the radius of the circle
    shape.setFillColor(sf::Color::Red);  // Set the color to red
    shape.setPosition(position);         // Set the position of the power-up
    isActive = true;                     // Set the power-up as active initially
}

void PowerUp::render(sf::RenderWindow& window) {
    if (isActive) {
        window.draw(shape);  // Draw the power-up if it is still active
    }
}

sf::FloatRect PowerUp::getBounds() const {
    return shape.getGlobalBounds();  // Return the bounding box of the power-up
}

bool PowerUp::checkCollision(const sf::FloatRect& playerBounds) const {
    return isActive && shape.getGlobalBounds().intersects(playerBounds); // Check if player collides with power-up
}

bool PowerUp::isActiveState() const {
    return isActive; // Return whether the power-up is active
}

void PowerUp::deactivate() {
    isActive = false; // Deactivate the power-up after it's collected
}
