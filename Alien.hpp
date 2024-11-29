#ifndef ALIEN_HPP
#define ALIEN_HPP

#include <SFML/Graphics.hpp>

class Alien {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed;

public:
    Alien(const sf::Vector2f& position);
    void update();
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    bool isOffScreen() const;
};

#endif // ALIEN_HPP
