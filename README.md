# Alien Invasion

Our approach to the classic retro game Space Invaders.

Introduction
Alien Invasion is a thrilling and challenging arcade game where players control a spaceship to fend off waves of invading aliens. Featuring modern mechanics, dynamic animations, and immersive soundtracks, this project is designed to demonstrate C++ programming principles and game development practices.

Features
Player Control: Move the spaceship using arrow keys and fire projectiles with the spacebar.
Dynamic Aliens: Aliens of various types (Blue, Yellow, Green, and UFO) with distinct behaviors.
Health System: Lose health when aliens reach the bottom or collide with the player.
Scoring System: Earn points for each alien destroyed. Compete to beat the highest score!
Skins: Choose from a variety of custom spaceship designs by renowned designer Pietro Rodrigano.
Music and Sounds: Featuring an exclusive soundtrack collaboration with 50 Cent and immersive in-game sound effects.
Difficulty Scaling: More aliens spawn as the score increases.
Leaderboard: Store the and sort the higherscores.

Installation
Prerequisites
SFML Library: Install via Homebrew (macOS) or your package manager.
bash
Copy code
brew install sfml


Here’s a structured README.md file for your project:

Alien Invasion
A modern take on the classic Space Invaders game, built with C++ and SFML.

Table of Contents
Introduction
Features
Installation
How to Play
File Structure
Design Choices
Contributors
Introduction
Alien Invasion is a thrilling and challenging arcade game where players control a spaceship to fend off waves of invading aliens. Featuring modern mechanics, dynamic animations, and immersive soundtracks, this project is designed to demonstrate C++ programming principles and game development practices.

Features
Player Control: Move the spaceship using arrow keys and fire projectiles with the spacebar.
Dynamic Aliens: Aliens of various types (Blue, Yellow, Green, and UFO) with distinct behaviors.
Health System: Lose health when aliens reach the bottom or collide with the player.
Scoring System: Earn points for each alien destroyed. Compete to beat the highest score!
Skins: Choose from a variety of custom spaceship designs.
Music and Sounds: Featuring an exclusive soundtrack collaboration with 50 Cent and immersive in-game sound effects.
Difficulty Scaling: More aliens spawn as the score increases.
Installation
Prerequisites
SFML Library: Install via Homebrew (macOS) or your package manager.
bash
Copy code
brew install sfml
Compilation
Use the following command to compile the project:

bash
Copy code
g++ -std=c++17 -o alien_invasion main.cpp Alien.cpp Player.cpp Projectile.cpp GameState.cpp \
-I/opt/homebrew/opt/sfml/include \
-L/opt/homebrew/opt/sfml/lib \
-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
Run the Game
Once compiled, run the executable:

bash
Copy code
./alien_invasion
How to Play
Objective: Destroy as many aliens as possible while avoiding collisions. Survive as long as you can to achieve the highest score!
Controls:
Arrow Keys: Move the spaceship left and right.
Spacebar: Fire projectiles.
Game Over: The game ends when your health reaches zero.
File Structure
src/
main.cpp: Entry point of the game, handling initialization, the game loop, and state transitions.
Alien.cpp: Implements alien behavior, including movement, animations, and interactions.
Player.cpp: Manages player controls, health system, and shooting mechanics.
Projectile.cpp: Handles projectile movement and collision detection.
GameState.cpp: Manages game state transitions (e.g., menu, gameplay, and game over).
include/
Alien.hpp: Declaration of the Alien class and its methods.
Player.hpp: Declaration of the Player class and its methods.
Projectile.hpp: Declaration of the Projectile class and its methods.
GameState.hpp: Enumeration of game states.
resources/
images/: Textures for aliens, players, and background.
sounds/: Background music and sound effects.
fonts/: Fonts used for in-game text.
Design Choices
Object-Oriented Design: Modular classes for Player, Alien, Projectile, and GameState for clean and maintainable code.
Dynamic Resource Management: Efficient loading of textures and sounds ensures scalability and memory optimization.
Update Methods: Centralized logic for real-time interactivity between game elements (Player, Alien, Projectile).
Scaling Difficulty: Alien spawn rate increases with the score, adding replay value and challenge.
Contributors
Andrei: CMake integration, report writing, and debugging.
Daniel: Core gameplay features, mechanics, and additional features.
Leonardo: Presentation, design, and code structure.
Peter: Documentation, GTests, and sound implementation.
Pietro: Custom skins, creative ideas, and presentation.
Acknowledgments
SFML Library: For providing an excellent framework for 2D graphics, audio, and input handling.
50 Cent: For contributing a custom soundtrack to enhance the player experience.
License
This project is licensed under the MIT License. See the LICENSE file for details.

