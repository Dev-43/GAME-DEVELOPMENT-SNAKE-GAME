#include <SFML/Graphics.hpp>
#include <ctime>
#include "Menu.hpp"
#include "Snake.hpp"
#include "Food.hpp"
#include "Game.hpp"

const unsigned WIDTH = 800;
const unsigned HEIGHT = 600;
const float GRID_SIZE = 20.f;

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Snake Game");
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(10);

    Menu menu;
    if (!menu.showMenu(window)) return 0;

    Snake snake(GRID_SIZE);
    Food food(GRID_SIZE, WIDTH, HEIGHT);
    Game game;
    sf::Clock gameClock;
    int foodEaten = 0;

    while (window.isOpen()) {
        auto eventOpt = window.pollEvent();
        if (eventOpt.has_value()) {
            const sf::Event& event = eventOpt.value();
            if (event.is<sf::Event::Closed>()) window.close();

            if (auto key = event.getIf<sf::Event::KeyPressed>()) {
                using Key = sf::Keyboard::Key;
                switch (key->code) {
                    case Key::Up:    snake.direction = {0.f, -GRID_SIZE}; break;
                    case Key::Down:  snake.direction = {0.f, GRID_SIZE}; break;
                    case Key::Left:  snake.direction = {-GRID_SIZE, 0.f}; break;
                    case Key::Right: snake.direction = {GRID_SIZE, 0.f}; break;
                    default: break;
                }
            }
        }

        snake.move();
        snake.wrap(WIDTH, HEIGHT);

        if (snake.body[0].getGlobalBounds().contains(food.food.getPosition())) {
            snake.grow();
            food.spawn(WIDTH, HEIGHT);
            game.updateScore(10);
            foodEaten++;
            if (foodEaten % 5 == 0)
                food.spawnBonus(WIDTH, HEIGHT);
        }

        if (food.bonusActive) {
            if (snake.body[0].getGlobalBounds().contains(food.bonus.getPosition())) {
                snake.grow();
                game.updateScore(20);
                food.disableBonus();
            } else if (food.bonusTimer.getElapsedTime().asSeconds() > 5.f) {
                food.disableBonus();
            }
        }

        if (snake.checkSelfCollision()) {
            game.gameOver(window);
        }

        game.updateTimer(gameClock.getElapsedTime().asSeconds());

        window.clear();
        window.draw(food.food);
        if (food.bonusActive) window.draw(food.bonus);
        for (auto& segment : snake.body)
            window.draw(segment);
        game.draw(window);
        window.display();
    }

    return 0;
}
