#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Snake {
public:
    std::vector<sf::RectangleShape> body;
    sf::Vector2f direction;
    float gridSize;

    Snake(float gridSize) : gridSize(gridSize), direction(gridSize, 0.f) {
        sf::RectangleShape head({gridSize, gridSize});
        head.setFillColor(sf::Color::Green);
        head.setPosition({400.f, 300.f});
        body.push_back(head);
    }

    void move() {
        for (std::size_t i = body.size() - 1; i > 0; --i)
            body[i].setPosition(body[i - 1].getPosition());
        body[0].move(direction);
    }

    void grow() {
        sf::RectangleShape segment({gridSize, gridSize});
        segment.setFillColor(sf::Color::Green);
        segment.setPosition(body.back().getPosition());
        body.push_back(segment);
    }

    void wrap(unsigned width, unsigned height) {
        sf::Vector2f pos = body[0].getPosition();
        if (pos.x < 0) pos.x = width - gridSize;
        else if (pos.x >= width) pos.x = 0;
        if (pos.y < 0) pos.y = height - gridSize;
        else if (pos.y >= height) pos.y = 0;
        body[0].setPosition(pos);
    }

    bool checkSelfCollision() const {
        for (std::size_t i = 1; i < body.size(); ++i)
            if (body[0].getGlobalBounds().contains(body[i].getPosition()))
                return true;
        return false;
    }
};
