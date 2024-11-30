#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
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
    void handleInput(float deltaTime);          // Fixed: Requires deltaTime
    void update();
    void updateProjectiles(float deltaTime);
    void render(sf::RenderWindow& window);
    void renderProjectiles(sf::RenderWindow& window);
    void shoot();

    sf::Vector2f getPosition() const;
    sf::FloatRect getBounds() const;
    std::vector<Projectile>& getProjectiles(); // Fixed: Const-qualified
    void removeProjectile(size_t index);
};

#endif // PLAYER_HPP
