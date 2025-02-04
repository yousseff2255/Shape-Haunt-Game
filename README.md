# Shape Haunt

**Shape Haunt** is a C++ game where the player's mission is to guess and cover randomly generated complex shapes using a set of basic shapes. The game leverages Object-Oriented Programming (OOP) principles to ensure modularity, extensibility, and maintainability.

---



## Game Overview

The game generates random complex shapes on the screen, and the player is provided with a set of basic shapes. The goal is to place these basic shapes to completely cover the complex shape. The game challenges the player's spatial reasoning and problem-solving skills.

---

## Features

- **Random Shape Generation**: The game generates complex shapes dynamically, ensuring a unique experience every time.
- **Basic Shape Toolkit**: Players are given a set of basic shapes to use as tools for covering the complex shape.
- **OOP Design**: The game is built using Object-Oriented Programming principles, providing the following benefits:
  - **Modularity**: Code is organized into reusable and independent modules (classes), making it easy to maintain and update.
  - **Extensibility**: New shapes or features can be added without modifying existing code, thanks to inheritance and polymorphism.
  - **Encapsulation**: Data and behavior are encapsulated within classes, ensuring secure and controlled access.
  - **Abstraction**: Complex logic is hidden behind simple interfaces, making the code easier to understand and use.
- **Interactive Gameplay**: Players can drag, rotate, and resize basic shapes to fit them onto the complex shape.
- **Score System**: Players are scored based on how efficiently and fast they cover the complex shape.

---

## How to Play

1. Launch the game.
2. You will have the choice to play a timed game or not
3. Choose a level
4. A random complex shape will appear on the screen.
5. Use the provided basic shapes to cover the complex shape.
6. Drag, rotate, and resize the basic shapes to fit them onto the complex shape.
7. Once you match correctly , your score will increase and the shape will disappear leaving you with the rest of the complex shape
   (If you successfully match a shape within the first few seconds, a special object will appear and move randomly across the screen. If you manage to click on it, you’ll earn double points for your match!)

---

## Installation

To run the game, follow these steps:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yousseff2255/Shape-Haunt-Game.git
   ```
2. **Navigate to the Project Directory**:
   ```bash
   cd Shape-Haunt-Game
   ```
3. **Compile the Code**:
   ```bash
   g++ -o Shape_Haunt main.cpp grid.cpp operations.cpp shape.cpp BasicShapes.cpp CompositeShapes.cpp FlipBasic.cpp game.cpp toolbar.cpp
   ```
4. **Run the Game**:
   ```bash
   ./shapeHaunt
   ```

---

## Dependencies

- **C++ Compiler**: Ensure you have a C++ compiler installed (e.g., `g++`).
- **Graphics Library**: The game uses CMU Graphics Library for rendering. Make sure the library is installed and linked properly.

---

## Code Structure

The project is organized into the following classes:

1. **Shape**: Base class for all shapes.
2. **ComplexShape**: Derived from `Shape`, represents the randomly generated complex shapes.
3. **BasicShape**: Derived from `Shape`, represents the basic shapes provided to the player.
4. **Game**: Manages the game logic, including shape generation, player input, and scoring.
5. **Toolbar**: Responsible for the toolbar
6. **Operation**: Manages all operations (e.g., Rotate , Flip ,..) 

---

## Contributing

Contributions are welcome! If you’d like to contribute to the project, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Commit your changes.
4. Submit a pull request.

---

## Contact

For questions or feedback, feel free to reach out:

- **Email**: yousseff2255@gmail.com

---

Enjoy playing **Shape Haunt**! 🎮
