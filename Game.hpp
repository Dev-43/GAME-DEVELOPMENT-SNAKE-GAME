#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
class Game {
public:
    int score;
    sf::Font font;
    sf::Text scoreText;
    sf::Text timerText;

    Game() : score(0), 
             scoreText(font, "Score: 0", 20), 
             timerText(font, "Time: 0s", 20) {
        
        if (!font.openFromFile("assets/OpenSans-Regular.ttf")) {
            std::cerr << "⚠️ Font failed to load!\n";
        }

        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition({10.f, 10.f});

        timerText.setFillColor(sf::Color::Cyan);
        timerText.setPosition({650.f, 10.f});
    }

    void updateScore(int value) {
        score += value;
        scoreText.setString("Score: " + std::to_string(score));
    }

    void updateTimer(float seconds) {
        timerText.setString("Time: " + std::to_string(static_cast<int>(seconds)) + "s");
    }

    void draw(sf::RenderWindow& window) {
        window.draw(scoreText);
        window.draw(timerText);
    }

    void gameOver(sf::RenderWindow& window) {
        window.close();
        std::cout << "\n💀 GAME OVER 💀\nFinal Score: " << score << "\n";
    }
};
