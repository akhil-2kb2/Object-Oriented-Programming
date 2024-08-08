#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

// Player class
class Player {
public:
    sf::RectangleShape shape;
    int experience;
    int level;

    Player() : experience(0), level(1) {
        shape.setSize(sf::Vector2f(50, 50));
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(100, 100);
    }

    void gainExperience(int points) {
        experience += points;
        if (experience >= level * 100) {
            level++;
            cout << "Level Up! Current Level: " << level << endl;
        }
    }
};

// Enemy class
class Enemy {
public:
    sf::RectangleShape shape;
    int health;

    Enemy(float x, float y) : health(50) {
        shape.setSize(sf::Vector2f(50, 50));
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(x, y);
    }

    bool isDefeated() {
        return health <= 0;
    }

    void takeDamage(int damage) {
        health -= damage;
        cout << "Enemy health: " << health << endl;
    }
};

// Game class
class Game {
private:
    sf::RenderWindow window;
    Player player;
    vector<Enemy> enemies;

public:
    Game() : window(sf::VideoMode(800, 600), "CodeQuest Adventure") {
        enemies.push_back(Enemy(400, 300));
    }

    void run() {
        while (window.isOpen()) {
            processEvents();
            update();
            render();
        }
    }

    void processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    void update() {
        // Player movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            player.shape.move(0, -5);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            player.shape.move(0, 5);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            player.shape.move(-5, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            player.shape.move(5, 0);

        // Check for boundaries
        if (player.shape.getPosition().x < 0) player.shape.setPosition(0, player.shape.getPosition().y);
        if (player.shape.getPosition().y < 0) player.shape.setPosition(player.shape.getPosition().x, 0);
        if (player.shape.getPosition().x > 750) player.shape.setPosition(750, player.shape.getPosition().y);
        if (player.shape.getPosition().y > 550) player.shape.setPosition(player.shape.getPosition().x, 550);

        // Example combat logic
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (!enemies.empty()) {
                enemies[0].takeDamage(10);
                if (enemies[0].isDefeated()) {
                    player.gainExperience(50);
                    enemies.erase(enemies.begin());
                }
            }
        }
    }

    void render() {
        window.clear();
        window.draw(player.shape);
        for (Enemy& enemy : enemies) {
            window.draw(enemy.shape);
        }
        window.display();
    }
};

// Main function
int main() {
    Game game;
    game.run();
    return 0;
}

