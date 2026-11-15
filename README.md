
🧩 Sudoku Game in C++



📌 About the Project

Sudoku Game in C++ is an interactive, console-based Sudoku application developed using C++17 and Object-Oriented Programming (OOP).

The project generates randomized Sudoku puzzles, provides multiple difficulty levels, validates player moves and tracks game performance.

It also includes helpful features such as hints, automatic mistake correction, score tracking, a timer and save/load functionality.

The main objective of this project is to demonstrate the practical application of OOP concepts, recursion, backtracking and problem-solving techniques.

---

✨ Key Features

Feature| Description
🎲 Random Puzzle Generation| Generates new Sudoku puzzles using backtracking.
🟢 Easy Mode| Suitable for beginners.
🟡 Medium Mode| Provides a moderate challenge.
🔴 Hard Mode| Designed for experienced players.
✅ Move Validation| Checks whether entered numbers follow Sudoku rules.
💡 Hint System| Provides the correct answer for an empty cell.
🔧 AutoFix System| Corrects incorrect entries automatically.
⏱️ Game Timer| Tracks the time taken to complete the puzzle.
🏆 Score System| Tracks player performance and scores.
💾 Save & Load| Allows players to save and resume their games.
⚠️ Error Handling| Handles invalid inputs without crashing the application.

---

🎮 Difficulty Levels

The game provides three difficulty levels:

Level| Numbers Removed| Initial Clues
🟢 Easy| 30| 51
🟡 Medium| 40| 41
🔴 Hard| 55| 26

Players can choose their preferred difficulty before starting a game.

---

🏗️ Project Architecture

The project is organized into three main classes.

1. Player Class

Responsible for managing player information and performance.

- Maintains the player's score.
- Tracks the number of mistakes.
- Records elapsed time.
- Restores saved player information.

2. SudokuBoard Class

Responsible for managing the Sudoku puzzle.

- Creates and displays the Sudoku grid.
- Generates valid Sudoku solutions.
- Validates rows, columns and 3×3 subgrids.
- Provides hints and automatic corrections.
- Handles saving and loading game data.

3. SudokuGame Class

Controls the overall game execution.

- Starts the game.
- Handles difficulty selection.
- Accepts player input.
- Controls the gameplay loop.
- Checks whether the puzzle is completed.

---

🧠 Object-Oriented Programming Concepts

This project uses class-based object-oriented design to organize the game functionality.

OOP Concept| Application
Encapsulation| Groups player and board data with their related methods.
Abstraction| Separates game operations into classes with clear responsibilities.
Inheritance| Document the actual parent-child class relationships here, if implemented.
Polymorphism| Document actual method overriding or overloading here, if implemented.

Note: Inheritance and polymorphism should only be described as implemented features if they are present in the source code.

---

⚙️ Algorithm Used

Backtracking Algorithm

Backtracking is a recursive problem-solving technique used to generate a valid Sudoku solution.

How it works:

1. Start with an empty Sudoku grid.
2. Select an empty cell.
3. Try numbers from 1 to 9.
4. Check whether the number is valid in its row, column and 3×3 subgrid.
5. If valid, place the number and move to the next cell.
6. If no number works, return to the previous cell and try another number.
7. Continue until the entire grid is completed.

Algorithm flow:

       Start
         |
   Find Empty Cell
         |
   Try Numbers 1-9
         |
    Is Number Safe?
       /       \
     Yes        No
      |          |
 Place Number   Try Next
      |
 Recursive Call
      |
  Grid Completed?
    /       \
  Yes        No
   |          |
 Return     Backtrack
 Solution      |
              Try Again

The algorithm ensures that the generated Sudoku solution follows the standard Sudoku rules.

---

🛠️ Technologies Used

- Programming Language: C++17
- Programming Paradigm: Object-Oriented Programming
- Algorithm: Recursive Backtracking
- Libraries: STL, iostream, vector, algorithm, random and file handling libraries
- Development Environment: Any C++17-compatible compiler

---

📂 Project Structure

Sudoku-Game-cpp/
│
├── include/
│   └── Header files (.h)
│
├── src/
│   └── Implementation files (.cpp)
│
├── main.cpp
│
└── README.md

Refer to the actual repository for the complete list of source and header filenames.

---

🚀 Installation and Execution

Prerequisites

- C++ compiler supporting C++17.
- GCC, MinGW or another compatible compiler.
- Terminal or command prompt.

Step 1: Clone the Repository

git clone https://github.com/shaheedmastanshaik-byte/Sudoku-Game-cpp.git

Step 2: Navigate to the Project

cd Sudoku-Game-cpp

Step 3: Compile the Project

g++ -std=c++17 -Iinclude main.cpp src/*.cpp -o sudoku

Step 4: Run the Game

Windows:

sudoku.exe

Linux / macOS:

./sudoku

Adjust the compilation command if your actual source filenames or folder arrangement differ.

---

🖥️ Sample Gameplay

<p align="center">
  <b>Sudoku Game Interface</b>
</p><!-- Add your actual game screenshots here --><p align="center">
  <i>Screenshot 1: Main Menu</i>
  <br/>
  <i>Screenshot 2: Sudoku Gameplay</i>
  <br/>
  <i>Screenshot 3: Game Completion</i>
</p>---

🔮 Future Improvements

Some possible improvements for future versions:

- Develop a graphical user interface (GUI).
- Add more Sudoku difficulty levels.
- Introduce a leaderboard system.
- Add sound effects and animations.
- Improve puzzle uniqueness validation.
- Add more customization options.
- Implement additional testing for puzzle generation and saving.

---

👥 Team Members

This project was developed collaboratively by:

S.No.| Team Member
1| Shaheed Mastan Shaik
2| M. Jeevan Kumar
3| V. Manoj Kumar
4| M. Sahith

---

🎯 Project Objective

The primary objective of this project is to apply programming concepts to develop an interactive Sudoku game while gaining practical experience in:

- Object-Oriented Programming.
- Recursion and Backtracking.
- Problem-Solving Techniques.
- Data Validation.
- File Handling.
- Team Collaboration.

---

❤️ Acknowledgements

We would like to thank our faculty and everyone who supported us during the development of this project.

This project helped us strengthen our C++ programming knowledge and understand how theoretical programming concepts can be applied to real-world applications.

---

<p align="center">
  <b>⭐ If you like this project, consider giving it a star!</b>
  <br/><br/>
  <b>Made with ❤️ using C++</b>
  <br/>
  <i>Think Smart. Solve Smart. Play Sudoku!</i>
</p>




