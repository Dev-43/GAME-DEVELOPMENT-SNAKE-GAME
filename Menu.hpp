#pragma once
#include <SFML/Graphics.hpp>

class Menu {
public:
    bool showMenu(sf::RenderWindow& window) {
        while (window.isOpen()) {
            auto eventOpt = window.pollEvent();
            if (eventOpt.has_value()) {
                auto& event = eventOpt.value();
                if (event.is<sf::Event::Closed>()) window.close();

                if (auto key = event.getIf<sf::Event::KeyPressed>()) {
                    using Key = sf::Keyboard::Key;
                    if (key->code == Key::Enter)
                        return true;
                    else if (key->code == Key::Escape)
                        return false;
                }
            }

            window.clear(sf::Color::Black);
            window.display();
        }
        return false;
    }
};
