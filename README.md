# GAME-DEVELOPMENT-SNAKE-GAME

# 🐍 Snake Game — SFML 3 Edition  
> 🚧 Status: **Incomplete**

**INTERN**: Devesh Laxman Dolas  
**PROJECT TYPE**: Game Development  
**TECH**: C++ with SFML 3  
**MENTOR**: Neela Santosh  
**COMPANY**: CODTECH IT SOLUTIONS  
**DURATION**: 4 Weeks  

---

## 🎮 Game Overview

A grid-based Snake game developed using **C++ and SFML 3**. The player controls a growing snake that must eat food and bonus items to increase score while avoiding self-collision. The snake wraps around screen boundaries, and a score + timer is displayed onscreen.

---

## 📂 Project Structure

```plaintext
SnakeGame/
├── main.cpp               # Game loop, input handling, rendering
├── Game.hpp               # Score/timer logic and display
├── Snake.hpp              # Snake behavior and movement
├── Food.hpp               # Regular and bonus food handling
├── Menu.hpp               # Console-based game start menu
├── assets/
│   └── OpenSans-Regular.ttf    # Font used for score & time
```

---

## ✔️ Features Implemented

✅ Arrow key movement for snake  
✅ Self-collision detection for Game Over  
✅ Screen wrapping at window edges  
✅ Bonus food appears every 5 items  
✅ Bonus disappears after 5 seconds  
✅ Score and elapsed time rendered onscreen  
✅ Console-based menu (Enter to start, Esc to exit)  
✅ SFML 3-compliant font and rendering  

---

## 🛠️ Build Instructions

### Requirements

- SFML 3 (graphics, window, system modules)  
- C++17 or later  
- Working font (`OpenSans-Regular.ttf`) in `assets/` folder  

### Compile Command

```bash
g++ main.cpp -std=c++17 -IC:/SFML/include -LC:/SFML/lib \
    -lsfml-graphics -lsfml-window -lsfml-system -o SnakeGame.exe
```

---

## ⚠️ Known Issues & Remaining Errors

- ⚠ `sf::Text` requires 3 arguments in SFML 3 (`font`, `string`, `size`)  
- ⚠ `sf::Text(font(), ...)` is invalid — cannot pass temporary font object  
- ⚠ `sf::VideoMode(WIDTH, HEIGHT)` must now be `sf::VideoMode({WIDTH, HEIGHT})`  
- ⚠ Missing or invalid font file will prevent score/time from rendering  
- ⚠ Bonus food may cause visual overlap if placed behind snake unexpectedly  

---

## 🚧 Remaining Tasks (To-Do)

| Feature                                 | Status     |
|----------------------------------------|------------|
| Display "Game Over" onscreen           | ⬜ Pending  |
| Restart option after death             | ⬜ Planned  |
| Animate tail growth                    | ⬜ Pending  |
| Add sound effects (bite / game over)   | ⬜ Planned  |
| Replace console menu with graphical UI | ⬜ Planned  |
| Refactor logic into StateManager       | ⬜ Future   |

---

## 📌 Status

🚧 This project is **not yet complete**. While the core game loop is functional, visual polish and user experience improvements like restart flow and sound effects are pending. The project is ideal for internship submission, with room for creative extensions in the future.

---

## 🙌 Credits

Developed by **Devesh Dolas** during internship at **CODTECH IT SOLUTIONS**.  
Built using modular C++ classes and modern **SFML 3** rendering techniques.

---

## 📬 Contact

📧 Email: deveshdolas9@gmail.com  
🌐 Reach out for feedback, enhancements, or collaboration.
