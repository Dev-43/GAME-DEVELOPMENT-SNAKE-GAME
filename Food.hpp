#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <cstdlib>

class Food {
public:
    sf::RectangleShape food;
    sf::RectangleShape bonus;
    bool bonusActive = false;
    float gridSize;
    sf::Clock bonusTimer;

    Food(float gridSize, unsigned width, unsigned height) : gridSize(gridSize) {
        food.setSize({gridSize, gridSize});
        food.setFillColor(sf::Color::Red);
        spawn(width, height);

        bonus.setSize({gridSize, gridSize});
        bonus.setFillColor(sf::Color::Yellow);
    }

    void spawn(unsigned width, unsigned height) {
        int gx = std::rand() % (width / static_cast<int>(gridSize));
        int gy = std::rand() % (height / static_cast<int>(gridSize));
        food.setPosition({gx * gridSize, gy * gridSize});
    }

    void spawnBonus(unsigned width, unsigned height) {
        int gx = std::rand() % (width / static_cast<int>(gridSize));
        int gy = std::rand() % (height / static_cast<int>(gridSize));
        bonus.setPosition({gx * gridSize, gy * gridSize});
        bonusActive = true;
        bonusTimer.restart();
    }

    void disableBonus() {
        bonusActive = false;
    }
};
