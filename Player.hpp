#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Projectile.hpp"

class Player {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed;
    std::vector<Projectile> projectiles;
    sf::Clock shootClock;

public:
    Player();
    void handleInput();
    void update();
    void render(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;
    sf::FloatRect getBounds() const;
    void shoot();
    void updateProjectiles();
    void renderProjectiles(sf::RenderWindow& window);
    const std::vector<Projectile>& getProjectiles() const;
};

#endif // PLAYER_HPP
